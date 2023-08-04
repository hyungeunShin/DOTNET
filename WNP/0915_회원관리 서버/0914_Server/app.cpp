//app.cpp

#include "std.h"

void app_run()
{


	logo();
	con_Run();
}

void logo()
{
	system("cls");		//#include <stdlib.h>
	printf("******************************************************\n");
	printf(" 가변형 패킷을 활용한 1대 다 통신 프로그램(서버)\n");
	printf(" 홍길동\n");
	printf(" 2021-09-15\n");
	printf("******************************************************\n");
	system("pause");
}
