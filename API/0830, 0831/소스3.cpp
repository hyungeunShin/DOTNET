//������ �ڵ��� �̿��� ������ ����
/*
GUI ��� : ������(�ѹ� ���� ������)
           [���� ���� -> ��� -> ���� ����]

UI ���  : �ý��� ������ ����
           ������ �ڵ�
*/

//�ý��ۿ��� ������ ������ �ڵ� ���
//HWND FindWindow("Ŭ������", "Ÿ��Ʋ��(�������)");  //�ַ� 2��° ���ڷ� ȹ��
#include <windows.h>
#include <stdio.h>

int main()
{
    HWND hwnd= FindWindow(0, TEXT("���� ���� - Windows �޸���"));
    //HWND hwnd = FindWindow(0, TEXT("����"));
    if (hwnd == NULL)
    {
        printf("����\n");
    }

    printf("�ڵ� : %d, 0x%x\n", (int)hwnd, (int)hwnd);

    TCHAR classname[100];
    GetClassName(hwnd, classname, _countof(classname)); //����Ÿ��:sizeof -> countof

    printf("Ŭ������ : %ls\n", classname);

    RECT rc;
    GetWindowRect(hwnd, &rc);
    printf("������ ũ�� : (%d,%d)~(%d,%d)\n", rc.left, rc.top, rc.right, rc.bottom);

	return 0;
}