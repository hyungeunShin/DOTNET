//data.h
#pragma once

typedef struct tagCOLORDATA
{
	int r;
	int b;
	int g; 
	COLORREF color;
}COLORDATA;

//�ڽ��� �θ𿡰� ���� ��û�ϴ� ����� ���� �޽���
#define WM_APPLY	WM_USER + 100
