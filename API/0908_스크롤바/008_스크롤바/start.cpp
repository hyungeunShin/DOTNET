//start.cpp

#include "std.h"

COLORREF color = RGB(100, 100, 100);

//부모 자식 공유 데이터
COLORDATA data;
HWND g_child = NULL;

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (g_child == NULL)
	{
		data.r = GetRValue(color);
		data.g = GetGValue(color);
		data.b = GetBValue(color);

		g_child = CreateDialogParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1),
			hwnd, ColorDlgProc, (LPARAM)&data);
		ShowWindow(g_child, SW_SHOW);
	}
	else
	{
		SetFocus(g_child);
	}
	return 0;
}

LRESULT OnApply(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	color = data.color;
	InvalidateRect(hwnd, 0, TRUE);
	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	RECT rc;
	GetClientRect(hwnd, &rc);

	HBRUSH hbrush = CreateSolidBrush(color);

	FillRect(hdc, &rc, hbrush);

	DeleteObject(hbrush);

	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_APPLY:			return OnApply(hwnd, wParam, lParam);
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
	wc.hCursor = LoadCursor(0, IDC_ARROW);//시스템
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;	 //미리 만들어서 제공되는 프로시저(윈도우 공통 기능)
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;		//메뉴 등록
	wc.style = 0;				//윈도우 스타일

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("0830"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 500, 500,
		0, 0, hInst, 0);

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