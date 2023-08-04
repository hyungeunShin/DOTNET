//윈도우 만들기
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

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
	wc.lpfnWndProc = DefWindowProc;	 //미리 만들어서 제공되는 프로시저(윈도우 공통 기능)

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

	MessageBox(0, _TEXT("Hello,World!"), _TEXT("알림"), MB_OKCANCEL | MB_ICONQUESTION);
	return 0;
}
