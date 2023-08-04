//02_IP�ּ�Ÿ�Ժ�ȯ
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

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
    int number = inet_addr(ipaddr); // 0x050CC8E6;
    printf("IP ���ڿ� �ּ� = > ���� = 0x%08X\n", number);
    
    // 4byte ������ ���ڿ� �ּҷ� ��ȯ
    IN_ADDR in_addr;
    in_addr.s_addr = number;
    printf("IP ���� => ���ڿ� �ּ� = %s\n", inet_ntoa(in_addr));

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

/*
typedef struct tagin_addr
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
        ULONG S_addr;
    } S_un;
} MYIN_ADDR;

int main()
{
    MYIN_ADDR  myaddr;
    printf("%dbyte\n", sizeof(myaddr));     //4byte
    printf("%p, %p\n", &myaddr.S_un.S_addr, &myaddr.S_un.S_un_b);
    myaddr.S_un.S_addr = 0x01020304;  //16���� ǥ���� �����Ѱ��� 4bit
    
    printf("%d.%d.%d.%d\n",
        myaddr.S_un.S_un_b.s_b1, myaddr.S_un.S_un_b.s_b2,
        myaddr.S_un.S_un_b.s_b3, myaddr.S_un.S_un_b.s_b4);

    return 0;
}
*/