//02_���μ��� ����.cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include "psapi.h"		
/*
* Ŀ��
* Create  : Ŀ�ΰ�ü�� �����ϰ� �ش� Ŀ���� �ڵ鰪�� ��ȯ�޴� �Լ�(�ش� �ڵ鰪�� �ڵ����̺� ���)
* Open    : �̹� ������ Ŀ���� �ڵ鰪�� ��ȯ�޴� �Լ�(�ش� �ڵ鰪�� �ڵ����̺� ���)
*/
void PrintProcessNameAndID(DWORD processID) 
{
	TCHAR szProcessName[MAX_PATH] = TEXT("unknown");

	// ���μ����� �ڵ� ���
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION |PROCESS_VM_READ, FALSE, processID);
	// process �̸� ��������
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

	// process list ��������(PID��)
	if (!EnumProcesses(aProcess, sizeof(aProcess), &cbNeeded))
		// �迭 ��, ���ϵǴ� ����Ʈ �� 
		// �迭�� id������ ����.
		return 0;

	// �󸶳� ���� ���μ������� ���ϵǾ��� ���
	cProcesses = cbNeeded / sizeof(DWORD);

	printf("���μ��� ���� : %d\n", cProcesses);

	for (int i = 0; i < (int)cProcesses; i++)
	{
		printf("[%d] %d\t", i, aProcess[i]);
	}
	printf("\n");

	// process �̸� ���
	for (int i = 0; i < (int)cProcesses; i++)
		PrintProcessNameAndID(aProcess[i]);

	return 0;
}
