//07_Ŭ���̾�Ʈ.cpp
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
    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(9000);
    ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //�ڽſ��� ����!
    int retval = connect(Socket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
        return -1;

    printf("���� ����\n");

    char dummy = getchar();
    //------------------------------------------------------------
    //2. ����ó��
    WSACleanup();
    return 0;
}