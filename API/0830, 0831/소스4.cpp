//skeleton 코드
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

//WM_CLOSE : 메인윈도우를 종료하고자 할때 발생하는 최초 메시지 
//           1) 윈도우가 파괴가 된다.DestroyWindow()
//           2) 윈도우가 종료됨을 비큐메시지로 알림  WM_DESTROY
// 
//WM_DESTROY : 반드시 메시지 루프를 종료시켜야 한다.

//프로시저[메시지 처리, 반복 호출]
//CALLBACK : 미리 등록해 놓으면 필요할 때 호출
//           자신의 메시지큐에 WM_QUIT를 넣어주어야 한다.
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:	//초기화[호출시점 : 윈도우가 생성되고 눈에 보이기 전]
	{
		return 0;
	}
	case WM_DESTROY:	//종료처리[호출시점 : 윈도우가 파괴되고 나서]
	{
		PostQuitMessage(0);  //Post : 메시지큐에 메시지를 보낸다. QUIT : 메시지 종류:WM_QUIT
		return 0;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


//시작함수[윈도우 생성, 메시지 루프]
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	//1. 윈도우 클래스 정의
	WNDCLASS	wc;
	//확장 정보(지금은 필요없다, 나중을 위해서)
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	//윈도우 기본 정보(시스템에서 제공되는 정보)
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //펜, 브러쉬, 폰트
	wc.hCursor = LoadCursor(0, IDC_ARROW);//시스템
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;	 //미리 만들어서 제공되는 프로시저(윈도우 공통 기능)

	//해당 윈도우 클래스 KEY
	wc.lpszClassName = TEXT("First");

	//추가 정보
	wc.lpszMenuName = 0;		//메뉴 등록
	wc.style = 0;				//윈도우 스타일

	//2. 레지스트리에 등록
	RegisterClass(&wc);

	//3. 윈도우 만들기(UI)
	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("0830"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);

	//4. 윈도우 출력
	ShowWindow(hwnd, SW_SHOW); //ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);		   //나중에 설명

	//---------------- 메시지 루프 ----------------------------
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))   //자신의 AMQ에서 메시지 가져오기..[리턴FLASE : WM_QUIT ]
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);			//가져온 M를 미리 등록된 Proc 전달.
	}
	//-------------------------------------------------------

	return 0;
}
