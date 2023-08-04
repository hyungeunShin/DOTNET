//리스트 뷰 기능
#include "std.h"
HWND hListView;

void accountui_ListViewColumeHeader(HWND hDlg)
{
	hListView = GetDlgItem(hDlg, IDC_LIST3);
	LVCOLUMN COL;
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("계좌번호");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(hListView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("이름");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(hListView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("잔액");				// 세 번째 헤더
	COL.iSubItem = 2;
	SendMessage(hListView, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("개설 날짜");				// 네 번째 헤더
	COL.iSubItem = 3;
	SendMessage(hListView, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPTSTR)TEXT("개설 시간 ");				// 다섯 번째 헤더
	COL.iSubItem = 4;
	SendMessage(hListView, LVM_INSERTCOLUMN, 4, (LPARAM)&COL);
	//--test 
	//--test 
}


//
void accountui_ListViewPrintAll(HWND hDlg, vector<ACCOUNT> accountlist)
{

	SendMessage(hListView, LVM_DELETEALLITEMS, 0, 0);
	LVITEM LI;
	LI.mask = LVIF_TEXT;
	TCHAR temp[50];
	for (int i = 0; i < (int)accountlist.size();i++)
	{

		ACCOUNT acc = accountlist[i];

		LI.iItem = i;
		LI.iSubItem = 0;
		wsprintf(temp, TEXT("%d"), acc.id);
		LI.pszText = (LPTSTR)temp;			// 첫 번째 아이템
		SendMessage(hListView, LVM_INSERTITEM, 0, (LPARAM)&LI);


		LI.iSubItem = 1;
		LI.pszText = (LPTSTR)acc.name;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);

		LI.iSubItem = 2;
		wsprintf(temp, TEXT("%d 원 "), acc.money);
		LI.pszText = (LPTSTR)temp;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);
		LI.iSubItem = 3;
		wsprintf(temp, TEXT("%04d-%02d-%02d "), acc.time.wYear, acc.time.wMonth, acc.time.wDay);

		LI.pszText = (LPTSTR)temp;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);
		LI.iSubItem = 4;
		wsprintf(temp, TEXT("%02d:%02d:%02d "),
			acc.time.wHour, acc.time.wMinute, acc.time.wSecond);
		
		LI.pszText = (LPTSTR)temp;
		SendMessage(hListView, LVM_SETITEM, 0, (LPARAM)&LI);
	}
}

// 스태틱 컨트롤
void accountui_StaticCountPrint(HWND hDlg, int count)
{
	TCHAR msg[50];
	wsprintf(msg, TEXT("저장개수 : %d 개"), count);
	SetDlgItemText(hDlg, IDC_STATIC1, msg);
}