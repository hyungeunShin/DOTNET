//����� ���� �޽���
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

//1)�޽��� ����
#define WM_MYMSSAGE1  WM_USER + 100

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MYMSSAGE1:
	{
		TCHAR msg[20];
		wsprintf(msg, TEXT("%d, %d"), wParam, lParam);  //������ �̿��� ���ڿ��� ����� msg�� ����

		SetWindowText(hwnd, msg);  //
		return 0;
	}
	case WM_LBUTTONDOWN:  //
	{
		POINTS pt = MAKEPOINTS(lParam);   //���콺 ��ǥ ȹ��.		

		//2)����� ���� �޽����� ȣ��
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
	//MSG msg;
	//while (GetMessage(&msg, 0, 0, 0))   
	//{
	//	//TranslateMessage(&msg);
	//	DispatchMessage(&msg);			
	//}

	//�޽��� ����
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) //PM_REMOVE :�޽��� ��������,Q���� �����¸޽�������
		{
			if (msg.message == WM_QUIT)
				break;
			//TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else  //���޽ð�
		{
			HDC hdc = GetDC(hwnd);	//DC[�׸��� ������, ������ ������ �ִ� ������]��� GUI��ü

			//���� ���!
			SetPixel(hdc, rand() % 400, rand() % 400, RGB(0, 0, 0));

			ReleaseDC(hwnd, hdc);
		}
	}
	return 0;
}