//�ҽ�.cpp
//Ŭ���̾�Ʈ �ڵ� TEST


#include <stdio.h>
#include "wbclient.h"
#include "packet.h"

#define SERVER_IP	"211.230.98.246"//"127.0.0.1" //"230.200.12.5"
#define SERVER_PORT 9000



int main()
{
	if (wbclient_Init() == false)
		return 0;

	//���� ����
	if (wbclient_Connect(SERVER_IP, SERVER_PORT) == false)
		return 0;

	printf("���� ����\n");

    char buf[100];
    while (1)
    {
        gets_s(buf, sizeof(buf));
        if (strcmp(buf, "exit") == 0)
            break;
		
		PACKET pack = pack_ShortMessag("��â��", buf);
        int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
    }

	wbclient_DisConnect();
	wbclient_Exit();
	return 0;
}


/*
int main()
{
	PACKET pack = { 1, "aaa", "bbb" };

	char* buf = (char*)&pack;
	//---------------------------------------

	PACKET* ppack = (PACKET*)buf;
	printf("%s, %s\n", ppack->name, ppack->msg);
}
*/