//03_Timer.cpp
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

//L Button Ŭ���� �ý���, �����ð� ������ ȹ��->OnPaint���� Ŭ���̾�Ʈ ���� ��ܿ� ���
#define ID_TIMER1		1

TCHAR g_localTime[256];

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SetTimer(hwnd, ID_TIMER1, 1000, NULL);
	SendMessage(hwnd, WM_TIMER, 1, NULL); //�߰��� �κ�

	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	KillTimer(hwnd, ID_TIMER1);

	PostQuitMessage(0);
	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	HFONT font = CreateFont(36, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));

	HFONT oldfont = (HFONT)SelectObject(hdc, font);

	TextOut(hdc, 50, 50, g_localTime, _tcslen(g_localTime));

	DeleteObject(SelectObject(hdc, oldfont));

	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT OnTimer(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SYSTEMTIME st;

	//���� �ð�
	GetLocalTime(&st);
	wsprintf(g_localTime, TEXT("%04d-%02d-%02d %02d:%02d:%02d"),
		st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

	InvalidateRect(hwnd, 0, TRUE);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_TIMER:			return OnTimer(hwnd, wParam, lParam);
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
	case WM_CREATE:			return OnCreate(hwnd, wParam, lParam);
	case WM_DESTROY:		return OnDestroy(hwnd, wParam, lParam);
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