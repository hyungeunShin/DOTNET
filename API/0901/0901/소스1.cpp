//skeleton 코드
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

/*
LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	Rectangle(hdc, 100, 100, 200, 200);	 //단위가 pixel

	SetMapMode(hdc, MM_LOMETRIC);  //논리좌표 1 == 0.1mm(물리좌표) , Y축 증가 위

	Rectangle(hdc, 0, 0, 100, -100);	//단위가 0.1mm

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
	SetWindowExtEx(hdc, 160, 100, NULL);	//좌표의 전체 크기 설정...
	GetClientRect(hwnd, &rect);
	SetViewportExtEx(hdc, rect.right, rect.bottom, NULL);  //원점 좌표를 변경시키는 코드

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
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };		//물리좌표(pixel)
	HDC hdc = GetDC(hwnd);

	//Rectangle(hdc, pt.x, pt.y, pt.x + 100, pt.y + 100);	//논리좌표(pixcel)
	
	SetMapMode(hdc, MM_LOMETRIC);	//0.1mm	

	//물리좌표를 논리좌표로 변경해서 전달
	DPtoLP(hdc, &pt, 1);

	Rectangle(hdc, pt.x, pt.y, pt.x + 100, pt.y + 100);	//논리좌표(0.1mm)

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
	wc.style = CS_HREDRAW|CS_VREDRAW;				//윈도우 스타일

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