//무효화 영역 발생시키기
/*
* 방향키를 누르면 사각형 출력 위치 변경
* UP[ 위로 +10 ] DOWN [아래로 + 10] LEFT[왼쪽 +10], RIGHT[오른쪽 + 10]
*/
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static int x = 10;
	static int y = 10;
	static COLORREF color = RGB(255,0,0);

	switch (msg)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);   //검정색펜, 화이트브러쉬

		HBRUSH hbr = CreateSolidBrush(color);  //내 앞에 빨간색브러쉬 생성

		HBRUSH oldhbr = (HBRUSH)SelectObject(hdc, hbr);   //hbr을 손에 들었다., 기존 브러쉬는 리턴

		Rectangle(hdc, x, y, x + 100, y + 100);  

		//DeleteObject(SelectObject(hdc, oldhbr));	//oldhbr을 손에 들고, 반환된 hbr을 삭제함..

		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_KEYDOWN:	//키보드 메시지
	{
		switch (wParam)
		{
		case VK_UP:	    y = y - 10;	break;
		case VK_DOWN:	y = y + 10;	break;
		case VK_LEFT:	x = x - 10;	break;
		case VK_RIGHT:	x = x + 10;	break;
		case 'R':		color = RGB(255, 0, 0); break;
		case 'G':		color = RGB(0, 255, 0);	break;
		case 'B':		color = RGB(0, 0, 255); break;
		}
		InvalidateRect(hwnd, 0, TRUE);
		//RECT rt = { 0,0,50,50 };
		//InvalidateRect(hwnd, &rt, TRUE);
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
		//TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}