//16_클라이언트 recvn 추가.cpp

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

unsigned int __stdcall RecvThread(void* p)
{
    SOCKET Socket = (SOCKET)p;
    char buf[100];

    while (1)
    {
        int rev = recvn(Socket, buf, 5, 0);
        //int rev = recv(Socket, buf, sizeof(buf), 0);
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
    ServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
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