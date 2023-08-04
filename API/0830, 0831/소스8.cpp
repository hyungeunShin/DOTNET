//��ȿȭ ���� �߻���Ű��
/*
* ����Ű�� ������ �簢�� ��� ��ġ ����
* UP[ ���� +10 ] DOWN [�Ʒ��� + 10] LEFT[���� +10], RIGHT[������ + 10]
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
		HDC hdc = BeginPaint(hwnd, &ps);   //��������, ȭ��Ʈ�귯��

		HBRUSH hbr = CreateSolidBrush(color);  //�� �տ� �������귯�� ����

		HBRUSH oldhbr = (HBRUSH)SelectObject(hdc, hbr);   //hbr�� �տ� �����., ���� �귯���� ����

		Rectangle(hdc, x, y, x + 100, y + 100);  

		//DeleteObject(SelectObject(hdc, oldhbr));	//oldhbr�� �տ� ���, ��ȯ�� hbr�� ������..

		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_KEYDOWN:	//Ű���� �޽���
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