//06_����.cpp
// socket() -> bind() -> listen()
// accept()
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

int main()
{
    //1. �ʱ�ȭ 
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("������ ���� �ʱ�ȭ ����!\n");
        return -1;
    }
    printf("������ ���� �ʱ�ȭ ����!\n");

    //2. socket() -> bind() -> listen()
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET)
        return -1;

    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
//  memset(&ServerAddr, 0, sizeof(ServerAddr));     //C Library
    ServerAddr.sin_family       = AF_INET;
    ServerAddr.sin_port         = htons(9000);
    ServerAddr.sin_addr.s_addr  = htonl(INADDR_ANY);      //(ULONG)0x00000000 (����)
    int retval = bind(listenSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
        return -1;

    retval = listen(listenSocket, SOMAXCONN); //0x7fffffff
    if (retval == SOCKET_ERROR)
        return -1;

    printf("��� ������ �ʱ�ȭ ���� �Ϸ�\n");

    //3. Ŭ���̾�Ʈ�� ���� ���
    SOCKADDR_IN ClientAddr = { 0 };
    int clinetaddrsize = sizeof(ClientAddr);        //<----------
    SOCKET ClientSocket = accept(listenSocket, (SOCKADDR*)&ClientAddr, &clinetaddrsize);
    if (ClientSocket == INVALID_SOCKET)
        return -1;

    printf("Ŭ���̾�Ʈ ���� ����\n");
    //4. �������� ���
    printf("Ŭ���̾�Ʈ ���� : %s:%d\n",
        inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

    //���ϸ� ������, �� �ּ�, ���� �ּ�...
    SOCKADDR_IN testsockaddr;
    int length1 = sizeof(testsockaddr);
    getsockname(ClientSocket, (SOCKADDR*)&testsockaddr, &length1);

    SOCKADDR_IN testpeersockaddr;
    int length2 = sizeof(testpeersockaddr);
    getpeername(ClientSocket, (SOCKADDR*)&testpeersockaddr, &length2);

    printf("��� ���� ���� : ���ּ� %s:%d\t�����ּ� %s:%d\n",
        inet_ntoa(testsockaddr.sin_addr), ntohs(testsockaddr.sin_port),
        inet_ntoa(testpeersockaddr.sin_addr), ntohs(testpeersockaddr.sin_port) );

    //2. ����ó��
    WSACleanup();
    return 0;
}