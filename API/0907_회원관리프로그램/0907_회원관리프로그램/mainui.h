//mainui.h
#pragma once


//--- ����Ʈ���� ���
void mainui_ListViewColumeHeader(HWND hDlg);

//��ü���
void mainui_ListViewPrintAll(HWND hDlg, vector<MEMBER> memberlist);

//���޵� ȸ���� ������ ���(����)
void mainui_ListViewMemberPrint(HWND hDLg, int i, MEMBER mem);

//----- ����ƽ ��Ʈ�� ���
void mainui_StaticCountPrint(HWND hDlg, int count);
