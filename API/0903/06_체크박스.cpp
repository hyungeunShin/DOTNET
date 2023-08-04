//06_üũ�ڽ�

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
		TEXT("button"), TEXT("�簢�����"), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		20, 20, 100, 25, hwnd, (HMENU)IDC_BUTTON1, hInst, 0);

	hbutton2 = CreateWindow(
		TEXT("button"), TEXT("�귯����뿩��"), WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
		20, 50, 100, 25, hwnd, (HMENU)IDC_BUTTON2, hInst, 0);

	return 0;
}


LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	//1.���� üũ�� ���
	HPEN hbr;
	if (SendMessage(hbutton2, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		hbr = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	}
	else
	{
		hbr = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
	}

	HPEN hbrold = (HPEN)SelectObject(hdc, hbr);

	if (SendMessage(hbutton1, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		Rectangle(hdc, 100, 100, 200, 200);
	}
	else
	{
		Ellipse(hdc, 100, 100, 200, 200);
	}	

	DeleteObject(SelectObject(hdc, hbrold));

	EndPaint(hwnd, &ps);
	return 0;
}

//�ڽ� --> �θ�(�ڽ��� ID : LOWORD(wParam) )
//��ư�� ���� Ŭ���Ǿ���.
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_BUTTON1)
	{
		InvalidateRect(hwnd, 0, TRUE);
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)  //üũ���¸� �������� ó��.!!
	{
		if (SendMessage(hbutton2, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			SendMessage(hbutton2, BM_SETCHECK, BST_UNCHECKED, 0);
		}
		else
		{
			SendMessage(hbutton2, BM_SETCHECK, BST_CHECKED, 0);
		}
		InvalidateRect(hwnd, 0, TRUE);
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
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
