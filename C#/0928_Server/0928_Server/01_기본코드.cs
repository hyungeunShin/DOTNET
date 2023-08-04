﻿/*****************************************************************
 * [System.NET ]
 * 
 * TCP Server
 *****************************************************************/
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class TcpServerExample
{
    static void Main(string[] args)
    {
        Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 7000);
        server.Bind(ipep);

        server.Listen(20);

        Console.WriteLine("서버 시작... 클라이언트 접속 대기중...");

        Socket client = server.Accept();  // 클라이언트 접속 대기

        // 접속한 클라이언트 아이피 주소와 접속 포트번호 출력
        IPEndPoint ip = (IPEndPoint)client.RemoteEndPoint;
        Console.WriteLine("{0}주소, {1}포트 접속", ip.Address, ip.Port);

        //-------------- 데이터 송수신(IO 기본 byte stream) --------------------
        byte[] data = Encoding.Default.GetBytes("환영합니다.*^^*");
        client.Send(data, data.Length, SocketFlags.None); // 문자열 전송

        data = new byte[1024];
        if (client.Receive(data) != 0)   // 수신한 문자열이 있으면 화면에 출력
            Console.WriteLine("수신 메시지: " + Encoding.Default.GetString(data));
        else
            Console.WriteLine("수신 데이터 없음...");

        client.Close();         //  소켓 연결 끊기
        server.Close();
    }
}




