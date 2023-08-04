//https://docs.microsoft.com/ko-kr/windows/win32/psapi/enumerating-all-processes
#include <iostream>
using namespace std;
#include <Windows.h>
#include <tlhelp32.h>   // CreateToolhelp32Snapshot() 를 사용하기 위한 해더포함  

int main()
{   
    HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 pe32 = { 0 };
    pe32.dwSize = sizeof(PROCESSENTRY32);
    int count = 0;
    if (Process32First(hProcess, &pe32))
    {
        do
        {
            printf("[%03d] %s\t%d개\t%d\t%d\t%d\n", ++count,
                pe32.szExeFile, pe32.cntThreads, pe32.pcPriClassBase, 
                pe32.th32ParentProcessID, pe32.th32ProcessID );
        } while (Process32Next(hProcess, &pe32));
    }
    else
    {
        cout << "???" << endl;
    }

    CloseHandle(hProcess);

    return 0;
}

