//skeleton �ڵ�
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

/*
LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	Rectangle(hdc, 100, 100, 200, 200);	 //������ pixel

	SetMapMode(hdc, MM_LOMETRIC);  //����ǥ 1 == 0.1mm(������ǥ) , Y�� ���� ��

	Rectangle(hdc, 0, 0, 100, -100);	//������ 0.1mm

	EndPaint(hwnd, &ps);
	return 0;
}
*/

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	POINT ar[] = { 25,10,125,10,140,30,10,30,25,10 };
	HBRUSH BrR, BrB, BrY, OldBr;
	RECT rect;

	BrR = CreateSolidBrush(RGB(255, 0, 0));
	BrB = CreateSolidBrush(RGB(0, 0, 255));
	BrY = CreateSolidBrush(RGB(255, 255, 0));

	SetMapMode(hdc, MM_ANISOTROPIC);		//<-----------------------
	SetWindowExtEx(hdc, 160, 100, NULL);	//��ǥ�� ��ü ũ�� ����...
	GetClientRect(hwnd, &rect);
	SetViewportExtEx(hdc, rect.right, rect.bottom, NULL);  //���� ��ǥ�� �����Ű�� �ڵ�

	OldBr = (HBRUSH)SelectObject(hdc, BrR);
	Rectangle(hdc, 20, 30, 130, 90);
	SelectObject(hdc, BrB);
	Polygon(hdc, ar, 5);

	SelectObject(hdc, BrY);
	Rectangle(hdc, 30, 40, 60, 70);
	Rectangle(hdc, 90, 40, 120, 70);
	Ellipse(hdc, 135, 5, 155, 25);

	SelectObject(hdc, OldBr);
	DeleteObject(BrR);
	DeleteObject(BrB);
	DeleteObject(BrY);

	EndPaint(hwnd, &ps);
	return 0;
}

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };		//������ǥ(pixel)
	HDC hdc = GetDC(hwnd);

	//Rectangle(hdc, pt.x, pt.y, pt.x + 100, pt.y + 100);	//����ǥ(pixcel)
	
	SetMapMode(hdc, MM_LOMETRIC);	//0.1mm	

	//������ǥ�� ����ǥ�� �����ؼ� ����
	DPtoLP(hdc, &pt, 1);

	Rectangle(hdc, pt.x, pt.y, pt.x + 100, pt.y + 100);	//����ǥ(0.1mm)

	ReleaseDC(hwnd, hdc);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_NCHITTEST:
	{
		//code : HITTEST code
		DWORD code = DefWindowProc(hwnd, msg, wParam, lParam);
		if (code == HTCLIENT && GetKeyState(VK_CONTROL) < 0)
			code = HTCAPTION;

		if (code == HTLEFT) 
			code = HTRIGHT;

		return code;
	}
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLButtonDown(hwnd, wParam, lParam);
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
	wc.style = CS_HREDRAW|CS_VREDRAW;				//������ ��Ÿ��

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