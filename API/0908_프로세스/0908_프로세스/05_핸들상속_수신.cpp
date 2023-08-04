//05_핸들상속_수신.cpp

/*
* 실행방식
* 1) 05_핸들상속_수신.cpp를 빌드
* 2) 빌드해서 나온 실행파일의 이름을 child.exe 변경
* 3) 04_핸들상속_전송.cpp 를 빌드
* 4) 빌드해서 나온 실행파일과 동일 경로에 child.exe을 넣는다.
* 5) 3번에서 빌드한 실행파일을 실행.
*/


#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv)   //child.exe 1000
{
	if (argc != 2) 
	{
		printf("이프로그램은 직접 실행하면 안됩니다. 부모를 실행해 주세요\n");
		return 0;
	}
	
	//부모가 보내준 pipe 핸들을 꺼낸다.
	//핸들은 자신의 핸들테이블에 있다.
	HANDLE hPipe = (HANDLE)atoi(argv[1]);

	char buf[4096];
	while (true) 
	{
		memset(buf, 0, sizeof(buf));
		DWORD len;

		/*
		* 1. 핸들
		* 2. 받을 버퍼의 시작주소
		* 3. 받을 버퍼의 크기
		* 4. 실제 받은 크기(3 >= 4)
		* * 실제 받을 크기보다 큰 버퍼를 준비한다.
		*/
		BOOL b = ReadFile(hPipe, buf, sizeof(buf), &len, 0);
		if (b == FALSE) 
			break;
		printf("%s\n", buf);
	}
	CloseHandle(hPipe);

	return 0;
}
