//13_1대다통신서버.cpp
//12_다중접속 가능한 서버
//11_클라이언트 송수신으로 TEST 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <process.h>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <vector>
using namespace std;

//통신 소켓
//1. 저장 : accept
//2. 삭제 : 통신 thread 종료시
//3. 사용 : recv 이후 
vector<SOCKET> g_socketlist;

void DisplayMessage()
{
    LPVOID pMsg; //void * pMsg;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | // 오류 메시지 저장 메모리를 내부에서 할당하라
        FORMAT_MESSAGE_FROM_SYSTEM, //운영체제로 부터 오류 메시지를 가져온다
        NULL,
        WSAGetLastError(), //오류 코드
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), //언어(제어판 설정 언어)
        (LPTSTR)&pMsg, // 오류 메시지 outparam
        0, NULL);

    printf("%s\n", (char*)pMsg);// 오류 메시지 출력

    LocalFree(pMsg); // 오류 메시지 저장 메모리 반환 
}

unsigned int __stdcall WorkThread(void* p)
{
    SOCKET ClientSocket = (SOCKET)p;
    char buf[100];

    while (1)
    {
        //3) recv
        int rev = recv(ClientSocket, buf, sizeof(buf), 0);
        if (rev == SOCKET_ERROR)
        {
            printf("소켓에 오류가 발생\n");
            break;
        }
        else if (rev == 0)
        {
            printf("상대방이 closesocket() 호출\n");
            break;
        }
        else
        {
            printf("수신 정보 : %dbyte, %s\n", rev, buf);
            //4) send - echo(메아리, 보낸 정보를 그대로 전송)
            //rev = send(ClientSocket, buf, rev, 0);      //<---------------
            //1대 다통신.
            for (int i = 0; i < (int)g_socketlist.size(); i++)
            {
                SOCKET s = g_socketlist[i];
                rev = send(s, buf, rev, 0);
            }
            printf("송신 정보 : %dbyte, %s\n", rev, buf);
        }
    }

    //제거-----------------------------------
    for (int i = 0; i < (int)g_socketlist.size(); i++)
    {
        SOCKET s = g_socketlist[i];
        if (s == ClientSocket)
        {
            g_socketlist.erase(g_socketlist.begin() + i);  //<----------
            break;
        }
    }

    //5) close
    closesocket(ClientSocket);

    return 0;
}

int main()
{
    //1. 초기화 
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("윈도우 소켓 초기화 실패!\n");
        return -1;
    }
    printf("윈도우 소켓 초기화 성공!\n");

    //2. socket() -> bind() -> listen()
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSocket == INVALID_SOCKET)
    {

        return -1;
    }

    SOCKADDR_IN ServerAddr = { 0 };
    ZeroMemory(&ServerAddr, sizeof(ServerAddr));    //Win32API
//  memset(&ServerAddr, 0, sizeof(ServerAddr));     //C Library
    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(9000);
    ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY);      //(ULONG)0x00000000 (정수)
    int retval = bind(listenSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
    if (retval == SOCKET_ERROR)
    {
        DisplayMessage();
        return -1;
    }

    retval = listen(listenSocket, SOMAXCONN); //0x7fffffff
    if (retval == SOCKET_ERROR)
        return -1;

    printf("대기 소켓의 초기화 과정 완료\n");

    while (1)
    {
        //1) 클라이언트의 접속 대기
        SOCKADDR_IN ClientAddr = { 0 };
        int clinetaddrsize = sizeof(ClientAddr);        //<----------
        SOCKET ClientSocket = accept(listenSocket, (SOCKADDR*)&ClientAddr, &clinetaddrsize);
        if (ClientSocket == INVALID_SOCKET)
            return -1;

        g_socketlist.push_back(ClientSocket);       //저장-----------------------

        //2) 클라이언트 접속 정보 출력
        printf("클라이언트 정보 : %s:%d\n", inet_ntoa(ClientAddr.sin_addr), ntohs(ClientAddr.sin_port));

        //#include <process.h>
        CloseHandle((HANDLE)_beginthreadex(0, 0, WorkThread, (void*)ClientSocket, 0, 0));
    }

    //2. 종료처리
    WSACleanup();
    return 0;
}
