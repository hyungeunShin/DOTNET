﻿/*****************************************************************
 * [System.NET ]
 * 
 * TCP Client
 *****************************************************************/
using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class TcpClientExample
{
    static void Main(string[] args)
    {
        try
        {
            Socket server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            IPEndPoint ipep = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 7000);
            server.Connect(ipep);  // 127.0.0.1 서버 7000번 포트에 접속시도

            Console.WriteLine("서버에 접속...");  // 만약 서버 접속이 실패하면 예외 발생

            byte[] data = new byte[1024];
            server.Receive(data);

            Console.WriteLine("수신 데이터: " + Encoding.Default.GetString(data));

            server.Send(Encoding.Default.GetBytes("데이터 전송..."));

            server.Close();
        }
        catch (Exception ex)
        {
            Console.WriteLine("에러 : " + ex.Message);
        }
    }
}





