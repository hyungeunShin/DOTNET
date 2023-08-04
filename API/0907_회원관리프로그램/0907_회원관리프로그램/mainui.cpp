//mainui.cpp

#include "std.h"

HWND hListView;

void mainui_ListViewColumeHeader(HWND hDlg)
{
	hListView = GetDlgItem(hDlg, IDC_LIST1);

	LVCOLUMN COL;

	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 50;
	COL.pszText = (LPTSTR)TEXT("ȸ����ȣ");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(hListView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("�̸�");			// �� ��° ���
	COL.iSubItem = 1;
	SendMessage(hListView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("��ȭ��ȣ");				// �� ��° ���
	COL.iSubItem = 2;
	SendMessage(hListView, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("��¥");				// �� ��° ���
	COL.iSubItem = 3;
	SendMessage(hListView, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("�ð�");				// �ټ� ��° ���
	COL.iSubItem = 4;
	SendMessage(hListView, LVM_INSERTCOLUMN, 4, (LPARAM)&COL);
}

void mainui_ListViewPrintAll(HWND hDlg, vector<MEMBER> memberlist)
{
	//���� ����Ʈ�信 ��µ� ������ ���� 
	SendMessage(hListView, LVM_DELETEALLITEMS, 0, 0);

	LVITEM LI;
	LI.mask = LVIF_TEXT;
	TCHAR temp[100];
	for (int i = 0; i < (int)memberlist.size(); i++)
	{
		MEMBER mem = memberlist[i];

		LI.iItem = i; //<-------
		LI.iSubItem = 0;
		wsprintf(temp, TEXT("%d"), mem.id);
		LI.pszText = (LPTSTR)temp;			// ù ��° ������
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 1;
		LI.pszText = (LPTSTR)mem.name;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 2;
		LI.pszText = (LPTSTR)mem.phone;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 3;
		wsprintf(temp, TEXT("%04d-%02d-%02d"), mem.date.wYear, mem.date.wMonth, mem.date.wDay);
		LI.pszText = (LPTSTR)temp;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 4;
		wsprintf(temp, TEXT("%02d:%02d:%02d"), mem.date.wHour, mem.date.wMinute, mem.date.wSecond);
		LI.pszText = (LPTSTR)temp;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);
	}
}

void mainui_ListViewMemberPrint(HWND hDlg, int i, MEMBER mem)
{
	LVITEM LI;
	LI.mask = LVIF_TEXT;
	TCHAR temp[100];

	LI.iItem = i; //<-------
	LI.iSubItem = 0;
	wsprintf(temp, TEXT("%d"), mem.id);
	LI.pszText = (LPTSTR)temp;			// ù ��° ������
	SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 1;
	LI.pszText = (LPTSTR)mem.name;
	SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 2;
	LI.pszText = (LPTSTR)mem.phone;
	SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 3;
	wsprintf(temp, TEXT("%04d-%02d-%02d"), mem.date.wYear, mem.date.wMonth, mem.date.wDay);
	LI.pszText = (LPTSTR)temp;
	SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 4;
	wsprintf(temp, TEXT("%02d:%02d:%02d"), mem.date.wHour, mem.date.wMinute, mem.date.wSecond);
	LI.pszText = (LPTSTR)temp;
	SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);
}

void mainui_StaticCountPrint(HWND hDlg, int count)
{	
	//���尳�� : 0��
	TCHAR msg[50];
	wsprintf(msg, TEXT("���尳�� : %d��"), count);
	SetDlgItemText(hDlg, IDC_STATIC1, msg);
}