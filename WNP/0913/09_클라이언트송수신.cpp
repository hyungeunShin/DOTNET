//09_Ŭ���̾�Ʈ�ۼ���.cpp
//09_���� >> �������ϸ��� client����
//08_���� >> ����
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
    //------------------------------------------------------------
    SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket == INVALID_SOCKET)
        return -1;

    //�ּ� Ȯ��  cmd >> ipconfig��� (192.168.0.101)
    //1) connect
    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(9000);
    ServerAddr.sin_addr.s_addr = inet_addr("192.168.0.101"); //�ڽſ��� ����!
    int retval = connect(Socket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
        return -1;

    printf("���� ����\n");

    char buf[100];

    printf(">> ");
    gets_s(buf, sizeof(buf));

    //2) send
    int rev = send(Socket, buf, strlen(buf)+1, 0);      //<---------------
    printf("�۽� ���� : %dbyte, %s\n", rev, buf);

    //3) recv
    rev = recv(Socket, buf, sizeof(buf), 0);
    printf("���� ���� : %dbyte, %s\n", rev, buf);

    //4) close
    closesocket(Socket);
   
    //------------------------------------------------------------
    //2. ����ó��
    WSACleanup();
    return 0;
}