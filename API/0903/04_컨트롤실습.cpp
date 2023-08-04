//04_��Ʈ�� �ǽ�

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_EDIT1			1
#define IDC_BUTTON1			2
#define IDC_LISTBOX1		3
#define IDC_STATIC1			4

HWND hedit1, button1, hlistbox1;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hedit1 = CreateWindow(
		TEXT("edit"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE,
		20, 20, 200, 25, hwnd, (HMENU)IDC_EDIT1, hInst, 0);

	button1 = CreateWindow(
		TEXT("button"), TEXT("����"), WS_CHILD | WS_BORDER | WS_VISIBLE | BS_PUSHBUTTON,
		230, 20, 100, 25, hwnd, (HMENU)IDC_BUTTON1, hInst, 0);

	CreateWindow(
		TEXT("static"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE,
		20, 60, 310, 25, hwnd, (HMENU)IDC_STATIC1, hInst, 0);

	hlistbox1 = CreateWindow(
		TEXT("listbox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY,
		20, 90, 310, 300, hwnd, (HMENU)IDC_LISTBOX1, hInst, 0);

	SetFocus(hedit1);

	return 0;
}

TCHAR Items[][10] = { TEXT("�Ķ�"), TEXT("���"), TEXT("����"), TEXT("���") };

//�θ� --> ��Ʈ��(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{

	return 0;
}

//�ڽ� --> �θ�(�ڽ��� ID : LOWORD(wParam) )
//�پ��� ���� ���� (HIWORD(wParam) )

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_BUTTON1)
	{
		TCHAR msg[100];

		//����Ʈ��Ʈ�ѿ��� ���ڿ� ȹ��
		GetDlgItemText(hwnd, IDC_EDIT1, msg, _countof(msg));

		//����ó��
		if (_tcslen(msg) > 0)
		{
			//����Ʈ�ڽ��� �߰�
			SendMessage(hlistbox1, LB_ADDSTRING, 0, (LPARAM)msg);

			//����Ʈ ��Ʈ�� �ʱ�ȭ
			SetDlgItemText(hwnd, IDC_EDIT1, TEXT(""));
		}
		//��Ŀ�� �̵�
		SetFocus(hedit1);
	}
	else if (LOWORD(wParam) == IDC_LISTBOX1)
	{		
		if(HIWORD(wParam) == LBN_SELCHANGE)
		{
			//1. ���õ� �ε��� ȹ��
			int idx = SendMessage(hlistbox1, LB_GETCURSEL, 0, 0);
			//2. �ش� �ε����� ���ڿ��� ȹ��
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
	//������ Ŭ���� ����
	WNDCLASS	wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //��, �귯��, ��Ʈ
	wc.hCursor = LoadCursor(0, IDC_ARROW);//�ý���
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;	 //�̸� ���� �����Ǵ� ���ν���(������ ���� ���)
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;		//�޴� ���
	wc.style = 0;				//������ ��Ÿ��

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("0830"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//�޽��� ����
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}