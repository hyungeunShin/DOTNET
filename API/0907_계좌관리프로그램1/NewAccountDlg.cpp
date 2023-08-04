//NewAccountDlg.cpp

#include "std.h"

static ACCOUNT* pData = NULL;

BOOL modal_OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	pData = (ACCOUNT*)lParam;

	return TRUE;
}

BOOL modal_OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	
	case IDCANCEL1: EndDialog(hDlg, IDCANCEL1); return TRUE;
	case IDOK1:
	{
		//자신의 컨틀롤 정보 획득--> pData를 이용해 원본 데이터 변경!
		GetDlgItemText(hDlg, IDC_EDIT1, pData->account, _countof(pData->account));
		GetDlgItemText(hDlg, IDC_EDIT2, pData->name, _countof(pData->name));
		pData->balance = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
		
		GetLocalTime(&pData->date);

		EndDialog(hDlg, IDOK);
		return TRUE;
	}
	case IDCANCEL2: EndDialog(hDlg, IDCANCEL2); return TRUE;
	case IDOK2:
	{
		pData->balance = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
		GetLocalTime(&pData->date);
		EndDialog(hDlg, IDOK);
		return TRUE;
	}
	}
	return FALSE;
}

BOOL CALLBACK NewAccountDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return modal_OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return modal_OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;
}
