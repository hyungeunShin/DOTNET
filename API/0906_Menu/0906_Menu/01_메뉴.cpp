//01_메뉴
//윈도우에 메뉴를 부착
// - 메뉴의 클릭정보 획득(WM_COMMAND / LOWORD(wParam)
// - 메뉴 UI(체크or 활성화 여부)(WM_INITMENUPOPUP / 

//Context Menu

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>
#include "resource.h"

COLORREF color = RGB(255, 0, 0);

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))  //자식컨트롤의 ID / 메뉴의 선택ID 
	{
	//프로그램 종료(시작점 : WM_CLOSE)
	case ID_40001: SendMessage(hwnd, WM_CLOSE, 0, 0);  break;
	//색상
	case ID_40002: color = RGB(255, 0, 0); break;
	case ID_40003: color = RGB(0, 255, 0); break;
	case ID_40004: color = RGB(0, 0, 255); break;
//	case ID_40005:
	}
	InvalidateRect(hwnd, 0, FALSE);
	return 0;
}

LRESULT OnInitMenuPopUp(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU mainMenu = GetMenu(hwnd);

//	EnableMenuItem(mainMenu, ID_40002, color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED);
//	EnableMenuItem(mainMenu, ID_40003, color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
//	EnableMenuItem(mainMenu, ID_40004, color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

	CheckMenuItem(mainMenu, ID_40002, color == RGB(255, 0, 0) ? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(mainMenu, ID_40003, color == RGB(0, 255, 0) ? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(mainMenu, ID_40004, color == RGB(0, 0, 255) ? MF_CHECKED : MF_UNCHECKED);

	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	HBRUSH hbr = CreateSolidBrush(color);
	HBRUSH oldbr = (HBRUSH)SelectObject(hdc, hbr);

	Rectangle(hdc, 100, 100, 500, 500);

	DeleteObject(SelectObject(hdc, oldbr));

	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT OnContextMenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) }; //스크린좌표

	HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
		
	// 스크린 좌표...
	EnableMenuItem(hMenu, ID_40002, color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40003, color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40004, color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

	TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CONTEXTMENU:	return OnContextMenu(hwnd, wParam, lParam);
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
	case WM_INITMENUPOPUP:	return OnInitMenuPopUp(hwnd, wParam, lParam);
	case WM_COMMAND:		return OnCommand(hwnd, wParam, lParam);
	case WM_CREATE:
	{
		return 0;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	//윈도우 클래스 정의
	WNDCLASS	wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //펜, 브러쉬, 폰트
	wc.hCursor = LoadCursor(0, IDC_ARROW);//시스템
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;	 //미리 만들어서 제공되는 프로시저(윈도우 공통 기능)
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU2);		//메뉴 등록
	wc.style = 0;				//윈도우 스타일

	RegisterClass(&wc);

	HMENU hmenu = LoadMenu(hInst, MAKEINTRESOURCE(IDR_MENU1));
	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("0830"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, hmenu, hInst, 0);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//메시지 루프
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}