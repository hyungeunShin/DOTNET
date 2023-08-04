using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1104_Service
{
    //서비스 객체
    class HelloWorldWCFService : IHelloWorld
    {
        public string SayHello()
        {
            return "Hello WCF World!";
        }
    }
}
