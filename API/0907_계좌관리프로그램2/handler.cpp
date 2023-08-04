
#include "std.h"

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_init(hDlg);
	return TRUE;
}
BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{

	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
	case ID_40001 :EndDialog(hDlg, IDCANCEL); return TRUE;
	case ID_40002: con_insert(hDlg); return TRUE;
	case IDC_BUTTON1: con_delete(hDlg); return TRUE;
	case IDC_BUTTON3: con_moneyinsert(hDlg); return TRUE;
	case IDC_BUTTON2 : con_moneyout(hDlg); return TRUE;
		
	}
	return FALSE;
}
