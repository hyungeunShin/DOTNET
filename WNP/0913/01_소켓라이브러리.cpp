//01_소켓 라이브러리
/*
1. 소켓 라이브러리 사용을 위한 코드
   #include <WinSock2.h>
   #pragma comment(lib, "ws2_32.lib")

2. 소켓 라이브러리 초기화, 종료 코드 
*/
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


    //2. 종료처리
    WSACleanup();
	return 0;
}