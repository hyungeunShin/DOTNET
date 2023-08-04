//05_�ڵ���_����.cpp

/*
* ������
* 1) 05_�ڵ���_����.cpp�� ����
* 2) �����ؼ� ���� ���������� �̸��� child.exe ����
* 3) 04_�ڵ���_����.cpp �� ����
* 4) �����ؼ� ���� �������ϰ� ���� ��ο� child.exe�� �ִ´�.
* 5) 3������ ������ ���������� ����.
*/


#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv)   //child.exe 1000
{
	if (argc != 2) 
	{
		printf("�����α׷��� ���� �����ϸ� �ȵ˴ϴ�. �θ� ������ �ּ���\n");
		return 0;
	}
	
	//�θ� ������ pipe �ڵ��� ������.
	//�ڵ��� �ڽ��� �ڵ����̺� �ִ�.
	HANDLE hPipe = (HANDLE)atoi(argv[1]);

	char buf[4096];
	while (true) 
	{
		memset(buf, 0, sizeof(buf));
		DWORD len;

		/*
		* 1. �ڵ�
		* 2. ���� ������ �����ּ�
		* 3. ���� ������ ũ��
		* 4. ���� ���� ũ��(3 >= 4)
		* * ���� ���� ũ�⺸�� ū ���۸� �غ��Ѵ�.
		*/
		BOOL b = ReadFile(hPipe, buf, sizeof(buf), &len, 0);
		if (b == FALSE) 
			break;
		printf("%s\n", buf);
	}
	CloseHandle(hPipe);

	return 0;
}
