//skeleton �ڵ�
#pragma comment (linker, "/subsystem:windows")		// "/subsystem:console"

#include <Windows.h>
#include <tchar.h>

//WM_CLOSE : ���������츦 �����ϰ��� �Ҷ� �߻��ϴ� ���� �޽��� 
//           1) �����찡 �ı��� �ȴ�.DestroyWindow()
//           2) �����찡 ������� ��ť�޽����� �˸�  WM_DESTROY
// 
//WM_DESTROY : �ݵ�� �޽��� ������ ������Ѿ� �Ѵ�.

//���ν���[�޽��� ó��, �ݺ� ȣ��]
//CALLBACK : �̸� ����� ������ �ʿ��� �� ȣ��
//           �ڽ��� �޽���ť�� WM_QUIT�� �־��־�� �Ѵ�.
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:	//�ʱ�ȭ[ȣ����� : �����찡 �����ǰ� ���� ���̱� ��]
	{
		return 0;
	}
	case WM_DESTROY:	//����ó��[ȣ����� : �����찡 �ı��ǰ� ����]
	{
		PostQuitMessage(0);  //Post : �޽���ť�� �޽����� ������. QUIT : �޽��� ����:WM_QUIT
		return 0;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}


//�����Լ�[������ ����, �޽��� ����]
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
	wc.lpfnWndProc = WndProc;	 //�̸� ���� �����Ǵ� ���ν���(������ ���� ���)

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

	//---------------- �޽��� ���� ----------------------------
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))   //�ڽ��� AMQ���� �޽��� ��������..[����FLASE : WM_QUIT ]
	{
		//TranslateMessage(&msg);
		DispatchMessage(&msg);			//������ M�� �̸� ��ϵ� Proc ����.
	}
	//-------------------------------------------------------

	return 0;
}
