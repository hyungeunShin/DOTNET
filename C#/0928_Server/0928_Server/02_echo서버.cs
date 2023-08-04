/*****************************************************************
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
        Socket server = null;
        try
        {
            server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 7000);
            server.Bind(ipep);

            server.Listen(20);

            Console.WriteLine("서버 시작... 클라이언트 접속 대기중...");

            while (true)
            {
                Socket client = server.Accept();  // 클라이언트 접속 대기

                // 접속한 클라이언트 아이피 주소와 접속 포트번호 출력
                IPEndPoint ip = (IPEndPoint)client.RemoteEndPoint;
                Console.WriteLine("클라이언트 접속 {0}:{1}", ip.Address, ip.Port);

                //-------------- 데이터 송수신(IO 기본 byte stream) -------------------- 
                while (true)
                {
                    byte[] data = new byte[1024];                    
                    int retval = client.Receive(data);
                    string str = Encoding.Default.GetString(data).Trim('\0');
                    if (retval != 0)   // 수신한 문자열이 있으면 화면에 출력
                        Console.WriteLine("수신 메시지: " + str);
                    else
                        break;

                    client.Send(data, retval, SocketFlags.None); // 문자열 전송
                }
                Console.WriteLine("클라이언트 연결해제 {0}:{1}", ip.Address, ip.Port);
                client.Close();         //  소켓 연결 끊기
            }
        }
        catch(Exception ex)
        {
            Console.Write("에러 : " + ex.Message);
        }
        finally
        {            
            server.Close();
        }
    }
}

