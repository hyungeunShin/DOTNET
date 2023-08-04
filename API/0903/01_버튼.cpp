//01_��ư
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_BUTTON1		1
#define IDC_BUTTON2		2

HWND hbutton1, hbutton2;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hbutton1 = CreateWindow(
		TEXT("button"), TEXT("Ŭ��!"), WS_CHILD|WS_BORDER |WS_VISIBLE |BS_PUSHBUTTON,
		20,20,100,25, hwnd, (HMENU)IDC_BUTTON1, hInst, 0);

	hbutton2 = CreateWindow(
		TEXT("button"), TEXT("Ŭ��!"), WS_CHILD | WS_BORDER | WS_VISIBLE | BS_PUSHBUTTON,
		20, 50, 100, 25, hwnd, (HMENU)IDC_BUTTON2, hInst, 0);

	return 0;
}

//�θ� --> ��Ʈ��(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	SetWindowText(hwnd, TEXT("�θ��� Ÿ��Ʋ�� ���� ���"));
	SetWindowText(hbutton1, TEXT("����"));
	return 0;
}

//�ڽ� --> �θ�(�ڽ��� ID : LOWORD(wParam) )
//��ư�� ���� Ŭ���Ǿ���.
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_BUTTON1)
	{
		//�θ� Ÿ��Ʋ�� ���ڿ��� ȹ�� -> �޽����ڽ��� ���
		TCHAR msg[100];
		GetWindowText(hwnd, msg, _countof(msg));
		MessageBox(hwnd, msg, TEXT("�θ� ���ڿ�"), MB_OK);
	}
	else if (LOWORD(wParam) == IDC_BUTTON2)
	{
		//�θ� ���� �ִ� ���ڿ��� ȹ���ؼ� �ش� ���ڿ��� 2��° ��ư�� ���ڿ��� ����
		TCHAR msg[100];
		GetWindowText(hwnd, msg, _countof(msg));
		SetWindowText(hbutton2, msg);
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:		return OnCommand(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLButtonDown(hwnd, wParam, lParam);
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


hlistbox = CreateWindow(
	TEXT("listbox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY,
	20, 50, 500, 200, hwnd, (HMENU)IDC_LISTBOX, hInst, 0);

hbutton = CreateWindow(
	TEXT("button"), TEXT("����!"), WS_CHILD | WS_BORDER | WS_VISIBLE | BS_PUSHBUTTON,
	200, 200, 100, 25, hwnd, (HMENU)IDC_BUTTON, hInst, 0);

hcombobox = CreateWindow(
	TEXT("combobox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | CBS_DROPDOWN,
	20, 50, 200, 200, hwnTCHAR Items[][30] = { TEXT("1"), TEXT("2"), TEXT("3"), TEXT("4"), TEXT("5"), TEXT("6"), TEXT("7"),
TEXT("8"), TEXT("9"), TEXT("10"), TEXT("11"), TEXT("12"), TEXT("13"), TEXT("14"), TEXT("15"), TEXT("16"),
TEXT("17"), TEXT("18"),TEXT("19") ,TEXT("20") ,TEXT("21") ,TEXT("22") ,TEXT("23") ,TEXT("24"),TEXT("25"),
TEXT("26"), TEXT("27"),TEXT("28"),TEXT("29"), TEXT("30") }; d, (HMENU)IDC_COMBOBOX, hInst, 0);