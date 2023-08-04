//07_������ư

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_BUTTON11		1 //�׷�
#define IDC_BUTTON12		2
#define IDC_BUTTON13		3
#define IDC_BUTTON21		4 //�׷�
#define IDC_BUTTON22		5
#define IDC_BUTTON23		6

HWND hrb1, hrb2, hrb3, hrb4, hrb5, hrb6;

int shapeType		= 0;
COLORREF shapeColor = RGB(0, 255, 0);

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	//�׷�ڽ�
	CreateWindow(
		TEXT("button"), TEXT("����"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		5, 5, 120, 110, hwnd, (HMENU)0, hInst, 0);

	CreateWindow(
		TEXT("button"), TEXT("����"), WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		145, 5, 120, 110, hwnd, (HMENU)0, hInst, 0);

	//������ư
	hrb1 = CreateWindow(
		TEXT("button"), TEXT("�簢��"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON |WS_GROUP,
		10, 20, 100, 30, hwnd, (HMENU)IDC_BUTTON11, hInst, 0);

	hrb2 = CreateWindow(
		TEXT("button"), TEXT("Ÿ��"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		10, 50, 100, 30, hwnd, (HMENU)IDC_BUTTON12, hInst, 0);

	hrb3 = CreateWindow(
		TEXT("button"), TEXT("��"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		10, 80, 100, 30, hwnd, (HMENU)IDC_BUTTON13, hInst, 0);
	//-----------------------------------------------------------------------
	hrb4 = CreateWindow(
		TEXT("button"), TEXT("����"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		150, 20, 100, 30, hwnd, (HMENU)IDC_BUTTON21, hInst, 0);

	hrb5 = CreateWindow(
		TEXT("button"), TEXT("���"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		150, 50, 100, 30, hwnd, (HMENU)IDC_BUTTON22, hInst, 0);

	hrb6 = CreateWindow(
		TEXT("button"), TEXT("�Ķ�"), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		150, 80, 100, 30, hwnd, (HMENU)IDC_BUTTON23, hInst, 0);

	//--------------- ���� ��ư �� Ư�� ���� ��ư�� ���� ���·� ���� ------
	CheckRadioButton(hwnd, IDC_BUTTON11, IDC_BUTTON13, IDC_BUTTON11);
	CheckRadioButton(hwnd, IDC_BUTTON21, IDC_BUTTON23, IDC_BUTTON22);

	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	HBRUSH hbr = CreateSolidBrush(shapeColor);
	HBRUSH oldb = (HBRUSH)SelectObject(hdc, hbr);

	HPEN hpen = CreatePen(PS_SOLID, 1, shapeColor);
	HPEN oldpen = (HPEN)SelectObject(hdc, hpen);

	if (shapeType == 0)
		Rectangle(hdc, 100, 150, 200, 250);
	else if (shapeType == 1)
		Ellipse(hdc, 100, 150, 200, 250);
	else if (shapeType == 2)
	{
		MoveToEx(hdc, 100, 150, NULL);
		LineTo(hdc, 200, 250);
	}

	DeleteObject(SelectObject(hdc, oldpen));
	DeleteObject(SelectObject(hdc, oldb));
	
	EndPaint(hwnd, &ps);
	return 0;
}

//�ڽ� --> �θ�(�ڽ��� ID : LOWORD(wParam) )
//��ư�� ���� Ŭ���Ǿ���.
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch(LOWORD(wParam))
	{
	case IDC_BUTTON11:	shapeType = 0;	break;
	case IDC_BUTTON12:	shapeType = 1;	break;
	case IDC_BUTTON13:	shapeType = 2;	break;
	case IDC_BUTTON21:	shapeColor = RGB(255, 0, 0);	break;
	case IDC_BUTTON22:	shapeColor = RGB(0, 255, 0);	break;
	case IDC_BUTTON23:	shapeColor = RGB(0, 0, 255);	break;
	}
	InvalidateRect(hwnd, 0, TRUE);
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
