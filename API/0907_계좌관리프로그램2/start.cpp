
#pragma once
//01_��ȭ���ڱ��.cpp
/*
* skeleton �ڵ尡 �����.
* 1. ���ҽ��� ��ȭ���ڸ� ����
* 2. 1������ ���� ��ȭ������ �޽����� ó���� ���ν��� ����(�������� ���ν����ʹ� �ٸ���..)
* 3. WinMain������ 1������ ���� ��ȭ���ڸ� �����ϴ� �Լ� ȣ��
*    - �ش��Լ��� ��ȭ���ڰ� ����Ǳ� ������ ������ ����
*/

#include "std.h"


BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	case WM_INITDIALOG: return OnInitDialog(hDlg, wParam, lParam);
	case WM_COMMAND: return OnCommand(hDlg, wParam, lParam);
	}
	return FALSE;
}


int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,// instance
		MAKEINTRESOURCE(IDD_DIALOG1), // ���̾�α� ����
		0, // �θ� ������
		DlgProc); // Proc..


	return 0;
}