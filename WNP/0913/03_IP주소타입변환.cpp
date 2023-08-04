//02_IP�ּ�Ÿ�Ժ�ȯ

#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include  <ws2tcpip.h>

int main()
{
    //1. �ʱ�ȭ 
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("������ ���� �ʱ�ȭ ����!\n");
        return -1;
    }
    printf("������ ���� �ʱ�ȭ ����!\n");

    //--------------------------------------------------------
    // ���ڿ� �ּ� ���
    char ipaddr[] = "230.200.12.5";
    printf("IP ���ڿ� �ּ� : %s\n", ipaddr);

    // ���ڿ� �ּҸ� 4byte ������ ��ȯ
    IN_ADDR address = { 0 };  
    inet_pton(AF_INET, ipaddr, &address);  //IPV4, IPV6 ȣȯ��
    int numaddr = address.s_addr;
    printf("IP ���ڿ� �ּ� = > ���� = 0x%08X\n", numaddr);

    // 4byte ������ ���ڿ� �ּҷ� ��ȯ
    char stringaddr[20];
    IN_ADDR in_addr;
    in_addr.s_addr = numaddr;    
    inet_ntop(AF_INET, &in_addr,  stringaddr, sizeof(stringaddr));
    printf("IP ���� => ���ڿ� �ּ� = %s\n", stringaddr);

    //--------------------------------------------------------

    //2. ����ó��
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
//S_un : �ɹ� 3��(1�ɹ� : S_un_b,  2�ɹ� : S_un_w,  3�ɹ� : ULONG S_addr)
//�뵵�� ��ȯ�� ���� �ϱ� ���� ���� ����ü.