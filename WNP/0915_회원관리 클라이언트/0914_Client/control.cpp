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
		printf("라이브러리 초기화 오류 발생\n");
		exit(0);
		return;
	}

	//서버 연결
	if (wbclient_Connect(SERVER_IP, SERVER_PORT) == false)
	{
		printf("서버 연결 실패\n");
		exit(0);
		return;
	}

	printf("서버 연결\n");
}

void con_printall()
{
}

void con_InsertMember()
{
	printf("[회원 가입]\n\n");

	TCHAR name[20], id[20], pw[20];
	int age;

	printf("이름 : ");			gets_s(name, sizeof(name));
	printf("아이디 : ");			gets_s(id, sizeof(id));
	printf("패스워드 : ");		gets_s(pw, sizeof(pw));
	printf("나이 : ");			scanf_s("%d", &age);
	char dummy = getchar();

	//----------- 네트웤 코드(패킷 생성 -> 전송) --------------------------------
	INSERTMEMBER_PACK pack = pack_InsertMember(name, id, pw, age);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));	
	printf("회원 가입 정보 전송(%dbyte)\n", retval);
}

void con_LogIn()
{
	printf("[로그인]\n\n");

	TCHAR id[20], pw[20];

	printf("아이디 : ");			gets_s(id, sizeof(id));
	printf("패스워드 : ");		gets_s(pw, sizeof(pw));

	//----------- 네트웤 코드(패킷 생성 -> 전송) --------------------------------
	LOGIN_PACK pack = pack_LogIn(id, pw);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
	printf("로그인 정보 전송(%dbyte)\n", retval);
}

void con_LogOut()
{
	printf("[로그아웃]\n\n");

	if (g_isLogin == false)
	{
		printf("로그인 상태가 아닙니다.\n");
		return;
	}

	//----------- 네트웤 코드(패킷 생성 -> 전송) --------------------------------
	LOGOUT_PACK pack = pack_LogOut(g_id);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
	printf("로그아웃 정보 전송(%dbyte)\n", retval);
}

void con_DeleteMember()
{
	printf("[회원탈퇴]\n\n");

	if (g_isLogin == false)
	{
		printf("로그인 상태가 아닙니다.\n");
		return;
	}

	//----------- 네트웤 코드(패킷 생성 -> 전송) --------------------------------
	DELETEMEMBER_PACK pack = pack_DeleteMember(g_id);

	int retval = wbclinet_SendData((const char*)&pack, sizeof(pack));
	printf("회원 탈퇴 정보 전송(%dbyte)\n", retval);
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
		printf("회원가입이 성공했습니다.\n");
	else
		printf("회원가입이 실패했습니다.\n");
}

//로그인 성공시 : 회원 ID, 이름, 나이를 전역 변수에 저장!, 로그인 상태 변경!
void LogIn_Ack(bool ischeck, INSERTMEMBER_PACK* msg)
{
	if (ischeck)
	{
		g_isLogin = true;
		strcpy_s(g_name, sizeof(g_name), msg->name);
		strcpy_s(g_id, sizeof(g_id), msg->id);
		g_age = msg->age;

		printf("%s님이 로그인 하셨습니다.\n", msg->name);
	}
	else
	{
		printf("로그인 실패했습니다.\n");
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

		printf("로그아웃 하셨습니다.\n");
	}
	else
	{
		printf("로그아웃이 실패했습니다.\n");
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

		printf("회원 탈퇴 하셨습니다.\n");
	}
	else
	{
		printf("회원탈퇴가 실패했습니다.\n");
	}
}