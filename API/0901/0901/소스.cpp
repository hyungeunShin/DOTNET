//�׸����� & ���콺ĸó �ڵ�
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

POINT start, end;
BOOL  bNowDraw = FALSE;

//���׸��� 
/* 
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	start = end = { LOWORD(lParam), HIWORD(lParam) };
	bNowDraw = TRUE;

	return 0;
}

LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (bNowDraw)
	{
		HDC hdc = GetDC(hwnd);
		SetROP2(hdc, R2_NOT); //������� 1 ^1 = 0

		//����� ����
		MoveToEx(hdc, start.x, start.y, NULL);
		LineTo(hdc, end.x, end.y);

		//������ ��ǥ ����
		end.x = LOWORD(lParam);
		end.y = HIWORD(lParam);

		//�׸��� ����
		MoveToEx(hdc, start.x, start.y, NULL);
		LineTo(hdc, end.x, end.y);

		ReleaseDC(hwnd, hdc);
	}
	return 0;
}

LRESULT OnLButtonUp(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	bNowDraw = FALSE;
	HDC hdc = GetDC(hwnd);

	MoveToEx(hdc, start.x, start.y, NULL);
	LineTo(hdc, end.x, end.y);

	ReleaseDC(hwnd, hdc);
	return 0;
}
*/

//�簢�� �׸���
/*
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	start = end = { LOWORD(lParam), HIWORD(lParam) };
	bNowDraw = TRUE;

	return 0;
}

LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (bNowDraw)
	{
		HDC hdc = GetDC(hwnd);
		SetROP2(hdc, R2_NOT); //������� 1 ^1 = 0
		SelectObject(hdc, GetStockObject(NULL_BRUSH));

		//����� ����
		Rectangle(hdc, start.x, start.y, end.x, end.y);

		//������ ��ǥ ����
		end.x = LOWORD(lParam);
		end.y = HIWORD(lParam);

		//�׸��� ����
		Rectangle(hdc, start.x, start.y, end.x, end.y);

		ReleaseDC(hwnd, hdc);
	}
	return 0;
}

LRESULT OnLButtonUp(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	bNowDraw = FALSE;
	HDC hdc = GetDC(hwnd);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	Rectangle(hdc, start.x, start.y, end.x, end.y);

	ReleaseDC(hwnd, hdc);
	return 0;
}
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	start = end = { LOWORD(lParam), HIWORD(lParam) };
	bNowDraw = TRUE;

	return 0;
}

LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if (bNowDraw)
	{
		HDC hdc = GetDC(hwnd);
		SetROP2(hdc, R2_NOT); //������� 1 ^1 = 0
		SelectObject(hdc, GetStockObject(NULL_BRUSH));

		//����� ����
		Rectangle(hdc, start.x, start.y, end.x, end.y);

		//������ ��ǥ ����
		end.x = LOWORD(lParam);
		end.y = HIWORD(lParam);

		//�׸��� ����
		Rectangle(hdc, start.x, start.y, end.x, end.y);

		ReleaseDC(hwnd, hdc);
	}
	return 0;
}

LRESULT OnLButtonUp(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	bNowDraw = FALSE;
	HDC hdc = GetDC(hwnd);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	Rectangle(hdc, start.x, start.y, end.x, end.y);

	ReleaseDC(hwnd, hdc);
	return 0;
}
*/


//�簢�� �׸��� & ���콺 ĸó(LDown:ĸó����, LUp:ĸó�ݳ�)
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	start = end = { LOWORD(lParam), HIWORD(lParam) };
	SetCapture(hwnd); 

	return 0;
}

LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	if ( GetCapture() == hwnd)	//���� ���콺�� ĸ���ϰ� �ִ°�?
	{
		HDC hdc = GetDC(hwnd);
		SetROP2(hdc, R2_NOT); //������� 1 ^1 = 0
		SelectObject(hdc, GetStockObject(NULL_BRUSH));

		//����� ����
		Rectangle(hdc, start.x, start.y, end.x, end.y);

		//������ ��ǥ ����
		end.x = LOWORD(lParam);
		end.y = HIWORD(lParam);

		//�׸��� ����
		Rectangle(hdc, start.x, start.y, end.x, end.y);

		ReleaseDC(hwnd, hdc);
	}
	return 0;
}

LRESULT OnLButtonUp(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	ReleaseCapture();

	HDC hdc = GetDC(hwnd);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	Rectangle(hdc, start.x, start.y, end.x, end.y);

	ReleaseDC(hwnd, hdc);
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:	return OnLButtonDown(hwnd, wParam, lParam);
	case WM_MOUSEMOVE:		return OnMouseMove(hwnd, wParam, lParam);
	case WM_LBUTTONUP:		return OnLButtonUp(hwnd, wParam, lParam);

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