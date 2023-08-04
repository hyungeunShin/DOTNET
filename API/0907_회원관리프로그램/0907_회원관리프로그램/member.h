//member.h

#pragma once

typedef struct tagMember
{
	int id;
	TCHAR name[20];
	TCHAR phone[20];
	SYSTEMTIME  date;
}MEMBER;
