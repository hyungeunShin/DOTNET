//app.c

#include "std.h"

void app_init()
{
	logo();
	con_init();
}

void app_run()
{
	char ch;
	while (1)
	{
		system("cls");
		//con_printall();
		menuprint();
		ch = _getch();	//���ڸ� �Է¹޴� �Լ�[�Է¹��ڰ� ȭ�鿡 ��¾ȵ�, �����ϳ��� ������ ���� �Է� ����]
		switch (ch)
		{
		case '0': return;		//�Լ� ����!
		case '1': con_InsertMember();   break;
		case '2': con_LogIn();			break;
		case '3': con_LogOut();			break;
		case '4': con_DeleteMember();   break;
		default: printf("���� �޴� �Դϴ�.\n");  break;
		}
		Sleep(2000);
		system("pause");
	}
}

void app_exit()
{
	ending();
}

void logo()
{
	system("cls");		//#include <stdlib.h>
	printf("******************************************************\n");
	printf(" ������ ��Ŷ�� Ȱ���� 1�� �� ��� ���α׷�\n");
	printf(" ȫ�浿\n");
	printf(" 2021-09-15\n");
	printf("******************************************************\n");
	system("pause");
}

void menuprint()
{
	printf("******************************************************\n");
	printf(" [0] ���α׷� ����\n");
	printf(" [1] ȸ������(InsertMember)\n");
	printf(" [2] �α���(LogIn)\n");
	printf(" [3] �α׾ƿ�(LogOut)\n");
	printf(" [4] ȸ��Ż��(DeleteMember)\n");
	printf("******************************************************\n");
}

void ending()
{	
	system("cls");
	printf("******************************************************\n");
	printf(" ���α׷��� �����մϴ�.\n");
	printf("******************************************************\n");
	system("pause");
}