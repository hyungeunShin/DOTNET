//04_바이트정렬방식


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
    //----------------------------------------------------------------

    unsigned short us = 0x1234;         //2byte
    unsigned long ul  = 0x12345678;      //4byte

    // 호스트 바이트를 네트워크 바이트로 변환한다.
    printf("0x%08X = > 0x%08X\n", us, htons(us));
    printf("0x%08X = > 0x%08X\n", ul, htonl(ul));

    unsigned short n_us = htons(us);
    unsigned long n_ul = htonl(ul);
    // 네트워크 바이트를 호스트 바이트로 변환한다.
    printf("0x%08X = > 0x%08X\n", n_us, ntohs(n_us));
    printf("0x%08X = > 0x%08X\n", n_ul, ntohl(n_ul));

    //----------------------------------------------------------------
    //2. 종료처리
    WSACleanup();
    return 0;
}