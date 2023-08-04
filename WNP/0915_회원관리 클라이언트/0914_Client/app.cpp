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
		ch = _getch();	//문자를 입력받는 함수[입력문자가 화면에 출력안됨, 문자하나를 누르는 순간 입력 버퍼]
		switch (ch)
		{
		case '0': return;		//함수 종료!
		case '1': con_InsertMember();   break;
		case '2': con_LogIn();			break;
		case '3': con_LogOut();			break;
		case '4': con_DeleteMember();   break;
		default: printf("없는 메뉴 입니다.\n");  break;
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
	printf(" 가변형 패킷을 활용한 1대 다 통신 프로그램\n");
	printf(" 홍길동\n");
	printf(" 2021-09-15\n");
	printf("******************************************************\n");
	system("pause");
}

void menuprint()
{
	printf("******************************************************\n");
	printf(" [0] 프로그램 종료\n");
	printf(" [1] 회원가입(InsertMember)\n");
	printf(" [2] 로그인(LogIn)\n");
	printf(" [3] 로그아웃(LogOut)\n");
	printf(" [4] 회원탈퇴(DeleteMember)\n");
	printf("******************************************************\n");
}

void ending()
{	
	system("cls");
	printf("******************************************************\n");
	printf(" 프로그램을 종료합니다.\n");
	printf("******************************************************\n");
	system("pause");
}