//01_���� ���̺귯��
/*
1. ���� ���̺귯�� ����� ���� �ڵ�
   #include <WinSock2.h>
   #pragma comment(lib, "ws2_32.lib")

2. ���� ���̺귯�� �ʱ�ȭ, ���� �ڵ� 
*/
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


    //2. ����ó��
    WSACleanup();
	return 0;
}