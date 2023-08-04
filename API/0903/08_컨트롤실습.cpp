//08_컨트롤실습
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_E_NAME		1
#define IDC_CB_AGE		2
#define IDC_RB_MALE		3
#define IDC_RB_FEMALE	4
#define IDC_CB_PLAY		5
#define IDC_CB_GAME		6
#define IDC_CB_READ		7
#define IDC_B_SAVE		8
#define IDC_LB_VIEW		9

HWND hEName, hCBAge, hRBMale, hRBFemale, hCBPlay, hCBGame, hCBRead, hBSave, hLBView;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hEName = CreateWindow(
		TEXT("edit"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE,
		100, 50, 200, 25, hwnd, (HMENU)IDC_E_NAME, hInst, 0);
	
	hCBAge = CreateWindow(
		TEXT("combobox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | CBS_DROPDOWNLIST | WS_VSCROLL,
		100, 90, 200, 200, hwnd, (HMENU)IDC_CB_AGE, hInst, 0);

	//라디오버튼
	hRBMale = CreateWindow(
		TEXT("button"), TEXT("남"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		100, 130, 100, 30, hwnd, (HMENU)IDC_RB_MALE, hInst, 0);

	hRBFemale = CreateWindow(
		TEXT("button"), TEXT("여"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		200, 130, 100, 30, hwnd, (HMENU)IDC_RB_FEMALE, hInst, 0);

	//체크박스
	hCBPlay = CreateWindow(
		TEXT("button"), TEXT("운동"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		100, 170, 100, 25, hwnd, (HMENU)IDC_CB_PLAY, hInst, 0);

	hCBGame = CreateWindow(
		TEXT("button"), TEXT("게임"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		200, 170, 100, 25, hwnd, (HMENU)IDC_CB_GAME, hInst, 0);

	hCBRead = CreateWindow(
		TEXT("button"), TEXT("독서"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		300, 170, 100, 25, hwnd, (HMENU)IDC_CB_READ, hInst, 0);

	hBSave = CreateWindow(
		TEXT("button"), TEXT("저장"), WS_CHILD | WS_BORDER | WS_VISIBLE | BS_PUSHBUTTON,
		300, 230, 100, 25, hwnd, (HMENU)IDC_B_SAVE, hInst, 0);

	hLBView = CreateWindow(
		TEXT("listbox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY| WS_VSCROLL,
		50, 270, 350, 300, hwnd, (HMENU)IDC_LB_VIEW, hInst, 0);


	//콤보박스 초기화
	TCHAR temp[10];
	for (int i = 1; i <= 30; i++)
	{
		wsprintf(temp, TEXT("%d"), i);
		SendMessage(hCBAge, CB_ADDSTRING, 0, (LPARAM)temp);
	}

	//라디오버튼 초기화
	CheckRadioButton(hwnd, IDC_RB_MALE, IDC_RB_FEMALE, IDC_RB_MALE);

	SetFocus(hEName);
	return 0;
}

//부모 --> 컨트롤(SendMessage)
LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	TextOut(hdc, 50, 50, TEXT("이름"), _tcslen(TEXT("이름")));
	TextOut(hdc, 50, 90, TEXT("나이"), _tcslen(TEXT("나이")));
	TextOut(hdc, 50, 130, TEXT("성별"), _tcslen(TEXT("성별")));
	TextOut(hdc, 50, 170, TEXT("취미"), _tcslen(TEXT("취미")));

	EndPaint(hwnd, &ps);
	return 0;
}

//자식 --> 부모(자신의 ID : LOWORD(wParam) )
//버튼은 내가 클릭되었어.
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_B_SAVE)
	{
		TCHAR printMsg[200];

		//이름
		TCHAR inputName[20];
		GetDlgItemText(hwnd, IDC_E_NAME, inputName, _countof(inputName));

		//나이
		TCHAR inputAge[10] = { 0 };
		int idx = SendMessage(hCBAge, CB_GETCURSEL, 0, 0);		
		SendMessage(hCBAge, CB_GETLBTEXT, idx, (LPARAM)inputAge);

		//성별
		TCHAR inputGender[10] = { 0 };
		if (SendMessage(hRBMale, BM_GETCHECK, 0, 0) == BST_CHECKED)
			_tcscpy_s(inputGender, _countof(inputGender), TEXT("남"));
		else
			_tcscpy_s(inputGender, _countof(inputGender), TEXT("여"));

		//취미
		TCHAR inputHabby[30] = { 0 };
		if (SendMessage(hCBPlay, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			_tcscpy_s(inputHabby, _countof(inputHabby), TEXT("운동"));
		}
		if (SendMessage(hCBGame, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			_tcscat_s(inputHabby, _countof(inputHabby), TEXT(", 게임"));
		}
		if (SendMessage(hCBRead, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			_tcscat_s(inputHabby, _countof(inputHabby), TEXT(", 독서"));
		}


		wsprintf(printMsg, TEXT("%s, %s세, %s, (%s)"), 
			inputName, inputAge, inputGender, inputHabby);
		SendMessage(hLBView, LB_ADDSTRING, 0, (LPARAM)printMsg);
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:		return OnCommand(hwnd, wParam, lParam);
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
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