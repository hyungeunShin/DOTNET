//사용자 정의 메시지
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

//1)메시지 정의
#define WM_MYMSSAGE1  WM_USER + 100

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MYMSSAGE1:
	{
		TCHAR msg[20];
		wsprintf(msg, TEXT("%d, %d"), wParam, lParam);  //서식을 이용해 문자열을 만들고 msg에 저장

		SetWindowText(hwnd, msg);  //
		return 0;
	}
	case WM_LBUTTONDOWN:  //
	{
		POINTS pt = MAKEPOINTS(lParam);   //마우스 좌표 획득.		

		//2)사용자 정의 메시지를 호출
		//SendMessage(hwnd, WM_MYMSSAGE1, pt.x, pt.y);
		PostMessage(hwnd, WM_MYMSSAGE1, pt.x, pt.y);
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
	//MSG msg;
	//while (GetMessage(&msg, 0, 0, 0))   
	//{
	//	//TranslateMessage(&msg);
	//	DispatchMessage(&msg);			
	//}

	//메시지 루프
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) //PM_REMOVE :메시지 가져오기,Q에서 가져온메시지제거
		{
			if (msg.message == WM_QUIT)
				break;
			//TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else  //유휴시간
		{
			HDC hdc = GetDC(hwnd);	//DC[그리는 영역과, 도구를 가지고 있는 데이터]라는 GUI객체

			//점을 출력!
			SetPixel(hdc, rand() % 400, rand() % 400, RGB(0, 0, 0));

			ReleaseDC(hwnd, hdc);
		}
	}
	return 0;
}