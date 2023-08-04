//유니코드 --> 멀티바이트로 변경
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <winsock2.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment( lib, "ws2_32.lib")

struct FILE_INFO
{
	char FileName[260];
	int  size;
};

FILE_INFO g_info;

void PrintData(int count)
{
	system("cls");
	printf("파일명 : %s\n\n", g_info.FileName);
	printf("파일크기 : %dbyte\n\n", g_info.size);	
	printf("전송량 : %dbyte\n", count);
}


DWORD WINAPI FileClient(void* p)
{
	HWND hwnd = (HWND)p;

	WSADATA w;
	WSAStartup(MAKEWORD(2, 2), &w);

	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(s, (SOCKADDR*)&addr, sizeof(addr)) == -1)
	{
		MessageBox(0, "Connect Error", "", MB_OK);
		return 0;
	}
	//------------------------------------------
	// 화일 정보를 수신한다.
	recv(s, (char*)&g_info, sizeof(g_info), 0);

	// 주스레드에 알려준다. ->주스레드가 UI를 Update 한다.!
	PrintData(0);

	//--------------------------------------------
	char name[260];
	strcpy_s(name, sizeof(name), g_info.FileName);

	HANDLE hFile = CreateFile(name, GENERIC_WRITE, FILE_SHARE_READ,
		0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	int total = g_info.size;
	int current = 0;
	char buf[4096];
	while (total > current)
	{
		int nRecv = recv(s, buf, 4096, 0);
		if (nRecv <= 0) break;

		DWORD len;
		WriteFile(hFile, buf, nRecv, &len, 0);

		current += nRecv;
		PrintData(current);
	}
	if (current != total) MessageBox(0, "Error", "", MB_OK);
	else                    MessageBox(0, "Success", "", MB_OK);
	closesocket(s);
	CloseHandle(hFile);
	WSACleanup();
	return 0;
}

int main()
{
	HANDLE hthread = CreateThread(0, 0, FileClient, 0, 0, 0);

	WaitForSingleObject(hthread, INFINITE);

	return 0;
}