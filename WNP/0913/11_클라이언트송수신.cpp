//11_Ŭ���̾�Ʈ�ۼ���.cpp
//11_���� >> �������ϸ��� client����
//10_���� >> ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

void DisplayMessage()
{
    LPVOID pMsg; //void * pMsg;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | // ���� �޽��� ���� �޸𸮸� ���ο��� �Ҵ��϶�
        FORMAT_MESSAGE_FROM_SYSTEM, //�ü���� ���� ���� �޽����� �����´�
        NULL,
        WSAGetLastError(), //���� �ڵ�
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //���(������ ���� ���)
        (LPTSTR)&pMsg, // ���� �޽��� outparam
        0, NULL);

    printf("%s\n", (char*)pMsg);// ���� �޽��� ���

    LocalFree(pMsg); // ���� �޽��� ���� �޸� ��ȯ 
}


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
    ServerAddr.sin_addr.s_addr = inet_addr("211.230.98.246"); //�ڽſ��� ����!
    int retval = connect(Socket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
    {
        DisplayMessage();
        return -1;
    }

    printf("���� ����\n");

    char buf[100];

    while (1)
    {     
        printf(">> ");
        gets_s(buf, sizeof(buf));
        if (strcmp(buf, "exit") == 0)
            break;

        //2) send
        int rev = send(Socket, buf, strlen(buf) + 1, 0);      //<---------------
        printf("�۽� ���� : %dbyte, %s\n", rev, buf);

        //3) recv
        rev = recv(Socket, buf, sizeof(buf), 0);
        if (rev == SOCKET_ERROR || 0)
            break;
        else
            printf("���� ���� : %dbyte, %s\n", rev, buf);
    }

    //4) close
    closesocket(Socket);

    //------------------------------------------------------------
    //2. ����ó��
    WSACleanup();
    return 0;
}