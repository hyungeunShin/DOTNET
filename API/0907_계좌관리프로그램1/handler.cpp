//handler.cpp

#include "std.h"

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	con_Init(hDlg);

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//종료
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
		//메뉴 - 파일>>프로그램종료
	case ID_40001: EndDialog(hDlg, IDCANCEL); return TRUE;
		//메뉴 - 계좌관리기능 >> 계좌생성
	case ID_40002:		con_NewAccount(hDlg);		return TRUE;
		//메뉴 - 계좌관리기능 >> 입금
	case ID_40003:		con_InputAccount(hDlg);		return TRUE;
		//메뉴 - 계좌관리기능 >> 출금
	case ID_40004:		con_OutputAccount(hDlg);	return TRUE;
		//버튼 - 통지메시지
	case IDC_BUTTON1:	con_DeleteAccount(hDlg);	return TRUE;
	}
	return FALSE;
}
