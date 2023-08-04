//���α׷� �� ������ �ۼ���(���ź�)
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define WM_MYPOINT	  WM_USER +100
#define WM_MYPOINT1	  WM_USER +200

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MYPOINT1:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);

		HDC hdc = GetDC(hwnd);

		Ellipse(hdc, x, y, x + 50, y + 50);

		ReleaseDC(hwnd, hdc);
		MessageBox(0, TEXT(""), TEXT(""), MB_OK);
		return 111;
	}
	case WM_MYPOINT:
	{
		int x = wParam;
		int y = lParam;

		HDC hdc = GetDC(hwnd);

		Rectangle(hdc, x, y, x + 50, y + 50);

		ReleaseDC(hwnd, hdc);
		return 0;
	}
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
	wc.hCursor = LoadCursor(0, IDC_ARROW);//�ý���
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;	 //�̸� ���� �����Ǵ� ���ν���(������ ���� ���)
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;		//�޴� ���
	wc.style = 0;				//������ ��Ÿ��

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("Sample"), WS_OVERLAPPEDWINDOW,
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