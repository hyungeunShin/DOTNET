//05_�ּҸ� ǥ���ϴ� ����ü

/*
sockaddr      : ǥ�� ����ü 
sockaddr_in   : TCP/IP, UDP/IP���� �ּҸ� ���� �Ҵ��ϱ� ���� �����Ǵ� ����ü.
*/
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
    //----------------------------------------------------------------------------
    SOCKADDR_IN addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);                        //�ݵ�� H -> N ��ȯ ����!
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");      //���ڿ� IP --> ���������� ����!
    //-----------------------------------------------------------------------------
    // inet_addr : ���ڿ� --> ���ں���  + ����� ���ڴ� �ݵ�� H -> N ��ȯ 
    // htonl()   : ����� ���ڴ� �ݵ�� H -> N ��ȯ 
    //2. ����ó��
    WSACleanup();
    return 0;
}
