//control.h
#pragma once

/*
[기능 시작점]
*/

void con_init();
void con_printall();

void con_InsertMember();
void con_LogIn();
void con_LogOut();
void con_DeleteMember();

void con_RecvData(TCHAR* msg);
void InsertMember_Ack(bool ischeck, INSERTMEMBER_PACK* msg);
void LogIn_Ack(bool ischeck, INSERTMEMBER_PACK* msg);
void LogOut_Ack(bool ischeck, LOGOUT_PACK* msg);
void DeleteMember_Ack(bool ischeck, DELETEMEMBER_PACK* msg);