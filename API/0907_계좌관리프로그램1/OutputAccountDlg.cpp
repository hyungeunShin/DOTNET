//OutputAccountDlg.cpp
#include "std.h"

static ACCOUNT* pData = NULL;

BOOL OutputAcc_OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	pData = (ACCOUNT*)lParam;

	return TRUE;
}

BOOL OutputAcc_OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
	case IDOK:
	{
		//�ڽ��� ��Ʋ�� ���� ȹ��--> pData�� �̿��� ���� ������ ����!
		GetDlgItemText(hDlg, IDC_EDIT1, pData->account, _countof(pData->account));
		pData->balance = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);

		EndDialog(hDlg, IDOK);
		return TRUE;
	}
	}
	return FALSE;
}

BOOL CALLBACK OutputAccountDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return OutputAcc_OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return OutputAcc_OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;
}