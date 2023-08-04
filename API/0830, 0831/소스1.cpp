//UNICODE와 ANSI(DBMS)확인

#include <stdio.h>
#include <tchar.h>  //범용타입

#define TEXT(A)  "BB" ## A

int main()
{
	char ch1[] = "abc";   //"abc" ANSI
	printf("%s\n", ch1);

	wchar_t ch2[] = L"abc"; //L"abc" UNICODE
	printf("%ls\n", ch2);

	printf("%d, %d\n", sizeof(ch1), sizeof(ch2));  //4byte, 8byte

	TCHAR ch3[] = _TEXT("abc");

	printf("%s\n", TEXT("TEST"));

	return 0;
}