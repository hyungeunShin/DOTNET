//packet.h
//���ø����̼� �������� ����
//���� ũ�� ��Ŷ

#pragma once

#include <tchar.h>

//1. ��Ŷ Ÿ�� ����
//Ŭ���̾�Ʈ > ���� 
#define PACK_INSERTMEMBER	1
#define PACK_LOGIN			2
#define PACK_LOGOUT			3
#define PACK_DELETEMEMBER	4

//���� > Ŭ���̾�Ʈ
#define ACK_INSERTMEMBER_S  11   // Ŭ���̾�Ʈ���� ���� ������ �״�� ����
#define ACK_INSERTMEMBER_F	12   // Ŭ���̾�Ʈ���� ���� ������ �״�� ����
#define ACK_LOGIN_S	        13
#define ACK_LOGIN_F			14
#define ACK_LOGOUT_S		15
#define ACK_LOGOUT_F		16
#define ACK_DELETEMEMBER_S	17
#define ACK_DELETEMEMBER_F	18

struct INSERTMEMBER_PACK
{
    int flag;
    TCHAR name[20];
    TCHAR id[20];
    TCHAR pw[20];
    int age;
};

struct DELETEMEMBER_PACK
{
    int flag;
    TCHAR id[20];
};

struct LOGIN_PACK
{
    int flag;
    TCHAR id[20];
    TCHAR pw[20];
};

struct LOGOUT_PACK
{
    int flag;
    TCHAR id[20];
};

INSERTMEMBER_PACK pack_InsertMember(bool ischeck, TCHAR* name, TCHAR* id, TCHAR* pw, int age);
INSERTMEMBER_PACK pack_LogIn(bool ischeck, TCHAR* name, TCHAR* id, TCHAR* pw, int age);
LOGOUT_PACK pack_LogOut(bool ischeck, TCHAR* id);
DELETEMEMBER_PACK pack_DeleteMember(bool ischeck, TCHAR* id);