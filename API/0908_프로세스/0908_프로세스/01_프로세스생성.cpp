//01_프로세스 생성.cpp

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

		//커널객체 확인 방법( 1) 커널객체의 핸들은 HANDLE,   2) 인자에 SECURITY_ATTRIBUTE,보안속성 )
		TCHAR name[] = TEXT("calc.exe");
		GetDlgItemText(hDlg, IDC_EDIT1, name, _countof(name));	//notepad.exe , calc.exe

		//리턴 : 프로세스 생성 요청이 성공했다....(프로세스 생성이 완료되었다가 아님....)
		BOOL b = CreateProcess(NULL, name, 0, 0, 0, 0, 0, 0, &si, &pi);
		if (b) 
		{
			//대기(기다리는) 함수
			// 리턴의 시기
			//1인자 : 해당 프로세스가 생성이 완료되면 리턴
			//2인자 : 시간(INFINITE, 무한대기)
			WaitForInputIdle(pi.hProcess, INFINITE);	

			//핸들을 닫는다......
			//CloseHandle(pi.hProcess);
			//CloseHandle(pi.hThread);

			MessageBox(NULL, TEXT("프로세스가 생성됨"), TEXT("알림"), MB_OK);

			//프로세스 종료
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
		//최초 호출 시점.
	case WM_INITDIALOG:
	{
		return TRUE;
	}
	case WM_COMMAND:	return OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;	//메시지를 처리하지 않았다.-> 이 다음에 대화상자 처리하는 default프로시저
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance
		MAKEINTRESOURCE(IDD_DIALOG1), // 다이얼로그 선택
		0, // 부모 윈도우
		DlgProc); // Proc..
	return 0;
}