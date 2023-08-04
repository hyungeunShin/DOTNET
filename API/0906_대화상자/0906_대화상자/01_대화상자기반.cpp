//01_��ȭ���ڱ��.cpp
/*
* skeleton �ڵ尡 �����.
* 1. ���ҽ��� ��ȭ���ڸ� ����
* 2. 1������ ���� ��ȭ������ �޽����� ó���� ���ν��� ����(�������� ���ν����ʹ� �ٸ���..)
* 3. WinMain������ 1������ ���� ��ȭ���ڸ� �����ϴ� �Լ� ȣ��
*    - �ش��Լ��� ��ȭ���ڰ� ����Ǳ� ������ ������ ����
*/
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"
#include <Windows.h>
#include <tchar.h>
#include "resource.h"

//���� ���� ����
#define IDC_EDIT11	1
HWND hEdit1;
HWND hEdit2; 

//���ҽ��� ������� ID�� resource.h ���Ͽ� �����Ǿ� �ִ�.
//�ڵ��� �ʿ��ϴٸ� ���;� �Ѵ�. GetDlgItem

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE hInst = GetModuleHandle(0);

	hEdit1 = CreateWindow(
		TEXT("edit"), NULL, WS_CHILD | WS_BORDER | WS_VISIBLE | ES_AUTOHSCROLL,//����
		20, 50, 200, 25, hDlg, (HMENU)IDC_EDIT11, hInst, 0);

	hEdit2 = GetDlgItem(hDlg, IDC_EDIT1); 

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	if(LOWORD(wParam) == IDCANCEL)
	{
		EndDialog(hDlg, IDCANCEL); 
		return TRUE;
	}
	else if (LOWORD(wParam) == IDC_BUTTON1)
	{
		TCHAR msg[100];
		GetDlgItemText(hDlg, IDC_EDIT11, msg, _countof(msg));
		SetDlgItemText(hDlg, IDC_EDIT1, msg);
	}
	return FALSE;		//<=====
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	//���� ȣ�� ����.
	case WM_INITDIALOG:		return OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND:		return OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;	//�޽����� ó������ �ʾҴ�.-> �� ������ ��ȭ���� ó���ϴ� default���ν���
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance
		MAKEINTRESOURCE(IDD_DIALOG1), // ���̾�α� ����
		0, // �θ� ������
		DlgProc); // Proc..


	return 0;
}