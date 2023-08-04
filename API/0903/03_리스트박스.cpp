//03_리스트박스 & 스태틱박스(정보를 출력하는 용도, 사용방법은 에디트와 동일)

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_LISTBOX1		1
#define IDC_STATIC1			2

HWND hlistbox1;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	//static은 handle없이 만들겠다.
	CreateWindow(
		TEXT("static"), TEXT("...."), WS_CHILD | WS_BORDER | WS_VISIBLE,
		20, 20, 200, 25, hwnd, (HMENU)IDC_STATIC1, hInst, 0);

	hlistbox1 = CreateWindow(
		TEXT("listbox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY,
		20, 50, 200, 300, hwnd, (HMENU)IDC_LISTBOX1, hInst, 0);

	//리스트박스에 문자열 넣기
	SendMessage(hlistbox1, LB_ADDSTRING, 0, (LPARAM)TEXT("빨강"));

	return 0;
}

TCHAR Items[][10] = { TEXT("파랑"), TEXT("녹색"), TEXT("검정"), TEXT("흰색") };

//부모 --> 컨트롤(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < 4; i++)
	{
		SendMessage(hlistbox1, LB_ADDSTRING, 0, (LPARAM)Items[i]);
	}
	return 0;
}

//자식 --> 부모(자신의 ID : LOWORD(wParam) )
//다양한 통지 패턴 (HIWORD(wParam) )
//OnCommand : 누가 보냈는가? 어떤 내용인가?
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_LISTBOX1)
	{
		if (HIWORD(wParam) == LBN_SELCHANGE)
		{
			//1. 선택된 인덱스 획득
			int idx = SendMessage(hlistbox1, LB_GETCURSEL, 0, 0);
			//2. 해당 인덱스의 문자열을 획득
			TCHAR msg[100] = { 0 };
			SendMessage(hlistbox1, LB_GETTEXT, idx, (LPARAM)msg);

			SetDlgItemText(hwnd, IDC_STATIC1, msg);
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