//03_����Ʈ�ڽ� & ����ƽ�ڽ�(������ ����ϴ� �뵵, ������� ����Ʈ�� ����)

#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

#define IDC_LISTBOX1		1
#define IDC_STATIC1			2

HWND hlistbox1;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	//static�� handle���� ����ڴ�.
	CreateWindow(
		TEXT("static"), TEXT("...."), WS_CHILD | WS_BORDER | WS_VISIBLE,
		20, 20, 200, 25, hwnd, (HMENU)IDC_STATIC1, hInst, 0);

	hlistbox1 = CreateWindow(
		TEXT("listbox"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | LBS_NOTIFY,
		20, 50, 200, 300, hwnd, (HMENU)IDC_LISTBOX1, hInst, 0);

	//����Ʈ�ڽ��� ���ڿ� �ֱ�
	SendMessage(hlistbox1, LB_ADDSTRING, 0, (LPARAM)TEXT("����"));

	return 0;
}

TCHAR Items[][10] = { TEXT("�Ķ�"), TEXT("���"), TEXT("����"), TEXT("���") };

//�θ� --> ��Ʈ��(SendMessage)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	for (int i = 0; i < 4; i++)
	{
		SendMessage(hlistbox1, LB_ADDSTRING, 0, (LPARAM)Items[i]);
	}
	return 0;
}

//�ڽ� --> �θ�(�ڽ��� ID : LOWORD(wParam) )
//�پ��� ���� ���� (HIWORD(wParam) )
//OnCommand : ���� ���´°�? � �����ΰ�?
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDC_LISTBOX1)
	{
		if (HIWORD(wParam) == LBN_SELCHANGE)
		{
			//1. ���õ� �ε��� ȹ��
			int idx = SendMessage(hlistbox1, LB_GETCURSEL, 0, 0);
			//2. �ش� �ε����� ���ڿ��� ȹ��
			TCHAR msg[100] = { 0 };
			SendMessage(hlistbox1, LB_GETTEXT, idx, (LPARAM)msg);

			SetDlgItemText(hwnd, IDC_STATIC1, msg);
		}
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
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}