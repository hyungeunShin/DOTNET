//wbclient.cpp

#include <stdio.h>
#include "wbclient.h"

SOCKET Socket;

bool wbclient_Init()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        return false;
    }
    return true;
}

void wbclient_Exit()
{   
    WSACleanup();
}

bool wbclient_Connect(const char* ip, int port)
{
    Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket == INVALID_SOCKET)
        return false;

    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &ServerAddr.sin_addr);   //#include  <ws2tcpip.h>
    int retval = connect(Socket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
    {
        DisplayMessage();
        return false;
    }

    HANDLE handle = CreateThread(0, 0, RecvThread, (void*)Socket, 0, 0);
    if (handle != 0)
        CloseHandle(handle);

    return true;
}

void wbclient_DisConnect()
{
    closesocket(Socket);
}

void DisplayMessage()
{
    LPVOID pMsg; //void * pMsg;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | // 오류 메시지 저장 메모리를 내부에서 할당하라
        FORMAT_MESSAGE_FROM_SYSTEM, //운영체제로 부터 오류 메시지를 가져온다
        NULL,
        WSAGetLastError(), //오류 코드
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //언어(제어판 설정 언어)
        (LPTSTR)&pMsg, // 오류 메시지 outparam
        0, NULL);

    printf("%s\n", (char*)pMsg);// 오류 메시지 출력

    LocalFree(pMsg); // 오류 메시지 저장 메모리 반환 
}

int recvn(SOCKET s, char* buf, int len, int flags)
{
    int received;
    char* ptr = buf;
    int left = len;  //남은 바이트 크기

    while (left > 0) {
        received = recv(s, ptr, left, flags);
        if (received == SOCKET_ERROR)
            return SOCKET_ERROR;
        else if (received == 0)
            break;
        left -= received;  //남은크기 -= 받은크기
        ptr += received;   //저장 위치 이동
    }

    return (len - left);
}

DWORD __stdcall RecvThread(void* p)
{
    SOCKET Socket = (SOCKET)p;
    char buf[100];

    while (1)
    {
        int rev = wbclient_RecvData(buf, 5);
        if (rev == SOCKET_ERROR || 0)
            break;
        else
            printf("[수신] %s\n", buf);
    }

    closesocket(Socket);
    return 0;
}

int wbclinet_SendData(const char* msg, int size)
{
    int rev = send(Socket, msg, size, 0);
    return rev;
}

int wbclient_RecvData(char* msg, int size)
{
    int rev = recvn(Socket, msg, size, 0);
    return rev;
}