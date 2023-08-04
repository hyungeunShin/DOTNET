//09_클라이언트송수신.cpp
//09_빌드 >> 실행파일명을 client변경
//08_빌드 >> 실행
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

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
    //1) connect
    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(9000);
    ServerAddr.sin_addr.s_addr = inet_addr("192.168.0.101"); //자신에게 전달!
    int retval = connect(Socket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
        return -1;

    printf("접속 성공\n");

    char buf[100];

    printf(">> ");
    gets_s(buf, sizeof(buf));

    //2) send
    int rev = send(Socket, buf, strlen(buf)+1, 0);      //<---------------
    printf("송신 정보 : %dbyte, %s\n", rev, buf);

    //3) recv
    rev = recv(Socket, buf, sizeof(buf), 0);
    printf("수신 정보 : %dbyte, %s\n", rev, buf);

    //4) close
    closesocket(Socket);
   
    //------------------------------------------------------------
    //2. 종료처리
    WSACleanup();
    return 0;
}