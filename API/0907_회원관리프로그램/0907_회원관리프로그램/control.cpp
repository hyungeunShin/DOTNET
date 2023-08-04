//control.cpp

#include "std.h"

vector<MEMBER> g_memberlist;

void con_Init(HWND hDlg)
{
	mainui_ListViewColumeHeader(hDlg);
}

//INSERT
void con_NewMember(HWND hDlg)
{
	MEMBER data = { 0 };

	UINT ret = DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2),
		hDlg, NewMemberDlgProc, (LPARAM)&data);
	if (ret == IDOK)
	{
		g_memberlist.push_back(data);
		//MessageBox(hDlg, TEXT("저장 성공"), TEXT("알림"), MB_OK);
		//mainui_ListViewPrintAll(hDlg, g_memberlist);
		mainui_ListViewMemberPrint(hDlg, g_memberlist.size() - 1, data);
		mainui_StaticCountPrint(hDlg, g_memberlist.size());
	}
}

//DELETE
void con_DeleteMember(HWND hDlg)
{
	TCHAR name[20];
	GetDlgItemText(hDlg, IDC_EDIT1, name, _countof(name));

	for (int i = 0; i < (int)g_memberlist.size(); i++)
	{
		MEMBER mem = g_memberlist[i];
		if (_tcscmp(name, mem.name) == 0)
		{
			g_memberlist.erase(g_memberlist.begin() + i); //vecotr 컨테이너 삭제 코드
			mainui_ListViewPrintAll(hDlg, g_memberlist);
			mainui_StaticCountPrint(hDlg, g_memberlist.size());
			return;
		}
	}
}
