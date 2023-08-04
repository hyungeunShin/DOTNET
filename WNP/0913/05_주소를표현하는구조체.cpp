//05_주소를 표현하는 구조체

/*
sockaddr      : 표준 구조체 
sockaddr_in   : TCP/IP, UDP/IP에서 주소를 쉽게 할당하기 위해 제공되는 구조체.
*/
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
    //----------------------------------------------------------------------------
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);                        //반드시 H -> N 변환 전달!
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");      //문자열 IP --> 숫자형변형 전달!
    //-----------------------------------------------------------------------------
    // inet_addr : 문자열 --> 숫자변경  + 변경된 숫자는 반드시 H -> N 변환 
    // htonl()   : 변경된 숫자는 반드시 H -> N 변환 
    //2. 종료처리
    WSACleanup();
    return 0;
}
