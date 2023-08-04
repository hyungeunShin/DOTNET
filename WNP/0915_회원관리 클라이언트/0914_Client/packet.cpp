//packet.cpp

#include <string.h>
#include "packet.h"

INSERTMEMBER_PACK pack_InsertMember(TCHAR* name, TCHAR* id, TCHAR* pw, int age)
{
	INSERTMEMBER_PACK pack;

	pack.flag = PACK_INSERTMEMBER;
	strcpy_s(pack.name, sizeof(pack.name), name);
	strcpy_s(pack.id, sizeof(pack.id), id);
	strcpy_s(pack.pw, sizeof(pack.pw), pw);
	pack.age = age;

	return pack;
}

LOGIN_PACK pack_LogIn(TCHAR* id, TCHAR* pw)
{
	LOGIN_PACK pack;

	pack.flag = PACK_LOGIN;
	strcpy_s(pack.id, sizeof(pack.id), id);
	strcpy_s(pack.pw, sizeof(pack.pw), pw);

	return pack;
}

LOGOUT_PACK pack_LogOut(TCHAR* id)
{
	LOGOUT_PACK pack;

	pack.flag = PACK_LOGOUT;
	strcpy_s(pack.id, sizeof(pack.id), id);

	return pack;
}

DELETEMEMBER_PACK pack_DeleteMember(TCHAR* id)
{
	DELETEMEMBER_PACK pack;

	pack.flag = PACK_DELETEMEMBER;
	strcpy_s(pack.id, sizeof(pack.id), id);

	return pack;
}