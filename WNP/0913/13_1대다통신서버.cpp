//13_1�����ż���.cpp
//12_�������� ������ ����
//11_Ŭ���̾�Ʈ �ۼ������� TEST 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <process.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <vector>
using namespace std;

//��� ����
//1. ���� : accept
//2. ���� : ��� thread �����
//3. ��� : recv ���� 
vector<SOCKET> g_socketlist;

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

unsigned int __stdcall WorkThread(void* p)
{
    SOCKET ClientSocket = (SOCKET)p;
    char buf[100];

    while (1)
    {
        //3) recv
        int rev = recv(ClientSocket, buf, sizeof(buf), 0);
        if (rev == SOCKET_ERROR)
        {
            printf("���Ͽ� ������ �߻�\n");
            break;
        }
        else if (rev == 0)
        {
            printf("������ closesocket() ȣ��\n");
            break;
        }
        else
        {
            printf("���� ���� : %dbyte, %s\n", rev, buf);
            //4) send - echo(�޾Ƹ�, ���� ������ �״�� ����)
            //rev = send(ClientSocket, buf, rev, 0);      //<---------------
            //1�� �����.
            for (int i = 0; i < (int)g_socketlist.size(); i++)
            {
                SOCKET s = g_socketlist[i];
                rev = send(s, buf, rev, 0);
            }
            printf("�۽� ���� : %dbyte, %s\n", rev, buf);
        }
    }

    //����-----------------------------------
    for (int i = 0; i < (int)g_socketlist.size(); i++)
    {
        SOCKET s = g_socketlist[i];
        if (s == ClientSocket)
        {
            g_socketlist.erase(g_socketlist.begin() + i);  //<----------
            break;
        }
    }

    //5) close
    closesocket(ClientSocket);

    return 0;
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

    //2. socket() -> bind() -> listen()
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET)
    {

        return -1;
    }

    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
//  memset(&ServerAddr, 0, sizeof(ServerAddr));     //C Library
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(9000);
    ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);      //(ULONG)0x00000000 (����)
    int retval = bind(listenSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
    {
        DisplayMessage();
        return -1;
    }

    retval = listen(listenSocket, SOMAXCONN); //0x7fffffff
    if (retval == SOCKET_ERROR)
        return -1;

    printf("��� ������ �ʱ�ȭ ���� �Ϸ�\n");

    while (1)
    {
        //1) Ŭ���̾�Ʈ�� ���� ���
        SOCKADDR_IN ClientAddr = { 0 };
        int clinetaddrsize = sizeof(ClientAddr);        //<----------
        SOCKET ClientSocket = accept(listenSocket, (SOCKADDR*)&ClientAddr, &clinetaddrsize);
        if (ClientSocket == INVALID_SOCKET)
            return -1;

        g_socketlist.push_back(ClientSocket);       //����-----------------------

        //2) Ŭ���̾�Ʈ ���� ���� ���
        printf("Ŭ���̾�Ʈ ���� : %s:%d\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

        //#include <process.h>
        CloseHandle((HANDLE)_beginthreadex(0, 0, WorkThread, (void*)ClientSocket, 0, 0));
    }

    //2. ����ó��
    WSACleanup();
    return 0;
}
