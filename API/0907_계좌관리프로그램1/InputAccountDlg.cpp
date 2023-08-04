//InputAccountDlg.cpp

#include "std.h"

static ACCOUNT* pData = NULL;

BOOL InputAcc_OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	pData = (ACCOUNT*)lParam;

	return TRUE;
}

BOOL InputAcc_OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
	case IDOK:
	{
		//자신의 컨틀롤 정보 획득--> pData를 이용해 원본 데이터 변경!
		GetDlgItemText(hDlg, IDC_EDIT1, pData->account, _countof(pData->account));
		pData->balance = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);

		EndDialog(hDlg, IDOK);
		return TRUE;
	}	
	}
	return FALSE;
}

BOOL CALLBACK InputAccountDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return InputAcc_OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return InputAcc_OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;
}