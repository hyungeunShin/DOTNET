//소스.cpp
//서버 코드 TEST

#include <stdio.h>
#include "wbserver.h"

#define SERVER_PORT 9000

int main()
{
	if (wbserver_Init() == false)
		return 0;

	if (wbserver_Start(SERVER_PORT) == false)
		return 0;

	char dummy = getchar();

	wbserver_Exit();

	return 0;
}