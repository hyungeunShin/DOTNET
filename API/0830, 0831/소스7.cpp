//DC �ڵ�
/*
* LButtonDown Ŭ���� 0, 0�� 100*100�� �簢�� ���
* WM_PAINT����  150, 0�� 100*100�� �簢�� ���
*/
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_PAINT: //��ȿȭ�� �߻��Ǿ�����...--> ��ȿȭ ������ �����ؾ� �Ѵ�....:�������������� ���ѹݺ�
	{
		//DCȹ��, ��ȿȭ ������ �����ϴ� ����!!!!!!
		//Ŭ���̾�Ʈ���� ��ȿȭ�� ������ �׸� �� �ִ� DC
		//Ŭ���� ����== ��ȿȭ����
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);	

		Rectangle(hdc, 150, 0, 150 + 100, 0 + 100);

		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_LBUTTONDOWN:
	{
		HDC hdc = GetDC(hwnd);

		Rectangle(hdc, 0, 0, 0+100, 0+100);

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