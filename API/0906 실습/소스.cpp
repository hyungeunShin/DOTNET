#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"
#include <Windows.h>
#include <tchar.h>
#include "resource.h"
#define ID_TIMER 65 

COLORREF color = RGB(255, 0, 0);
WORD pWidth = 1; 
TCHAR tch[50] = { _T("레드") };
TCHAR tch1[50] = { _T("두께 : 1 ") };
RECT rc = { 300, 100, 500, 500 };
TCHAR g_localtime[256];

BOOL OnPaint(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hDlg, &ps);

	HBRUSH hbr = CreateSolidBrush(color);
	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, hbr);
	
	HPEN hpen = CreatePen(0, pWidth, BLACK_PEN);
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);
	Rectangle(hdc,rc.left,rc.top,rc.right,rc.bottom);

	DeleteObject(SelectObject(hdc, oldbr));
	DeleteObject(SelectObject(hdc, oldpen));
	TextOut(hdc, 50, 140, TEXT("색상"), _tcslen(TEXT("색상")));
	TextOut(hdc, 50,200, TEXT("펜의 두께"), _tcslen(TEXT("펜의 두께")));

	SetDlgItemText(hDlg, IDC_EDIT1, tch);
	SetDlgItemText(hDlg, IDC_EDIT2, tch1);

	TextOut(hdc, 10, 10, g_localtime, _tcslen(g_localtime));
	EndPaint(hDlg, &ps);
	return FALSE;
}
LRESULT OnTimer(HWND hwnd, WPARAM wParam, LPARAM lParam)
{

	SYSTEMTIME st;

	
	GetLocalTime(&st);
	wsprintf(g_localtime, TEXT("%04d - %02d - %02d %02d: %02d : %02d "),
		st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

	InvalidateRect(hwnd, 0, TRUE);

	return FALSE;
}
BOOL OnInitMenuPopUp(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	HMENU mainMenu = GetMenu(hDlg);


	CheckMenuItem(mainMenu, ID_40002, color == RGB(255, 0, 0) ? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(mainMenu, ID_40003, color == RGB(0, 255, 0) ? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(mainMenu, ID_40004, color == RGB(0, 0, 255) ? MF_CHECKED : MF_UNCHECKED);

	CheckMenuItem(mainMenu, ID_40005, pWidth == 1 ? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(mainMenu, ID_40006, pWidth == 3 ? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(mainMenu, ID_40007, pWidth == 5 ? MF_CHECKED : MF_UNCHECKED);



	return FALSE;
}


BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_40001:  EndDialog(hDlg, IDCANCEL); return TRUE;
	case ID_40002:  color = RGB(255, 0, 0);	_tcscpy_s(tch, _countof(tch), TEXT("레드"));break;
	case ID_40003: color = RGB(0, 255, 0)	;_tcscpy_s(tch, _countof(tch), TEXT("그린"));	break;
	case ID_40004: color = RGB(0, 0, 255);_tcscpy_s(tch, _countof(tch), TEXT("블루"));	break;
	case ID_40005: pWidth = 1;_tcscpy_s(tch1, _countof(tch1), TEXT("두께 : 1 ")); 	break;
	case ID_40006: pWidth = 3; _tcscpy_s(tch1, _countof(tch1), TEXT("두께 : 3 "));break;
	case ID_40007: pWidth = 5;_tcscpy_s(tch1, _countof(tch1), TEXT("두께 : 5 ")); break;
	case IDCANCEL: KillTimer(hDlg, ID_TIMER); EndDialog(hDlg, IDCANCEL); return TRUE;
	}
	InvalidateRect(hDlg, 0, FALSE);
	return FALSE;
}

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam) {

	SetTimer(hDlg, ID_TIMER, 1000, NULL);
	SendMessage(hDlg, WM_TIMER, 1, NULL);

	return FALSE;
}
BOOL OnContextMenu(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	POINT pt;
		GetCursorPos(&pt);          // 현재 커서의 위치(스크린 좌표)
	ScreenToClient(hDlg, &pt); // 스크린 좌표를 클라이 언트 좌표로..
	POINT pt1 = { LOWORD(lParam), HIWORD(lParam) };
	HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));

	if (PtInRect(&rc, pt))
	{
		
		HMENU hSubMenu = GetSubMenu(hMenu, 1);
		
		
		EnableMenuItem(hMenu, ID_40002, color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED);
		EnableMenuItem(hMenu, ID_40003, color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
		EnableMenuItem(hMenu, ID_40004, color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

		TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt1.x, pt1.y, 0, hDlg, 0);

		
	}
	else
	{
		HMENU hSubMenu = GetSubMenu(hMenu, 0);
		TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt1.x, pt1.y, 0, hDlg, 0);

	}
	return TRUE;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	
	switch (msg)
	{
	case WM_COMMAND: return OnCommand(hDlg, wParam, lParam);
	case WM_PAINT:		 return OnPaint(hDlg, wParam, lParam);
	case WM_INITDIALOG: return OnInitDialog(hDlg, wParam, lParam);
	case WM_INITMENUPOPUP: return OnInitMenuPopUp(hDlg, wParam, lParam);
	case WM_CONTEXTMENU:	return OnContextMenu(hDlg, wParam, lParam);
	case WM_TIMER: return OnTimer(hDlg, wParam, lParam);
	}
	return FALSE;
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance
		MAKEINTRESOURCE(IDD_DIALOG1), // 다이얼로그 선택
		0, // 부모 윈도우
		DlgProc); // Proc..


	return 0;
}