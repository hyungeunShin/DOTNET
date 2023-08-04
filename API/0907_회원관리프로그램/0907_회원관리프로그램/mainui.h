//mainui.h
#pragma once


//--- 리스트뷰의 기능
void mainui_ListViewColumeHeader(HWND hDlg);

//전체출력
void mainui_ListViewPrintAll(HWND hDlg, vector<MEMBER> memberlist);

//전달된 회윈의 정보만 출력(누적)
void mainui_ListViewMemberPrint(HWND hDLg, int i, MEMBER mem);

//----- 스태틱 컨트롤 출력
void mainui_StaticCountPrint(HWND hDlg, int count);
