
#include "std.h" 
vector<ACCOUNT> account;

void con_init(HWND hDlg)
{
	accountui_ListViewColumeHeader(hDlg);
}


void con_insert(HWND hDlg)
{
	ACCOUNT data;
	UINT ret = DialogBoxParam(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG2),
		hDlg, NewMemberDlgProc, (LPARAM)&data);
	if (ret == IDOK)
	{
		for (int i = 0;i < (int)account.size();i++)
		{
			ACCOUNT acc = account[i];
			if (data.id == acc.id)
			{
				MessageBox(0, _TEXT("아이디가 이미 존재합니다."), _TEXT("알림"), MB_OKCANCEL | MB_ICONEXCLAMATION);
				return;
			}
			
		}
		if (_tcslen(data.name) > 0)
		{
			account.push_back(data);
			accountui_ListViewPrintAll(hDlg, account);
			accountui_StaticCountPrint(hDlg, (int)account.size());
		}
	}
}

void con_delete(HWND hDlg)
{
	int id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
	for (int i = 0;i < (int)account.size();i++)
	{
		ACCOUNT acc = account[i];
		if (id == acc.id)
		{

			account.erase(account.begin() + i);

			accountui_ListViewPrintAll(hDlg, account);
			accountui_StaticCountPrint(hDlg, account.size());
			SetDlgItemText(hDlg, IDC_EDIT1, TEXT(""));
			return;
		
			
		}
		
	}
	MessageBox(0, _TEXT("아이디가 일치하지 않습니다."), _TEXT("알림"), MB_OKCANCEL | MB_ICONEXCLAMATION);


}
void con_moneyinsert(HWND hDlg)
{
	int id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	int money = GetDlgItemInt(hDlg, IDC_EDIT4, 0, 0);
	for (int i = 0;i < (int)account.size();i++)
	{
		
		ACCOUNT acc = account[i];
		if (id == acc.id)
		{
			if (money <= 0)
			{
				MessageBox(0, _TEXT("입금액이 잘못되었습니다."), _TEXT("알림"), MB_OKCANCEL | MB_ICONEXCLAMATION);
				return;
			}
			else
			{
				acc.money += money;
				account[i] = acc;
				accountui_ListViewPrintAll(hDlg, account);
				SetDlgItemText(hDlg, IDC_EDIT2, TEXT(""));
				SetDlgItemText(hDlg, IDC_EDIT4, TEXT(""));
				return;
			}
			return;
		}
		else
		{
			MessageBox(0, _TEXT("아이디가 일치하지 않습니다."), _TEXT("알림"), MB_OKCANCEL | MB_ICONEXCLAMATION);
			return;
		}
	}
	return;
}

void  con_moneyout(HWND hDlg)
{
	int id = GetDlgItemInt(hDlg, IDC_EDIT2, 0, 0);
	int money = GetDlgItemInt(hDlg, IDC_EDIT4, 0, 0);
	for (int i = 0;i < (int)account.size();i++)
	{

		ACCOUNT acc = account[i];
		if (id == acc.id)
		{
			if (money > acc.money)
			{
				MessageBox(0, _TEXT("출금액이 현재 계좌 금액보다 많습니다."), _TEXT("알림"), MB_OKCANCEL | MB_ICONEXCLAMATION);
				return;
			}
			else
			{
				acc.money -= money;
				account[i] = acc;
				accountui_ListViewPrintAll(hDlg, account);
				SetDlgItemText(hDlg, IDC_EDIT2, TEXT(""));
				SetDlgItemText(hDlg, IDC_EDIT4, TEXT(""));
				return;
			}
			return;
		}
		else
		{
			MessageBox(0, _TEXT("아이디가 일치하지 않습니다."), _TEXT("알림"), MB_OKCANCEL | MB_ICONEXCLAMATION);
			SetDlgItemText(hDlg, IDC_EDIT2, TEXT(""));
			return;
		}
	}
	return;
}