//06_서버.cpp
// socket() -> bind() -> listen()
// accept()
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

    //2. socket() -> bind() -> listen()
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET)
        return -1;

    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
//  memset(&ServerAddr, 0, sizeof(ServerAddr));     //C Library
    ServerAddr.sin_family       = AF_INET;
    ServerAddr.sin_port         = htons(9000);
    ServerAddr.sin_addr.s_addr  = htonl(INADDR_ANY);      //(ULONG)0x00000000 (정수)
    int retval = bind(listenSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
        return -1;

    retval = listen(listenSocket, SOMAXCONN); //0x7fffffff
    if (retval == SOCKET_ERROR)
        return -1;

    printf("대기 소켓의 초기화 과정 완료\n");

    //3. 클라이언트의 접속 대기
    SOCKADDR_IN ClientAddr = { 0 };
    int clinetaddrsize = sizeof(ClientAddr);        //<----------
    SOCKET ClientSocket = accept(listenSocket, (SOCKADDR*)&ClientAddr, &clinetaddrsize);
    if (ClientSocket == INVALID_SOCKET)
        return -1;

    printf("클라이언트 접속 성공\n");
    //4. 접속정보 출력
    printf("클라이언트 정보 : %s:%d\n",
        inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

    //소켓만 있으면, 내 주소, 상대방 주소...
    SOCKADDR_IN testsockaddr;
    int length1 = sizeof(testsockaddr);
    getsockname(ClientSocket, (SOCKADDR*)&testsockaddr, &length1);

    SOCKADDR_IN testpeersockaddr;
    int length2 = sizeof(testpeersockaddr);
    getpeername(ClientSocket, (SOCKADDR*)&testpeersockaddr, &length2);

    printf("통신 소켓 정보 : 내주소 %s:%d\t상대방주소 %s:%d\n",
        inet_ntoa(testsockaddr.sin_addr), ntohs(testsockaddr.sin_port),
        inet_ntoa(testpeersockaddr.sin_addr), ntohs(testpeersockaddr.sin_port) );

    //2. 종료처리
    WSACleanup();
    return 0;
}