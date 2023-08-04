//mainui.h

#pragma once

//---리스트뷰의 기능
void mainui_ListViewColumeHeader(HWND hDlg);

void mainui_ListViewPrintAll(HWND hDlg, vector<ACCOUNT> memberlist);

//----스태틱 컨트롤 출력
void mainui_StaticCountPrint(HWND hDlg, int count);