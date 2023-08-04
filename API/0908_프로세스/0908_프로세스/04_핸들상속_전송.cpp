//04_핸들상속.cpp
/*
* IPC(InterProcess Commnuication, 하나의 PC에 있는 서로 다른 Process끼리 통신)
* 파이프 생성(핸들 2개 생성)
* 핸들 테이블에 있는 핸들 중 자식에게 상속할 핸들을 상속 가능하게 수정
* 자식 생성
* 1) 핸들테이블에 있는 핸들 상속하겠다고 설정
* 2) 자식을 생성시 명령행 인자로 상속한 핸들의 값을 전달
* -------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
//명령행 인자(프로그램 실행 시 외부에서 전달되는 정보-문자열 형태로만..)
//기본적으로 자신의 실행파일 full path 경로가 전달된다.
//[테스트] 프로젝트 >> 속성 : 구성속성 >>디버깅 : 명령인수 ( 111 aaa bbb 10.1 )
/*
int main(int argc, char**argv) //argcount, argvalue[문자열 들...]
{
	for (int i = 0; i < argc; i++)
	{
		printf("[%d] %s\n", i, argv[i]);
	}
	return 0;
}
*/


int main(int argc, char** argv) //argcount, argvalue[문자열 들...]
{
	if (argc != 4)
	{
		printf("실행 방법 예) 프로그램명.exe 10 + 2\n");
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



////파이프 코드
//#include <stdio.h>
//#include <windows.h>
//
//int main() 
//{
//	//1. 파이프 생성 및 핸들 설정
//	HANDLE hRead, hWrite;
//	CreatePipe(&hRead, &hWrite, 0, 4096);
//	// 읽기 위한 핸들을 상속 가능하게 한다.
//	SetHandleInformation(hRead, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
//
//	//2. 자식 생성
//	TCHAR cmd[256];
//	wsprintf(cmd, TEXT("child.exe %d"), hRead); // 명령형 전달인자 사용
//	PROCESS_INFORMATION pi;
//	STARTUPINFO si = { sizeof(si) };
//	BOOL b = CreateProcess(0, cmd, 0, 0, TRUE, CREATE_NEW_CONSOLE,0, 0, &si, &pi);
//	if (b) 
//	{
//		//안쓸꺼니깐....
//		CloseHandle(pi.hProcess);
//		CloseHandle(pi.hThread);
//		CloseHandle(hRead);
//	}
//	
//	//3. 메시시 전송
//	char buf[4096];
//	while (true) 
//	{
//		printf("전달할 메세지를 입력하세요 >> ");
//		gets_s(buf, sizeof(buf));
//		if (strcmp(buf, "exit") == 0)
//			break;
//		DWORD len;
//
//		/*
//		* 1. 핸들
//		* 2. 보낼 버퍼의 시작주소
//		* 3. 보낼 크기
//		* 4. 실제 보낸 크기 
//		* * 3번과 4번을 비교하면 원하는 크기가 전송되었는지 확인 가능!
//		*/
//		WriteFile(hWrite, buf, strlen(buf) + 1, &len, 0);
//	}
//
//	return 0;
//}
