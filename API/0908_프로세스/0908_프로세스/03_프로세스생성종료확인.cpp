//03_프로세스 생성 종료 확인
/*
* 생성 : CreateProcess()
* 강제 종료 : TerminateProcess()
* 살/죽 상태 : GetExitCodeProcess()
* CloseHandle()
*/

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"
#include <Windows.h>
#include <tchar.h>
#include "resource.h"

HANDLE g_handle;

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(hDlg, IDCANCEL);
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		PROCESS_INFORMATION pi;
		STARTUPINFO			si = { sizeof(si) };

		TCHAR name[100];
		GetDlgItemText(hDlg, IDC_EDIT1, name, _countof(name));	//notepad.exe , calc.exe

		//프로세스 KO, (쓰레드 KO.)
		BOOL b = CreateProcess(NULL, name, 0, 0, 0, 0, 0, 0, &si, &pi);
		if (b)
		{
			g_handle = pi.hProcess;
			SetDlgItemInt(hDlg, IDC_EDIT2, (int)pi.dwProcessId, 0);
			SetDlgItemInt(hDlg, IDC_EDIT3, (int)pi.hProcess, 0);
		}

		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		int pid = GetDlgItemInt(hDlg, IDC_EDIT4, 0, 0);
		g_handle = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
		SetDlgItemInt(hDlg, IDC_EDIT2, (int)pid, 0);
		SetDlgItemInt(hDlg, IDC_EDIT3, (int)g_handle, 0);

		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON3)
	{
		//HANDLE handle = (HANDLE)GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
		TerminateProcess(g_handle, 10);
		//CloseHandle(g_handle);
	}
	else if (LOWORD(wParam) == IDC_BUTTON4)
	{
		TCHAR msg[20];
		DWORD exitcode;
		GetExitCodeProcess(g_handle, &exitcode);
		if (exitcode == STILL_ACTIVE)  //살아있다.
		{
			wsprintf(msg, TEXT("실행중 : %d\n"), exitcode);
		}
		else
		{
			wsprintf(msg, TEXT("종료됨 : %d\n"), exitcode);
			CloseHandle(g_handle);
		}
		SetDlgItemText(hDlg, IDC_EDIT5, msg);

		return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		return TRUE;
	}
	case WM_COMMAND:	return OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;	
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance
		MAKEINTRESOURCE(IDD_DIALOG2), // 다이얼로그 선택
		0, // 부모 윈도우
		DlgProc); // Proc..
	return 0;
}