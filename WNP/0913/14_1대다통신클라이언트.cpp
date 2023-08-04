//14_1대다통신클라이언트.cpp
//1st : send
//2nd : recv , 호출시점은 접속 후...

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <process.h>

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

unsigned int __stdcall RecvThread(void* p)
{
    SOCKET Socket = (SOCKET)p;
    char buf[100];

    while (1)
    {
        int rev = recv(Socket, buf, sizeof(buf), 0);
        if (rev == SOCKET_ERROR || 0)
            break;
        else
            printf("[수신] %s\n", buf);
            //printf("수신 정보 : %dbyte, %s\n", rev, buf);
    }

    closesocket(Socket);
    return 0;
}

int main()
{
    //1. 초기화 
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("윈도우 소켓 초기화 실패!\n");
        return -1;
    }
    printf("윈도우 소켓 초기화 성공!\n");
    //------------------------------------------------------------
    SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (Socket == INVALID_SOCKET)
        return -1;

    //주소 확인  cmd >> ipconfig명령 (192.168.0.101)
    //1) connect 211.230.98.246
    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(9000);
    ServerAddr.sin_addr.s_addr = inet_addr("211.230.98.246");
    //ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //자신에게 전달!
    int retval = connect(Socket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
    {
        DisplayMessage();
        return -1;
    }

    printf("접속 성공\n");
    //#include <process.h>
    CloseHandle((HANDLE)_beginthreadex(0, 0, RecvThread, (void*)Socket, 0, 0));

    char buf[100];

    while (1)
    {
        //printf(">> ");
        gets_s(buf, sizeof(buf));
        if (strcmp(buf, "exit") == 0)
            break;

        //2) send
        int rev = send(Socket, buf, strlen(buf) + 1, 0);      //<---------------
        //printf("송신 정보 : %dbyte, %s\n", rev, buf);        
    }

    //4) close
    closesocket(Socket);

    //------------------------------------------------------------
    //2. 종료처리
    WSACleanup();
    return 0;
}