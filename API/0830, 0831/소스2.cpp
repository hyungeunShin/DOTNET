//������ �����
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpCmdLine, int nShowCmd)
{
	//1. ������ Ŭ���� ����
	WNDCLASS	wc;
	//Ȯ�� ����(������ �ʿ����, ������ ���ؼ�)
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;

	//������ �⺻ ����(�ý��ۿ��� �����Ǵ� ����)
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //��, �귯��, ��Ʈ
	wc.hCursor = LoadCursor(0, IDC_ARROW);//�ý���
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = DefWindowProc;	 //�̸� ���� �����Ǵ� ���ν���(������ ���� ���)

	//�ش� ������ Ŭ���� KEY
	wc.lpszClassName = TEXT("First");

	//�߰� ����
	wc.lpszMenuName = 0;		//�޴� ���
	wc.style = 0;				//������ ��Ÿ��

	//2. ������Ʈ���� ���
	RegisterClass(&wc);

	//3. ������ �����(UI)
	HWND hwnd = CreateWindowEx(0,
		TEXT("FIRST"), TEXT("0830"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0, hInst, 0);
 
	//4. ������ ���
	ShowWindow(hwnd, SW_SHOW); //ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);		   //���߿� ����

	MessageBox(0, _TEXT("Hello,World!"), _TEXT("�˸�"), MB_OKCANCEL | MB_ICONQUESTION);
	return 0;
}
