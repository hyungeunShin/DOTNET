//ColorDlgProc.cpp
/*
* OnInitDialog : 초기화
* ColorPrint : 수정한 정보를 부모의 전역변수에 저장하고 --> 부모에 메시지를 전송!
*/
#include "std.h"

static COLORDATA* pData = NULL;
extern HWND g_child;

HWND hRed, hGreen, hBlue;
int r, g, b;

void ColorPrint(HWND hDlg)
{
	HWND hstatic = GetDlgItem(hDlg, IDC_STATIC1);
	RECT rc;
	GetClientRect(hstatic, &rc);

	HDC hdc = GetDC(hstatic);	//스태틱 컨트롤에 출력할 수 있는 DC
	HBRUSH hbrush = CreateSolidBrush(RGB(r, g, b));

	FillRect(hdc, &rc, hbrush);

	DeleteObject(hbrush);
	ReleaseDC(hstatic, hdc);

	pData->r = r;
	pData->g = g;
	pData->b = b;
	pData->color = RGB(r, g, b);
	SendMessage(GetParent(hDlg), WM_APPLY, 0, 0);
}

BOOL color_OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	pData = (COLORDATA*)lParam;

	//스크롤바 핸들
	hRed = GetDlgItem(hDlg, IDC_SCROLLBAR1);
	hGreen = GetDlgItem(hDlg, IDC_SCROLLBAR2);
	hBlue = GetDlgItem(hDlg, IDC_SCROLLBAR3);

	//스크롤바 초기화
	SetScrollRange(hRed, SB_CTL, 0, 255, TRUE);
	SetScrollPos(hRed, SB_CTL, pData->r, TRUE);
	SetScrollRange(hGreen, SB_CTL, 0, 255, TRUE);
	SetScrollPos(hGreen, SB_CTL, pData->g, TRUE);
	SetScrollRange(hBlue, SB_CTL, 0, 255, TRUE);
	SetScrollPos(hBlue, SB_CTL, pData->b, TRUE);

	//에디트 컨트롤 초기화(스크롤바와 동기화)
	r = GetScrollPos(hRed, SB_CTL);
	g = GetScrollPos(hGreen, SB_CTL);
	b = GetScrollPos(hBlue, SB_CTL);

	SetDlgItemInt(hDlg, IDC_EDIT1, r, 0);
	SetDlgItemInt(hDlg, IDC_EDIT2, g, 0);
	SetDlgItemInt(hDlg, IDC_EDIT3, b, 0);	

	return TRUE;
}

BOOL color_OnHScroll(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	int TempPos;

	if ((HWND)lParam == hRed) TempPos = r;
	if ((HWND)lParam == hGreen) TempPos = g;
	if ((HWND)lParam == hBlue) TempPos = b;
	switch (LOWORD(wParam))
	{
	case SB_LINELEFT:
		TempPos = max(0, TempPos - 1);
		break;
	case SB_LINERIGHT:
		TempPos = min(255, TempPos + 1);
		break;
	case SB_PAGELEFT:
		TempPos = max(0, TempPos - 10);
		break;
	case SB_PAGERIGHT:
		TempPos = min(255, TempPos + 10);
		break;
	case SB_THUMBTRACK:
		TempPos = HIWORD(wParam);
		break;
	}
	if ((HWND)lParam == hRed)
	{
		r = TempPos;
		SetDlgItemInt(hDlg, IDC_EDIT1, r, 0);
	}
	if ((HWND)lParam == hGreen)
	{
		g = TempPos;
		SetDlgItemInt(hDlg, IDC_EDIT2, g, 0);
	}
	if ((HWND)lParam == hBlue)
	{
		b = TempPos;
		SetDlgItemInt(hDlg, IDC_EDIT3, b, 0);
	}
	SetScrollPos((HWND)lParam, SB_CTL, TempPos, TRUE);

	ColorPrint(hDlg);

	return TRUE;
}

BOOL color_OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if (LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(hDlg, IDCANCEL);
		g_child = NULL;
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_EDIT1)
	{
		if (HIWORD(wParam) == EN_CHANGE)
		{
			r = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
			SetScrollPos(hRed, SB_CTL, r, TRUE);
			ColorPrint(hDlg);
		}
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_EDIT2)
	{
		if (HIWORD(wParam) == EN_CHANGE)
		{
			g = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
			SetScrollPos(hGreen, SB_CTL, g, TRUE);
			ColorPrint(hDlg);
		}
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_EDIT3)
	{
		if (HIWORD(wParam) == EN_CHANGE)
		{
			b = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
			SetScrollPos(hBlue, SB_CTL, b, TRUE);
			ColorPrint(hDlg);
		}
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		//-----------------------------------------------------------------
		CHOOSECOLOR COL;
		static COLORREF crTemp[16];
		for (int i = 0; i < 16; i++) {
			crTemp[i] = RGB(0, 0, i * 8 + 128);
		}
		memset(&COL, 0, sizeof(CHOOSECOLOR));
		COL.lStructSize = sizeof(CHOOSECOLOR);
		COL.hwndOwner = hDlg;
		COL.lpCustColors = crTemp;
		//--------------------------------------------------------------------
		if (ChooseColor(&COL) != 0) {			//실행(모달)
			r = GetRValue(COL.rgbResult);
			g = GetGValue(COL.rgbResult);
			b = GetBValue(COL.rgbResult);
			//[r,g,b변수][스크롤바][에디트][하단색상출력static]
			SetScrollPos(hRed, SB_CTL, r, TRUE);
			SetScrollPos(hGreen, SB_CTL, g, TRUE);
			SetScrollPos(hBlue, SB_CTL, b, TRUE);
			SetDlgItemInt(hDlg, IDC_EDIT1, r, 0);
			SetDlgItemInt(hDlg, IDC_EDIT2, g, 0);
			SetDlgItemInt(hDlg, IDC_EDIT3, b, 0);
			ColorPrint(hDlg);
		}
		return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK ColorDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:		return color_OnCommand(hDlg, wParam, lParam);
	case WM_HSCROLL:		return color_OnHScroll(hDlg, wParam, lParam);
	case WM_INITDIALOG:		return color_OnInitDialog(hDlg, wParam, lParam);
	}
	return FALSE;
}