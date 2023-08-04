//handler.cpp

#include "std.h"

//�������� & ���->�ʱ�ȭ ����
/*
OnCreate : �ʱ�ȭ
OnKeyDown : Update(����)
OnLButtonDown: UPdate(����)
*/
SHAPE g_curShape;
vector<SHAPE> g_ShapeList;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM lParam)
{	
	g_curShape.pt.x = 0;
	g_curShape.pt.y = 0;
	g_curShape.color = RGB(255, 0, 0);
	g_curShape.type = SHAPE_RECT;

	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT OnKeyDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case 'R':	g_curShape.color = RGB(255, 0, 0); break;
	case 'G':	g_curShape.color = RGB(0, 255, 0); break;
	case 'B':	g_curShape.color = RGB(0, 0, 255); break;
	case 'D':	g_curShape.color = RGB(rand()%256, rand()%256, rand()%256); break;
	case '1':	g_curShape.type = SHAPE_RECT;		break;
	case '2':	g_curShape.type = SHAPE_ELLIPS;		break;
	case '3':	g_curShape.type = SHAPE_TRY;		break;
	}
	RECT rc = { 0,0, 200, 100 };
	InvalidateRect(hwnd, &rc, TRUE);

	return 0;
}

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	g_curShape.pt = { LOWORD(lParam), HIWORD(lParam) };

	//���͸� PtInRect
	RECT rc2 = { 0,0, 200, 150 };
	if (PtInRect(&rc2, g_curShape.pt) == TRUE)
		return 0;
	
	SHAPE sh = g_curShape; 
	g_ShapeList.push_back(sh);

	//�»��
	RECT rc1 = { 0,0, 200, 100 };
	InvalidateRect(hwnd, &rc1, TRUE);

	//�������
	RECT rc = { sh.pt.x - 25, sh.pt.y - 25, sh.pt.x + 25, sh.pt.y + 25 };
	InvalidateRect(hwnd, &rc, FALSE);
	UpdateWindow(hwnd);

	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	//1. ���� ���
	for (int i = 0; i < (int)g_ShapeList.size(); i++)
	{
		SHAPE sh = g_ShapeList[i];

		HBRUSH hbr = CreateSolidBrush(sh.color);
		HBRUSH oldbr = (HBRUSH)SelectObject(hdc, hbr);

		if( sh.type == SHAPE_RECT)
			Rectangle(hdc, sh.pt.x - 25, sh.pt.y - 25, sh.pt.x + 25, sh.pt.y + 25);
		else if(sh.type == SHAPE_ELLIPS)
			Ellipse(hdc, sh.pt.x - 25, sh.pt.y - 25, sh.pt.x + 25, sh.pt.y + 25);
		else if (sh.type == SHAPE_TRY)
		{
			POINT polygon[3] = { {sh.pt.x, sh.pt.y-25},{sh.pt.x-25,sh.pt.y+25},{sh.pt.x+25, sh.pt.y+25} };
			Polygon(hdc, polygon, 3);
		}

		DeleteObject(SelectObject(hdc, oldbr));
	}

	//2. ���� ���� ���
	TCHAR temp[100];
	wsprintf(temp, TEXT("��ǥ : %d, %d"), g_curShape.pt.x, g_curShape.pt.y);
	TextOut(hdc, 5, 5, temp, _tcslen(temp));

	if (g_curShape.type == SHAPE_RECT)
		wsprintf(temp, TEXT("Ÿ�� : �簢��"));
	else if(g_curShape.type == SHAPE_ELLIPS)
		wsprintf(temp, TEXT("Ÿ�� : Ÿ��"));
	else if (g_curShape.type == SHAPE_TRY)
		wsprintf(temp, TEXT("Ÿ�� : �ﰢ��"));
	TextOut(hdc, 5, 30, temp, _tcslen(temp));

	wsprintf(temp, TEXT("���� : %03d,%03d,%03d"),
		GetRValue(g_curShape.color), GetGValue(g_curShape.color), GetBValue(g_curShape.color));
	TextOut(hdc, 5, 55, temp, _tcslen(temp));

	wsprintf(temp, TEXT("���� : %d��"), g_ShapeList.size());
	TextOut(hdc, 5, 80, temp, _tcslen(temp));

	EndPaint(hwnd, &ps);
	return 0;
}