//05_���ҽ�_Ŀ��.cpp

//�ڵ忡�� ���ҽ��� ����Ϸ��� ID�� �ʿ��ϴ�....resource.h

/*
* 1. ������Ŭ������ ���� ����� Ŀ���� ����
*     LoadCursor(�� �ν��Ͻ�,  MAKEINTRESOURCE(������Ŀ��ID));
* 
* 2. �������� Ŀ���� �����ϴ� ���(Ŀ���� ���콺�� ���� �ִ� ����)
*    WM_HITTEST ----------> WM_SETCURSOR  -----------------------> WSM_���콺�޽��� 
*    [HITTESTCODEȹ��]      [�ش���ġ������ ���콺Ŀ����纯��]
*                           �̸������Ǵ� SETCURSOR
*                           1)Ŭ���̾�Ʈ ���� : WClass���� ������ Ŀ�����
*                           2)�� ���� ���� : �˾Ƽ� ����
*                           Ŀ������� �����ϴ� �Լ� SetCursor
* 
*   ���� ���� WM_SETCURSOR�� ���͸�
*   ���ϴ� ��ġ���� SetCursor�Լ��� ȣ��
*   ������ ������ DefWindowProc���� ����
*/
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>
#include "resource.h"			//<===========================

RECT g_rc = { 100,100, 300, 300 };
//���콺 LButtonClick�Ҷ� Ŀ�� ����� ����...
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HCURSOR h1 = LoadCursorFromFile(TEXT("C:\\windows\\cursors\\person_il.cur"));
	SetCursor(h1);
	return 0;
}

LRESULT OnSetCursor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	int code = LOWORD(lParam); // hit test code�� ��� �ִ�.
	
	POINT pt;
	GetCursorPos(&pt); // ���� Ŀ���� ��ġ(��ũ�� ��ǥ)
	ScreenToClient(hwnd, &pt); // ��ũ�� ��ǥ�� Ŭ���� ��Ʈ ��ǥ��..
	
	// Ŭ���̾�Ʈ �ȿ����� Ư����ġ������ �ٸ� Ŀ���� ����ϴ� ���.
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
	//������ Ŭ���� ����
	WNDCLASS	wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //��, �귯��, ��Ʈ
	//wc.hCursor = LoadCursor(0, IDC_ARROW);//�ý���
	wc.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_CURSOR2));
	//wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
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