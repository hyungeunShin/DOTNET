//01_���μ��� ����.cpp

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"
#include <Windows.h>
#include <tchar.h>
#include "resource.h"

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if(LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(hDlg, IDCANCEL); 
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		PROCESS_INFORMATION pi;
		STARTUPINFO			si = { sizeof(si) };	

		//Ŀ�ΰ�ü Ȯ�� ���( 1) Ŀ�ΰ�ü�� �ڵ��� HANDLE,   2) ���ڿ� SECURITY_ATTRIBUTE,���ȼӼ� )
		TCHAR name[] = TEXT("calc.exe");
		GetDlgItemText(hDlg, IDC_EDIT1, name, _countof(name));	//notepad.exe , calc.exe

		//���� : ���μ��� ���� ��û�� �����ߴ�....(���μ��� ������ �Ϸ�Ǿ��ٰ� �ƴ�....)
		BOOL b = CreateProcess(NULL, name, 0, 0, 0, 0, 0, 0, &si, &pi);
		if (b) 
		{
			//���(��ٸ���) �Լ�
			// ������ �ñ�
			//1���� : �ش� ���μ����� ������ �Ϸ�Ǹ� ����
			//2���� : �ð�(INFINITE, ���Ѵ��)
			WaitForInputIdle(pi.hProcess, INFINITE);	

			//�ڵ��� �ݴ´�......
			//CloseHandle(pi.hProcess);
			//CloseHandle(pi.hThread);

			MessageBox(NULL, TEXT("���μ����� ������"), TEXT("�˸�"), MB_OK);

			//���μ��� ����
			TerminateProcess(pi.hProcess, 0);
		}

		return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		//���� ȣ�� ����.
	case WM_INITDIALOG:
	{
		return TRUE;
	}
	case WM_COMMAND:	return OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;	//�޽����� ó������ �ʾҴ�.-> �� ������ ��ȭ���� ó���ϴ� default���ν���
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance
		MAKEINTRESOURCE(IDD_DIALOG1), // ���̾�α� ����
		0, // �θ� ������
		DlgProc); // Proc..
	return 0;
}