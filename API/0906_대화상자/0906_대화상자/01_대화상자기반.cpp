//01_대화상자기반.cpp
/*
* skeleton 코드가 변경됨.
* 1. 리소스로 대화상자를 생성
* 2. 1번에서 만든 대화상자의 메시지를 처리할 프로시저 구현(윈도우기반 프로시저와는 다르다..)
* 3. WinMain에서는 1번에서 만든 대화상자를 실행하는 함수 호출
*    - 해당함수는 대화상자가 종료되기 전까지 리턴을 안함
*/
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"
#include <Windows.h>
#include <tchar.h>
#include "resource.h"

//내가 직접 생성
#define IDC_EDIT11	1
HWND hEdit1;
HWND hEdit2; 

//리소스로 만든것은 ID만 resource.h 파일에 생성되어 있다.
//핸들은 필요하다면 얻어와야 한다. GetDlgItem

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hEdit1 = CreateWindow(
		TEXT("edit"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL,//수평
		20, 50, 200, 25, hDlg, (HMENU)IDC_EDIT11, hInst, 0);

	hEdit2 = GetDlgItem(hDlg, IDC_EDIT1); 

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if(LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(hDlg, IDCANCEL); 
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		TCHAR msg[100];
		GetDlgItemText(hDlg, IDC_EDIT11, msg, _countof(msg));
		SetDlgItemText(hDlg, IDC_EDIT1, msg);
	}
	return FALSE;		//<=====
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	//최초 호출 시점.
	case WM_INITDIALOG:		return OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return OnCommand(hDlg, wParam, lParam);
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