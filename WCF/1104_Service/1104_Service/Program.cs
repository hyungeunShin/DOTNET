using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.ServiceModel.Description;
using System.Text;
using System.Threading.Tasks;

namespace _1104_Service
{
    class Program
    {
        //WSDL문서 공개
        // ServiceMetadataBehavior 설정
        // http://localhost/wcf/example/helloworldservice?wsdl  WSDL문서 획득
        static void ServiceMetadata(ServiceHost host)
        {   
            ServiceMetadataBehavior behavior =
                            host.Description.Behaviors.Find<ServiceMetadataBehavior>();
            if (behavior == null)
            {
                behavior = new ServiceMetadataBehavior();
                host.Description.Behaviors.Add(behavior);
            }
            behavior.HttpGetEnabled = true;
        }

        //Hosting(1개의 종점을 구성하고 호스팅)
        static void BasicHost()
        {
            //1) 서비스 객체정보
            //2) 주소 정보
            ServiceHost host = new ServiceHost(
                typeof(HelloWorldWCFService),
                new Uri("http://localhost/wcf/sample/helloworldserver"));

            //서비스호스트 객체에 EndPoint 구성
            host.AddServiceEndpoint(
                typeof(IHelloWorld),           //contract
                new BasicHttpBinding(),        //binding (XML WebService)
                "" );                          //address : host객체 생성시 전달된 주소

            //-------------------------------WSDL문서를 공개-------------------------
            //WSDL 공개할 주소 : host객체 생성자를 통해 전달된 주소가 해당 주소로 설정!!!!!
            ServiceMetadata(host);
            //----------------------------------------------------------------------

            //호스팅!
            host.Open();
            Console.WriteLine("Press Any Key to stop the Service");
            Console.ReadKey(true);
            host.Close();
        }

        //Hosting(2개의 종점을 구성하고 호스팅)
        static void BasicHost1()
        {
            ServiceHost host = new ServiceHost(
                typeof(HelloWorldWCFService),
                new Uri("http://localhost/wcf/example/helloworldservice"),  //WSDL 1
                new Uri("net.tcp://localhost/wcf/example/hellowordservice"));   //2

			host.AddServiceEndpoint(
                typeof(IHelloWorld),        // service contract
                new BasicHttpBinding(),     // service binding
                "");                        // relative address 1번주소

            host.AddServiceEndpoint(
                typeof(IHelloWorld),        // service contract
                new NetTcpBinding(),        // service binding
                "");                        // 2번 주소

            //-------------------------------WSDL문서를 공개-------------------------
            //WSDL 공개할 주소 : host객체 생성자를 통해 전달된 주소가 해당 주소로 설정!!!!!
            ServiceMetadata(host);
            //----------------------------------------------------------------------

            host.Open();
            Console.WriteLine("Press Any key to stop the service");
            Console.ReadKey(true);
            host.Close();

        }

        static void ConfigHost()
        {
            //EndPoint 구성없이 Open이 되면
            //config파일을 체크 서비스객체명과 동일한 정보가 등록되어 있다면
            //해당 Endpoint 정보를 host에 설정한다.
            ServiceHost host = new ServiceHost(typeof(HelloWorldWCFService));                     
 
            host.Open();
            Console.WriteLine("Press Any Key to stop the Service");
            Console.ReadKey(true);
            host.Close();
        }

        static void Main(string[] args)
        {
            ConfigHost();
        }
    }
}
