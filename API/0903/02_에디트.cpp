//02_����Ʈ.cpp
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_EDIT1		1
#define IDC_EDIT2		2

HWND hedit1, hedit2;
//�ϳ��� ����Ʈ ��Ʈ���� 32kũ���� ���ڸ� ����� �� �ִ�.
LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hedit1 = CreateWindow(
		TEXT("edit"), TEXT("......"), WS_CHILD | WS_BORDER | WS_VISIBLE,
		20, 20, 200, 25, hwnd, (HMENU)IDC_EDIT1, hInst, 0);

	hedit2 = CreateWindow(
		TEXT("edit"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL,//����
		20, 50, 200, 25, hwnd, (HMENU)IDC_EDIT2, hInst, 0);

	return 0;
}

//�θ� --> ��Ʈ��(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	//ù��° ����Ʈ ��Ʈ�ѿ� �ִ� ���ڿ��� �ι�° ����Ʈ ��Ʈ�ѿ� ���
	//1) ������ ����....
//	TCHAR msg[100];
//	GetWindowText(hedit1, msg, _countof(msg));
//	SetWindowText(hedit2, msg);

	//2) ����Ʈ��Ʈ���� ID�� Ȱ���ϴ� ���(�ڵ� ����)
//	TCHAR msg[100];
	//���̾�α�(�θ�)�� ������(�ڽ�)���κ��� ����(���ڿ�)�� �����ڴ�.
//	GetDlgItemText(hwnd, IDC_EDIT1, msg, _countof(msg));
//	SetDlgItemText(hwnd, IDC_EDIT2, msg);

	//3) ����Ʈ��Ʈ���� ID�� Ȱ���ϴ� ���(�ڵ� ����)
	int value;
	//���̾�α�(�θ�)�� ������(�ڽ�)���κ��� ����(����)�� �����ڴ�.
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