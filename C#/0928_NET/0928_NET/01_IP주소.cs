/*****************************************************************
 * [System.NET ]
 * 
 * IP 주소 관련 클래스 
 *  IPAddress  : IP주소를 나타내는 클래스 
 *  IPEndPoint : IP 주소와 포트로 네트웤 종단점 정보를 가져오는 클래스
 *  IPHostEntry :하나의 호스트에 대한 상세 정보를 제공하는 클래스 
 *****************************************************************/
using System;
using System.Net;
using System.Net.NetworkInformation;

class IPTest
{
    // IP 일반 설정 
    static void Exam1()
    {
        IPAddress ex1 = IPAddress.Parse("61.81.98.44");
        Console.WriteLine("{0} = {1}", "ex1", ex1);
    }

    //IPEndPoint
    //로컬 주소를 바인드 하거나 소켓과 원격 주소를 연결할 때 사용
    static void Exam2()
    { 
        //IPAddress ex = IPAddress.Parse("61.81.98.44");
        //IPEndPoint ie = new IPEndPoint(ex, 8000);
        IPEndPoint ie = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 8000);

        Console.WriteLine("AddressFamily : {0}", ie.AddressFamily);
        Console.WriteLine("Address       : {0}", ie.Address);
        Console.WriteLine("Port          : {0}", ie.Port);
        Console.WriteLine("MaxPort:{0}MinPort:{1}", IPEndPoint.MaxPort, IPEndPoint.MinPort);
        Console.WriteLine("ToString()    : {0}", ie.ToString());
    }

    static void Exam3()
    {
        Console.Write(" 주소를 입력 하세요 -> ");
        string str = Console.ReadLine();

        IPAddress[] host = Dns.GetHostAddresses(str);

        Console.WriteLine("호스트 이름: " + Dns.GetHostEntry(host[0]).HostName);
        Console.WriteLine(" 아이피 주소 리스트 :");

        for (int i = 0; i < host.Length; i++)
        {
            IPAddress ip = host[i];
            Console.WriteLine("[{0}]", ip.ToString());
        }
    }

    static void Exam4()
    {
        NetworkInterface[] adapters = NetworkInterface.GetAllNetworkInterfaces();
        foreach (NetworkInterface adapter in adapters)
        {
            IPInterfaceProperties adapterProperties = adapter.GetIPProperties();
            GatewayIPAddressInformationCollection Gatewayaddresses =
                    adapterProperties.GatewayAddresses;
            IPAddressCollection dhcpServers = adapterProperties.DhcpServerAddresses;
            IPAddressCollection dnsServers = adapterProperties.DnsAddresses;

            Console.WriteLine("네트워크 카드 : " + adapter.Description); // 네트워크 정보
            Console.WriteLine("  Physical Address ........... : " + adapter.GetPhysicalAddress());
            Console.WriteLine("  IP Address ................. : " + Get_MyIP());

            // Gateway 정보 출력
            if (Gatewayaddresses.Count > 0)
            {
                foreach (GatewayIPAddressInformation address in Gatewayaddresses)
                {
                    Console.WriteLine("  Gateway Address ............ : " + address.Address.ToString());
                }
            }
            // DHCP 정보 출력
            if (dhcpServers.Count > 0)
            {
                foreach (IPAddress dhcp in dhcpServers)
                {
                    Console.WriteLine("  DHCP Servers ............... : " + dhcp.ToString());
                }
            }
            // DNS 정보 출력
            if (dnsServers.Count > 0)
            {
                foreach (IPAddress dns in dnsServers)
                {
                    Console.WriteLine("  DNS Servers ................ : " + dns.ToString());
                }
            }
        }
    }
    // 자기 자신의 IP 정보 출력
    public static string Get_MyIP()
    {
        IPHostEntry host = Dns.GetHostEntry(Dns.GetHostName());
        string myip = host.AddressList[0].ToString();
        return myip;
    }

    static void Main()
    {
        Exam4();
    }
}

