//05_리소스_커서.cpp

//코드에서 리소스를 사용하려면 ID가 필요하다....resource.h

/*
* 1. 윈도우클래스에 내가 등록한 커서를 설정
*     LoadCursor(내 인스턴스,  MAKEINTRESOURCE(생성된커스ID));
* 
* 2. 동적으로 커서를 변경하는 방법(커서는 마우스와 관련 있는 도구)
*    WM_HITTEST ----------> WM_SETCURSOR  -----------------------> WSM_마우스메시지 
*    [HITTESTCODE획득]      [해당위치에따라 마우스커서모양변경]
*                           미리제공되는 SETCURSOR
*                           1)클라이언트 영역 : WClass에서 설정한 커서모양
*                           2)그 외의 영역 : 알아서 제공
*                           커서모양을 변경하는 함수 SetCursor
* 
*   내가 직접 WM_SETCURSOR를 필터링
*   원하는 위치에서 SetCursor함수를 호출
*   나머지 영역은 DefWindowProc으로 전달
*/
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>
#include "resource.h"			//<===========================

RECT g_rc = { 100,100, 300, 300 };
//마우스 LButtonClick할때 커서 모양을 변경...
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HCURSOR h1 = LoadCursorFromFile(TEXT("C:\\windows\\cursors\\person_il.cur"));
	SetCursor(h1);
	return 0;
}

LRESULT OnSetCursor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int code = LOWORD(lParam); // hit test code가 들어 있다.
	
	POINT pt;
	GetCursorPos(&pt); // 현재 커서의 위치(스크린 좌표)
	ScreenToClient(hwnd, &pt); // 스크린 좌표를 클라이 언트 좌표로..
	
	// 클라이언트 안에서도 특정위치에서는 다른 커서를 사용하는 방법.
	if (code == HTCLIENT && PtInRect(&g_rc, pt))
	{
		SetCursor(LoadCursor(0, IDC_ARROW));
		return TRUE;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	Rectangle(hdc, g_rc.left, g_rc.top, g_rc.right, g_rc.bottom);

	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_SETCURSOR:		return OnSetCursor(hwnd, msg, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLButtonDown(hwnd, wParam, lParam);
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
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
	//wc.hCursor = LoadCursor(0, IDC_ARROW);//시스템
	wc.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR2));
	//wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;	 //미리 만들어서 제공되는 프로시저(윈도우 공통 기능)
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;		//메뉴 등록
	wc.style = 0;				//윈도우 스타일

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("0830"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//메시지 루프
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}