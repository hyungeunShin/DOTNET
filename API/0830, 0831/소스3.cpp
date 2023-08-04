//윈도우 핸들을 이용한 윈도우 제어
/*
GUI 모듈 : 지역적(한번 쓰고 버린다)
           [펜을 생성 -> 사용 -> 펜을 제거]

UI 모듈  : 시스템 전역적 성질
           윈도우 핸들
*/

//시스템에서 생성된 윈도우 핸들 얻기
//HWND FindWindow("클래스명", "타이틀명(윈도우명)");  //주로 2번째 인자로 획득
#include <windows.h>
#include <stdio.h>

int main()
{
    HWND hwnd= FindWindow(0, TEXT("제목 없음 - Windows 메모장"));
    //HWND hwnd = FindWindow(0, TEXT("계산기"));
    if (hwnd == NULL)
    {
        printf("없다\n");
    }

    printf("핸들 : %d, 0x%x\n", (int)hwnd, (int)hwnd);

    TCHAR classname[100];
    GetClassName(hwnd, classname, _countof(classname)); //범용타입:sizeof -> countof

    printf("클래스명 : %ls\n", classname);

    RECT rc;
    GetWindowRect(hwnd, &rc);
    printf("윈도우 크기 : (%d,%d)~(%d,%d)\n", rc.left, rc.top, rc.right, rc.bottom);

	return 0;
}