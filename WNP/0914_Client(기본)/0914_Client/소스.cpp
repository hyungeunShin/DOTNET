//소스.cpp
//클라이언트 코드 TEST


#include <stdio.h>
#include "wbclient.h"

#define SERVER_IP	"127.0.0.1"//"127.0.0.1" //"230.200.12.5"
#define SERVER_PORT 9000

int main()
{
	if (wbclient_Init() == false)
		return 0;

	//서버 연결
	if (wbclient_Connect(SERVER_IP, SERVER_PORT) == false)
		return 0;

	printf("서버 연결\n");

    char buf[100];
    while (1)
    {
        gets_s(buf, sizeof(buf));
        if (strcmp(buf, "exit") == 0)
            break;

        int retval = wbclinet_SendData(buf, strlen(buf) + 1);   
    }

	wbclient_DisConnect();
	wbclient_Exit();
	return 0;
}