//01_버튼
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_BUTTON1		1
#define IDC_BUTTON2		2

HWND hbutton1, hbutton2;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hbutton1 = CreateWindow(
		TEXT("button"), TEXT("클릭!"), WS_CHILD|WS_BORDER |WS_VISIBLE |BS_PUSHBUTTON,
		20,20,100,25, hwnd, (HMENU)IDC_BUTTON1, hInst, 0);

	hbutton2 = CreateWindow(
		TEXT("button"), TEXT("클릭!"), WS_CHILD | WS_BORDER | WS_VISIBLE | BS_PUSHBUTTON,
		20, 50, 100, 25, hwnd, (HMENU)IDC_BUTTON2, hInst, 0);

	return 0;
}

//부모 --> 컨트롤(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SetWindowText(hwnd, TEXT("부모의 타이틀바 정보 출력"));
	SetWindowText(hbutton1, TEXT("변경"));
	return 0;
}

//자식 --> 부모(자신의 ID : LOWORD(wParam) )
//버튼은 내가 클릭되었어.
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_BUTTON1)
	{
		//부모 타이틀바 문자열을 획득 -> 메시지박스로 출력
		TCHAR msg[100];
		GetWindowText(hwnd, msg, _countof(msg));
		MessageBox(hwnd, msg, TEXT("부모 문자열"), MB_OK);
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		//부모가 갖고 있는 문자열을 획득해서 해당 문자열로 2번째 버튼의 문자열을 수정
		TCHAR msg[100];
		GetWindowText(hwnd, msg, _countof(msg));
		SetWindowText(hbutton2, msg);
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
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}


hlistbox = CreateWindow(
	TEXT("listbox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY,
	20, 50, 500, 200, hwnd, (HMENU)IDC_LISTBOX, hInst, 0);

hbutton = CreateWindow(
	TEXT("button"), TEXT("저장!"), WS_CHILD | WS_BORDER | WS_VISIBLE | BS_PUSHBUTTON,
	200, 200, 100, 25, hwnd, (HMENU)IDC_BUTTON, hInst, 0);

hcombobox = CreateWindow(
	TEXT("combobox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | CBS_DROPDOWN,
	20, 50, 200, 200, hwnTCHAR Items[][30] = { TEXT("1"), TEXT("2"), TEXT("3"), TEXT("4"), TEXT("5"), TEXT("6"), TEXT("7"),
TEXT("8"), TEXT("9"), TEXT("10"), TEXT("11"), TEXT("12"), TEXT("13"), TEXT("14"), TEXT("15"), TEXT("16"),
TEXT("17"), TEXT("18"),TEXT("19") ,TEXT("20") ,TEXT("21") ,TEXT("22") ,TEXT("23") ,TEXT("24"),TEXT("25"),
TEXT("26"), TEXT("27"),TEXT("28"),TEXT("29"), TEXT("30") }; d, (HMENU)IDC_COMBOBOX, hInst, 0);