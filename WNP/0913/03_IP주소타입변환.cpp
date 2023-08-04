//02_IP주소타입변환

#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include  <ws2tcpip.h>

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

    //--------------------------------------------------------
    // 문자열 주소 출력
    char ipaddr[] = "230.200.12.5";
    printf("IP 문자열 주소 : %s\n", ipaddr);

    // 문자열 주소를 4byte 정수로 변환
    IN_ADDR address = { 0 };  
    inet_pton(AF_INET, ipaddr, &address);  //IPV4, IPV6 호환용
    int numaddr = address.s_addr;
    printf("IP 문자열 주소 = > 정수 = 0x%08X\n", numaddr);

    // 4byte 정수를 문자열 주소로 변환
    char stringaddr[20];
    IN_ADDR in_addr;
    in_addr.s_addr = numaddr;    
    inet_ntop(AF_INET, &in_addr,  stringaddr, sizeof(stringaddr));
    printf("IP 정수 => 문자열 주소 = %s\n", stringaddr);

    //--------------------------------------------------------

    //2. 종료처리
    WSACleanup();
    return 0;
}
/*
typedef struct in_addr
{
  union
  {
        struct
        {
          UCHAR s_b1;
          UCHAR s_b2;
          UCHAR s_b3;
          UCHAR s_b4;
        } S_un_b;

        struct
        {
          USHORT s_w1;
          USHORT s_w2;
        } S_un_w;

        ULONG S_addr;
  } S_un;
} IN_ADDR, *PIN_ADDR, *LPIN_ADDR;*
*/
//S_un : 맴버 3개(1맴버 : S_un_b,  2맴버 : S_un_w,  3맴버 : ULONG S_addr)
//용도는 변환을 쉽게 하기 위해 만든 공용체.