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
	//����
	case IDCANCEL: EndDialog(hDlg, IDCANCEL); return TRUE;
	//�޴� - ����>>���α׷�����
	case ID_40001: EndDialog(hDlg, IDCANCEL); return TRUE;
	//�޴� - ȸ��������� >> ȸ������
	case ID_40002:		con_NewMember(hDlg);	 return TRUE;
	//��ư - �����޽���
	case IDC_BUTTON1:	con_DeleteMember(hDlg);	 return TRUE;
	}
	return FALSE;
}
