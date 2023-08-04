//02_프로세스 열거.cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "psapi.h"		
/*
* 커널
* Create  : 커널객체를 생성하고 해당 커널의 핸들값을 반환받는 함수(해당 핸들값이 핸들테이블에 등록)
* Open    : 이미 생성된 커널의 핸들값을 반환받는 함수(해당 핸들값이 핸들테이블에 등록)
*/
void PrintProcessNameAndID(DWORD processID) 
{
	TCHAR szProcessName[MAX_PATH] = TEXT("unknown");

	// 프로세스의 핸들 얻기
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |PROCESS_VM_READ, FALSE, processID);
	// process 이름 가져오기
	if (NULL != hProcess) 
	{
		HMODULE hMod;
		DWORD	cbNeeded;
		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, szProcessName, _countof(szProcessName));
		}
		else
		{
			printf(".....\n");
			return;
		}
	}
	else
	{
		printf(".....\n");
		return;
	}
	//print
	_tprintf(TEXT("%s ( PROCESS ID : %u )\n"), szProcessName, processID);
	CloseHandle(hProcess);
}

int main()
{
	
	DWORD aProcess[1024], cbNeeded, cProcesses;

	// process list 가져오기(PID값)
	if (!EnumProcesses(aProcess, sizeof(aProcess), &cbNeeded))
		// 배열 수, 리턴되는 바이트 수 
		// 배열에 id값들이 들어간다.
		return 0;

	// 얼마나 많은 프로세스들이 리턴되었나 계산
	cProcesses = cbNeeded / sizeof(DWORD);

	printf("프로세스 개수 : %d\n", cProcesses);

	for (int i = 0; i < (int)cProcesses; i++)
	{
		printf("[%d] %d\t", i, aProcess[i]);
	}
	printf("\n");

	// process 이름 출력
	for (int i = 0; i < (int)cProcesses; i++)
		PrintProcessNameAndID(aProcess[i]);

	return 0;
}
