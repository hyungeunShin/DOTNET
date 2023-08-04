//04_�ڵ���.cpp
/*
* IPC(InterProcess Commnuication, �ϳ��� PC�� �ִ� ���� �ٸ� Process���� ���)
* ������ ����(�ڵ� 2�� ����)
* �ڵ� ���̺� �ִ� �ڵ� �� �ڽĿ��� ����� �ڵ��� ��� �����ϰ� ����
* �ڽ� ����
* 1) �ڵ����̺� �ִ� �ڵ� ����ϰڴٰ� ����
* 2) �ڽ��� ������ ����� ���ڷ� ����� �ڵ��� ���� ����
* -------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
//����� ����(���α׷� ���� �� �ܺο��� ���޵Ǵ� ����-���ڿ� ���·θ�..)
//�⺻������ �ڽ��� �������� full path ��ΰ� ���޵ȴ�.
//[�׽�Ʈ] ������Ʈ >> �Ӽ� : �����Ӽ� >>����� : ����μ� ( 111 aaa bbb 10.1 )
/*
int main(int argc, char**argv) //argcount, argvalue[���ڿ� ��...]
{
	for (int i = 0; i < argc; i++)
	{
		printf("[%d] %s\n", i, argv[i]);
	}
	return 0;
}
*/


int main(int argc, char** argv) //argcount, argvalue[���ڿ� ��...]
{
	if (argc != 4)
	{
		printf("���� ��� ��) ���α׷���.exe 10 + 2\n");
		return 0;
	}

	int num1 = atoi(argv[1]);		//"111" --> 111  #include <stdlib.h>
	char oper = argv[2][0];			//"+\0" --> '+'
	int num2 = atoi(argv[3]);		//"222" --> 222

	if (oper == '+')
		printf("%d + %d = %d\n", num1, num2, num1 + num2);
	else if (oper == '-')
		printf("%d - %d = %d\n", num1, num2, num1 - num2);

	return 0;
}



////������ �ڵ�
//#include <stdio.h>
//#include <windows.h>
//
//int main() 
//{
//	//1. ������ ���� �� �ڵ� ����
//	HANDLE hRead, hWrite;
//	CreatePipe(&hRead, &hWrite, 0, 4096);
//	// �б� ���� �ڵ��� ��� �����ϰ� �Ѵ�.
//	SetHandleInformation(hRead, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
//
//	//2. �ڽ� ����
//	TCHAR cmd[256];
//	wsprintf(cmd, TEXT("child.exe %d"), hRead); // ����� �������� ���
//	PROCESS_INFORMATION pi;
//	STARTUPINFO si = { sizeof(si) };
//	BOOL b = CreateProcess(0, cmd, 0, 0, TRUE, CREATE_NEW_CONSOLE,0, 0, &si, &pi);
//	if (b) 
//	{
//		//�Ⱦ����ϱ�....
//		CloseHandle(pi.hProcess);
//		CloseHandle(pi.hThread);
//		CloseHandle(hRead);
//	}
//	
//	//3. �޽ý� ����
//	char buf[4096];
//	while (true) 
//	{
//		printf("������ �޼����� �Է��ϼ��� >> ");
//		gets_s(buf, sizeof(buf));
//		if (strcmp(buf, "exit") == 0)
//			break;
//		DWORD len;
//
//		/*
//		* 1. �ڵ�
//		* 2. ���� ������ �����ּ�
//		* 3. ���� ũ��
//		* 4. ���� ���� ũ�� 
//		* * 3���� 4���� ���ϸ� ���ϴ� ũ�Ⱑ ���۵Ǿ����� Ȯ�� ����!
//		*/
//		WriteFile(hWrite, buf, strlen(buf) + 1, &len, 0);
//	}
//
//	return 0;
//}
