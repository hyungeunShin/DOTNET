//account.h

#pragma once


typedef struct tagAccount
{
	TCHAR account[20];
	TCHAR name[20];
	int balance;
	SYSTEMTIME date;
}ACCOUNT;
