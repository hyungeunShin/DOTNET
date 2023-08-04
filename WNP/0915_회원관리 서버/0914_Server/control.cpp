//control.cpp

#include "std.h"

#define SERVER_PORT 9000

vector<MEMBER> memberlist;

//파싱
void con_RecvData(unsigned int handle, TCHAR* msg)	//원본 TCHAR buf[500];
{
	int* flag = (int*)msg;
	switch (*flag)
	{
	case PACK_INSERTMEMBER: con_InsertMember(handle, (INSERTMEMBER_PACK*)msg);	break;
	case PACK_LOGIN:		con_LogIn(handle, (LOGIN_PACK*)msg);				break;
	case PACK_LOGOUT:		con_LogOut(handle, (LOGOUT_PACK*)msg);				break;
	case PACK_DELETEMEMBER: con_DeleteMember(handle, (DELETEMEMBER_PACK*)msg);	break;
	}
}

bool IdCheck(TCHAR* id)
{
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];
		if (strcmp(id, mem.id) == 0)
			return false;
	}
	return true;
}

void con_InsertMember(unsigned int handle, INSERTMEMBER_PACK* pdata)
{
	//클라이언트에서 보낸 정보 처리 
	MEMBER mem;
	strcpy_s(mem.name, sizeof(mem.name), pdata->name);
	strcpy_s(mem.id, sizeof(mem.id), pdata->id);
	strcpy_s(mem.pw, sizeof(mem.pw), pdata->pw);
	mem.age = pdata->age;
	mem.islogin = false;

	//예외처리(동일한 ID는 중복 가입 될 수 없다.)
	bool ischeck = IdCheck(pdata->id);  // 중복 id가 있으면 false 반환
	if (ischeck)
	{
		memberlist.push_back(mem);
		con_PrintAll();
		file_Save(memberlist);
	}
	//---------------------------------------------------------------------

	//결과를 클라이언트에게 전송(패킷 생성 -> 전송[개인 / 전체])
	INSERTMEMBER_PACK ack = pack_InsertMember(ischeck, mem.name, mem.id, mem.pw, mem.age);
	int retval = wbserver_SendData(handle, (const char*)&ack, sizeof(ack));
	printf("회원 가입 응답 정보 전송(%dbyte)\n", retval);
}

int IsIdPwCheck(TCHAR* id, TCHAR* pw)
{
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];
		if (strcmp(id, mem.id) == 0 && strcmp(pw, mem.pw) == 0)
		{		
			return i;
		}
	}
	return -1;
}

void con_LogIn(unsigned int handle, LOGIN_PACK* pdata)
{
	int idx = IsIdPwCheck(pdata->id, pdata->pw);

	INSERTMEMBER_PACK ack;
	if (idx == -1)	//실패
	{
		ack = pack_LogIn(false, (char*)"", pdata->id, pdata->pw, -1);
	}
	else			//성공
	{
		memberlist[idx].islogin = true;
		ack = pack_LogIn(true, memberlist[idx].name, pdata->id, pdata->pw, memberlist[idx].age);

		con_PrintAll(); //<------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------

	//결과를 클라이언트에게 전송(패킷 생성 -> 전송[개인 / 전체])
	int retval = wbserver_SendData(handle, (const char*)&ack, sizeof(ack));
	printf("로그인 응답 정보 전송(%dbyte)\n", retval);
}

int IsIdLoginCheck(TCHAR* id)
{
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];
		if (strcmp(id, mem.id) == 0 && mem.islogin == true)
		{
			return i;
		}
	}
	return -1;
}

void con_LogOut(unsigned int handle, LOGOUT_PACK* pdata)
{
	int idx = IsIdLoginCheck(pdata->id);

	LOGOUT_PACK ack;
	if (idx == -1)	//실패
	{
		ack = pack_LogOut(false, pdata->id);
	}
	else			//성공
	{
		memberlist[idx].islogin = false;
		ack = pack_LogOut(true, pdata->id);

		con_PrintAll(); //<------------------------------------------------------------------
	}
	//--------------------------------------------------------------------------------

	//결과를 클라이언트에게 전송(패킷 생성 -> 전송[개인 / 전체])
	int retval = wbserver_SendData(handle, (const char*)&ack, sizeof(ack));
	printf("로그인 응답 정보 전송(%dbyte)\n", retval);
}

void con_DeleteMember(unsigned int handle, DELETEMEMBER_PACK* pdata)
{
	int idx = IsIdLoginCheck(pdata->id);

	DELETEMEMBER_PACK ack;
	if (idx == -1)	//실패
	{
		ack = pack_DeleteMember(false, pdata->id);
	}
	else			//성공
	{
		memberlist.erase(memberlist.begin() + idx);
		ack = pack_DeleteMember(true, pdata->id);

		con_PrintAll(); //<------------------------------------------------------------------
		file_Save(memberlist);
	}
	//--------------------------------------------------------------------------------

	//결과를 클라이언트에게 전송(패킷 생성 -> 전송[개인 / 전체])
	int retval = wbserver_SendData(handle, (const char*)&ack, sizeof(ack));
	printf("로그인 응답 정보 전송(%dbyte)\n", retval);
}

void con_PrintAll()
{
	system("cls");
	printf("저장 개수 : %d\n", memberlist.size());
	printf("-------------------------------------------------------\n");	
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];
		printf("[%s] %s\t%s\t%s\t%d\n",
			(mem.islogin ? "O" : "X"), mem.name, mem.id, mem.pw, mem.age);
	}
}

//초기화
void con_Run()
{
	system("cls");

	if (wbserver_Init() == false)
	{
		printf("소켓 라이브러리 초기화 오류\n");
		exit(0);
		return;
	}

	if (wbserver_Start(SERVER_PORT) == false)
	{
		printf("서버 시작 오류\n");
		exit(0);
		return;
	}

	printf("서버 실행.......\n");
	fild_Load(memberlist);
	con_PrintAll();
}

