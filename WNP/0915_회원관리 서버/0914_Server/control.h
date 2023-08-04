//control.h

#pragma once

//���� �������̽�---------------------------------------------------------
void con_Run();
//------------------------------------------------------------------------

//������ ���� �Լ� 
//�Ʒ� ������ ��� �Լ��� ���ŵ� ������ ����.
void con_RecvData(unsigned int handle, TCHAR* msg);

void con_InsertMember(unsigned int handle, INSERTMEMBER_PACK *pdata);
void con_LogIn(unsigned int handle, LOGIN_PACK *pdata);
void con_LogOut(unsigned int handle, LOGOUT_PACK *pdata);
void con_DeleteMember(unsigned int handle, DELETEMEMBER_PACK *pdata);

void con_PrintAll();

bool IdCheck(TCHAR* id);				//���̵� ���� ���� üũ 
int IsIdPwCheck(TCHAR* id, TCHAR* pw);	//���̵� �н����� ��ġ ���� üũ
int IsIdLoginCheck(TCHAR* id);			//�α��� ���� üũ