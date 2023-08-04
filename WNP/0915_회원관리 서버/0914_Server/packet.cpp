//packet.cpp
#include "std.h"

INSERTMEMBER_PACK pack_InsertMember(bool ischeck, TCHAR* name, TCHAR* id, TCHAR* pw, int age)
{
	INSERTMEMBER_PACK pack;

	if(ischeck)
		pack.flag = ACK_INSERTMEMBER_S;
	else
		pack.flag = ACK_INSERTMEMBER_F;
	strcpy_s(pack.name, sizeof(pack.name), name);
	strcpy_s(pack.id, sizeof(pack.id), id);
	strcpy_s(pack.pw, sizeof(pack.pw), pw);
	pack.age = age;

	return pack;
}

INSERTMEMBER_PACK pack_LogIn(bool ischeck, TCHAR* name, TCHAR* id, TCHAR* pw, int age)
{
	INSERTMEMBER_PACK pack;

	if (ischeck)
		pack.flag = ACK_LOGIN_S;
	else
		pack.flag = ACK_LOGIN_F;
	strcpy_s(pack.name, sizeof(pack.name), name);
	strcpy_s(pack.id, sizeof(pack.id), id);
	strcpy_s(pack.pw, sizeof(pack.pw), pw);
	pack.age = age;

	return pack;
}

LOGOUT_PACK pack_LogOut(bool ischeck, TCHAR* id)
{
	LOGOUT_PACK pack;

	if (ischeck)
		pack.flag = ACK_LOGOUT_S;
	else
		pack.flag = ACK_LOGOUT_F;
	strcpy_s(pack.id, sizeof(pack.id), id);

	return pack;
}

DELETEMEMBER_PACK pack_DeleteMember(bool ischeck, TCHAR* id)
{
	DELETEMEMBER_PACK pack;

	if (ischeck)
		pack.flag = ACK_DELETEMEMBER_S;
	else
		pack.flag = ACK_DELETEMEMBER_F;
	strcpy_s(pack.id, sizeof(pack.id), id);

	return pack;
}