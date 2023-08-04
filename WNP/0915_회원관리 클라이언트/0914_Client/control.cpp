//control.c

#include "std.h"

#define SERVER_IP	"127.0.0.1"//"127.0.0.1" //"230.200.12.5"
#define SERVER_PORT 9000

bool g_isLogin;
TCHAR g_name[20], g_id[20];
int g_age;


void con_init()
{
	if (wbclient_Init() == false)
	{
		printf("���̺귯�� �ʱ�ȭ ���� �߻�\n");
		exit(0);
		return;
	}

	//���� ����
	if (wbclient_Connect(SERVER_IP, SERVER_PORT) == false)
	{
		printf("���� ���� ����\n");
		exit(0);
		return;
	}

	printf("���� ����\n");
}

void con_printall()
{
}

void con_InsertMember()
{
	printf("[ȸ�� ����]\n\n");

	TCHAR name[20], id[20], pw[20];
	int age;

	printf("�̸� : ");			gets_s(name, sizeof(name));
	printf("���̵� : ");			gets_s(id, sizeof(id));
	printf("�н����� : ");		gets_s(pw, sizeof(pw));
	printf("���� : ");			scanf_s("%d", &age);
	char dummy = getchar();

	//----------- ��Ʈ�p �ڵ�(��Ŷ ���� -> ����) --------------------------------
	INSERTMEMBER_PACK pack = pack_InsertMember(name, id, pw, age);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));	
	printf("ȸ�� ���� ���� ����(%dbyte)\n", retval);
}

void con_LogIn()
{
	printf("[�α���]\n\n");

	TCHAR id[20], pw[20];

	printf("���̵� : ");			gets_s(id, sizeof(id));
	printf("�н����� : ");		gets_s(pw, sizeof(pw));

	//----------- ��Ʈ�p �ڵ�(��Ŷ ���� -> ����) --------------------------------
	LOGIN_PACK pack = pack_LogIn(id, pw);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
	printf("�α��� ���� ����(%dbyte)\n", retval);
}

void con_LogOut()
{
	printf("[�α׾ƿ�]\n\n");

	if (g_isLogin == false)
	{
		printf("�α��� ���°� �ƴմϴ�.\n");
		return;
	}

	//----------- ��Ʈ�p �ڵ�(��Ŷ ���� -> ����) --------------------------------
	LOGOUT_PACK pack = pack_LogOut(g_id);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
	printf("�α׾ƿ� ���� ����(%dbyte)\n", retval);
}

void con_DeleteMember()
{
	printf("[ȸ��Ż��]\n\n");

	if (g_isLogin == false)
	{
		printf("�α��� ���°� �ƴմϴ�.\n");
		return;
	}

	//----------- ��Ʈ�p �ڵ�(��Ŷ ���� -> ����) --------------------------------
	DELETEMEMBER_PACK pack = pack_DeleteMember(g_id);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
	printf("ȸ�� Ż�� ���� ����(%dbyte)\n", retval);
}

//------------------------------------------------------------------------

void con_RecvData(TCHAR* msg)
{
	int* flag = (int*)msg;
	switch (*flag)
	{
	case ACK_INSERTMEMBER_S: InsertMember_Ack(true, (INSERTMEMBER_PACK*)msg);	break;
	case ACK_INSERTMEMBER_F: InsertMember_Ack(false, (INSERTMEMBER_PACK*)msg);	break;

	case ACK_LOGIN_S:		 LogIn_Ack(true, (INSERTMEMBER_PACK*)msg);			break;
	case ACK_LOGIN_F:		 LogIn_Ack(false, (INSERTMEMBER_PACK*)msg);			break;

	case ACK_LOGOUT_S:		 LogOut_Ack(true, (LOGOUT_PACK*)msg);				break;
	case ACK_LOGOUT_F:		 LogOut_Ack(false, (LOGOUT_PACK*)msg);				break;

	case ACK_DELETEMEMBER_S: DeleteMember_Ack(true, (DELETEMEMBER_PACK*)msg);	break;
	case ACK_DELETEMEMBER_F: DeleteMember_Ack(false, (DELETEMEMBER_PACK*)msg);	break;
	}
}

void InsertMember_Ack(bool ischeck, INSERTMEMBER_PACK* msg)
{
	if (ischeck)
		printf("ȸ�������� �����߽��ϴ�.\n");
	else
		printf("ȸ�������� �����߽��ϴ�.\n");
}

//�α��� ������ : ȸ�� ID, �̸�, ���̸� ���� ������ ����!, �α��� ���� ����!
void LogIn_Ack(bool ischeck, INSERTMEMBER_PACK* msg)
{
	if (ischeck)
	{
		g_isLogin = true;
		strcpy_s(g_name, sizeof(g_name), msg->name);
		strcpy_s(g_id, sizeof(g_id), msg->id);
		g_age = msg->age;

		printf("%s���� �α��� �ϼ̽��ϴ�.\n", msg->name);
	}
	else
	{
		printf("�α��� �����߽��ϴ�.\n");
	}
}

void LogOut_Ack(bool ischeck, LOGOUT_PACK* msg)
{
	if (ischeck)
	{
		g_isLogin = false;
		strcpy_s(g_name, sizeof(g_name), "");
		strcpy_s(g_id, sizeof(g_id), "");
		g_age = -1;

		printf("�α׾ƿ� �ϼ̽��ϴ�.\n");
	}
	else
	{
		printf("�α׾ƿ��� �����߽��ϴ�.\n");
	}
}

void DeleteMember_Ack(bool ischeck, DELETEMEMBER_PACK* msg)
{
	if (ischeck)
	{
		g_isLogin = false;
		strcpy_s(g_name, sizeof(g_name), "");
		strcpy_s(g_id, sizeof(g_id), "");
		g_age = -1;

		printf("ȸ�� Ż�� �ϼ̽��ϴ�.\n");
	}
	else
	{
		printf("ȸ��Ż�� �����߽��ϴ�.\n");
	}
}