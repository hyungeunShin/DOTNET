//wbserver.cpp

#include <stdio.h>
#include <vector>
using namespace std;
#include "wbserver.h"
#include "packet.h"
#include "control.h"        //<-------------------------------------------

vector<SOCKET> g_socketlist;
SOCKET listenSocket;

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

int recvn(SOCKET s, char* buf, int len, int flags)
{
    int received;
    char* ptr = buf;
    int left = len;  //���� ����Ʈ ũ��

    while (left > 0) {
        received = recv(s, ptr, left, flags);
        if (received == SOCKET_ERROR)
            return SOCKET_ERROR;
        else if (received == 0)
            break;
        left -= received;  //����ũ�� -= ����ũ��
        ptr += received;   //���� ��ġ �̵�
    }

    return (len - left);
}

DWORD __stdcall WorkThread(void* p)
{
    SOCKET ClientSocket = (SOCKET)p;

    char buf[500];
    while (1)
    {
        //3) recv
        int rev = wbserver_RecvData(ClientSocket, buf, sizeof(buf));
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
            con_RecvData(ClientSocket, buf);
            /*for (int i = 0; i < (int)g_socketlist.size(); i++)
            {
                SOCKET s = g_socketlist[i];
                rev = wbserver_SendData(s, buf, rev);
            }
            printf("�۽� ���� : %dbyte, %s\n", rev, buf);*/
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

DWORD __stdcall ListenThread(void* p)
{
    while (1)
    {
        SOCKADDR_IN ClientAddr = { 0 };
        int clinetaddrsize = sizeof(ClientAddr);        //<----------
        SOCKET ClientSocket = accept(listenSocket, (SOCKADDR*)&ClientAddr, &clinetaddrsize);
        if (ClientSocket == INVALID_SOCKET)
            continue;   //<--

        g_socketlist.push_back(ClientSocket);       //����-----------------------

        //2) Ŭ���̾�Ʈ ���� ���� ���
        char stringaddr[20];
        inet_ntop(AF_INET, &ClientAddr.sin_addr, stringaddr, sizeof(stringaddr));
        printf("Ŭ���̾�Ʈ ���� : %s:%d\n", stringaddr, ntohs(ClientAddr.sin_port));

        HANDLE handle = CreateThread(0, 0, WorkThread, (void*)ClientSocket, 0, 0);
        if (handle != 0)
            CloseHandle(handle);
    }
}

bool wbserver_Init()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        return false;
    }
    return true;
}

void wbserver_Exit()
{
    WSACleanup();
}

bool wbserver_Start(int port)
{
    listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET)
    {
        return false;
    }

    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);      //(ULONG)0x00000000 (����)
    int retval = bind(listenSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
    {
        DisplayMessage();
        return false;
    }

    retval = listen(listenSocket, SOMAXCONN); //0x7fffffff
    if (retval == SOCKET_ERROR)
        return false;

    HANDLE handle = CreateThread(0, 0, ListenThread, (void*)listenSocket, 0, 0);
    if (handle != 0)
        CloseHandle(handle);

    return true;
}

void wbserver_DisConnect()
{
    closesocket(listenSocket);
}

int wbserver_SendData(SOCKET socket, const char* msg, int size)
{
    //1. ���(������ ũ��)
    int rev = send(socket, (const char*)&size, sizeof(int), 0);

    //2. �� ������ 
    rev = send(socket, msg, size, 0);

    return rev;
}

int wbserver_RecvData(SOCKET socket, char* msg, int size)
{
    //1. ��� ����
    int s;
    int rev = recvn(socket, (char*)&s, sizeof(int), 0);

    //2. �� ������
    rev = recvn(socket, msg, s, 0);
    return rev;
}