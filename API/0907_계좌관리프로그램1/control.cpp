//control.cpp

#include "std.h"

static ACCOUNT* pData = NULL;
vector<ACCOUNT> g_accountlist;

void con_Init(HWND hDlg)
{
	mainui_ListViewColumeHeader(hDlg);
}

//INSERT
void con_NewAccount(HWND hDlg)
{
	ACCOUNT data = { 0 };

	UINT ret = DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2),
		hDlg, NewAccountDlgProc, (LPARAM)&data);
	if (ret == IDOK)
	{
		g_accountlist.push_back(data);
		//MessageBox(hDlg, TEXT("���� ����"), TEXT("�˸�"), MB_OK);
		mainui_ListViewPrintAll(hDlg, g_accountlist);
		mainui_StaticCountPrint(hDlg, g_accountlist.size());
	}
}

//INPUT
void con_InputAccount(HWND hDlg)
{	
	ACCOUNT data;	//�Ա��� ���¹�ȣ, �Աݾ�

	UINT ret = DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG3),
		hDlg, InputAccountDlgProc, (LPARAM)&data);

	if (ret == IDOK)
	{
		for (int i = 0; i < (int)g_accountlist.size(); i++)
		{
			ACCOUNT acc = g_accountlist[i];
			
			if (_tcscmp(data.account, acc.account) == 0)
			{		
				g_accountlist[i].balance += data.balance;
				mainui_ListViewPrintAll(hDlg, g_accountlist);
				mainui_StaticCountPrint(hDlg, g_accountlist.size());
				return;
			}
		}
		MessageBox(hDlg, TEXT("���¾���"), TEXT("�˸�"), MB_OK);
	}
}

//OUTPUT
void con_OutputAccount(HWND hDlg)
{
	ACCOUNT data = { 0 };

	UINT ret = DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG4),
		hDlg, OutputAccountDlgProc, (LPARAM)&data);

	if (ret == IDOK)
	{
		for (int i = 0; i < (int)g_accountlist.size(); i++)
		{
			ACCOUNT acc = g_accountlist[i];

			if (_tcscmp(data.account, acc.account) == 0)
			{
				g_accountlist[i].balance -= data.balance;
				mainui_ListViewPrintAll(hDlg, g_accountlist);
				mainui_StaticCountPrint(hDlg, g_accountlist.size());
				return;
			}
		}
		MessageBox(hDlg, TEXT("���¾���"), TEXT("�˸�"), MB_OK);
	}
}

//DELETE
void con_DeleteAccount(HWND hDlg)
{
	TCHAR dAcc[20];
	GetDlgItemText(hDlg, IDC_EDIT1, dAcc, _countof(dAcc));

	for (int i = 0; i < (int)g_accountlist.size(); i++)
	{
		ACCOUNT acc = g_accountlist[i];
		if (_tcscmp(dAcc, acc.account) == 0)
		{
			g_accountlist.erase(g_accountlist.begin() + i);	//vector �����̳� ���� �ڵ�
			mainui_ListViewPrintAll(hDlg, g_accountlist);
			mainui_StaticCountPrint(hDlg, g_accountlist.size());
			return;
		}
	}
}