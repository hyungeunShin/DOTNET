
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
	case IDOK:
	{
		//�ڽ��� ��Ʈ�� ����ȹ�� -> pData�� �̿��� ���� ������ ���� 
		(*pData).id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
		GetDlgItemText(hDlg, IDC_EDIT2, (*pData).name, _countof((*pData).name));
		(*pData).money = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
		
		GetLocalTime(&(*pData).time);

		EndDialog(hDlg, IDOK);
		return TRUE;

	}
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
	}
	return FALSE;
}


BOOL CALLBACK NewMemberDlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

		
	case WM_INITDIALOG: return modal_OnInitDialog(hDlg, wParam, lParam);

	case WM_COMMAND:return modal_OnCommand(hDlg, wParam, lParam);

		//�޽����� ó������ �ʾҴ�.-> �� ������ ��ȭ���� ó���ϴ� default���ν���
	}
	return FALSE;
}