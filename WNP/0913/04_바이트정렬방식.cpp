//04_����Ʈ���Ĺ��


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
    //----------------------------------------------------------------

    unsigned short us = 0x1234;         //2byte
    unsigned long ul  = 0x12345678;      //4byte

    // ȣ��Ʈ ����Ʈ�� ��Ʈ��ũ ����Ʈ�� ��ȯ�Ѵ�.
    printf("0x%08X = > 0x%08X\n", us, htons(us));
    printf("0x%08X = > 0x%08X\n", ul, htonl(ul));

    unsigned short n_us = htons(us);
    unsigned long n_ul = htonl(ul);
    // ��Ʈ��ũ ����Ʈ�� ȣ��Ʈ ����Ʈ�� ��ȯ�Ѵ�.
    printf("0x%08X = > 0x%08X\n", n_us, ntohs(n_us));
    printf("0x%08X = > 0x%08X\n", n_ul, ntohl(n_ul));

    //----------------------------------------------------------------
    //2. ����ó��
    WSACleanup();
    return 0;
}