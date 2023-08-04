//control.h

#pragma once

//실행 인터페이스---------------------------------------------------------
void con_Run();
//------------------------------------------------------------------------

//데이터 수신 함수 
//아래 나열된 기능 함수로 수신된 정보를 전달.
void con_RecvData(unsigned int handle, TCHAR* msg);

void con_InsertMember(unsigned int handle, INSERTMEMBER_PACK *pdata);
void con_LogIn(unsigned int handle, LOGIN_PACK *pdata);
void con_LogOut(unsigned int handle, LOGOUT_PACK *pdata);
void con_DeleteMember(unsigned int handle, DELETEMEMBER_PACK *pdata);

void con_PrintAll();

bool IdCheck(TCHAR* id);				//아이디 존재 여부 체크 
int IsIdPwCheck(TCHAR* id, TCHAR* pw);	//아이디 패스워드 일치 여부 체크
int IsIdLoginCheck(TCHAR* id);			//로그인 여부 체크