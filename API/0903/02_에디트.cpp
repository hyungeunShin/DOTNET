//02_에디트.cpp
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_EDIT1		1
#define IDC_EDIT2		2

HWND hedit1, hedit2;
//하나의 에디트 컨트롤은 32k크기의 문자를 출력할 수 있다.
LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hedit1 = CreateWindow(
		TEXT("edit"), TEXT("......"), WS_CHILD | WS_BORDER | WS_VISIBLE,
		20, 20, 200, 25, hwnd, (HMENU)IDC_EDIT1, hInst, 0);

	hedit2 = CreateWindow(
		TEXT("edit"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL,//수평
		20, 50, 200, 25, hwnd, (HMENU)IDC_EDIT2, hInst, 0);

	return 0;
}

//부모 --> 컨트롤(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//첫번째 에디트 컨트롤에 있는 문자열을 두번째 에디트 컨트롤에 출력
	//1) 윈도우 성질....
//	TCHAR msg[100];
//	GetWindowText(hedit1, msg, _countof(msg));
//	SetWindowText(hedit2, msg);

	//2) 에디트컨트롤의 ID를 활용하는 방식(핸들 없이)
//	TCHAR msg[100];
	//다이얼로그(부모)의 아이템(자식)으로부터 글자(문자열)를 얻어오겠다.
//	GetDlgItemText(hwnd, IDC_EDIT1, msg, _countof(msg));
//	SetDlgItemText(hwnd, IDC_EDIT2, msg);

	//3) 에디트컨트롤의 ID를 활용하는 방식(핸들 없이)
	int value;
	//다이얼로그(부모)의 아이템(자식)으로부터 글자(숫자)를 얻어오겠다.
	value = GetDlgItemInt(hwnd, IDC_EDIT1, 0, 0);
	SetDlgItemInt(hwnd, IDC_EDIT2, value, 0);

	return 0;
}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_EDIT1)
	{		
		if (HIWORD(wParam) == EN_CHANGE)
		{
			TCHAR msg[100];
			GetDlgItemText(hwnd, IDC_EDIT1, msg, _countof(msg));
			SetDlgItemText(hwnd, IDC_EDIT2, msg);
		}
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:		return OnCommand(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLButtonDown(hwnd, wParam, lParam);
	case WM_CREATE:			return OnCreate(hwnd, wParam, lParam);
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
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
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