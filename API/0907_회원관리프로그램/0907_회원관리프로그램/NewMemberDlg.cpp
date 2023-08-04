//NewMemberDlg.cpp

#include "std.h"

static MEMBER* pData = NULL;

BOOL modal_OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	pData = (MEMBER*)lParam;

	return TRUE;
}

BOOL modal_OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
	case IDOK:
	{
		//자신의 컨틀롤 정보 획득--> pData를 이용해 원본 데이터 변경!
		pData->id	= GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
		GetDlgItemText(hDlg, IDC_EDIT2, pData->name, _countof(pData->name));
		GetDlgItemText(hDlg, IDC_EDIT3, pData->phone, _countof(pData->phone));
		GetLocalTime(&pData->date);

		EndDialog(hDlg, IDOK);
		return TRUE;
	}
	}
	return FALSE;
}

BOOL CALLBACK NewMemberDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return modal_OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return modal_OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;
}