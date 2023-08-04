using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;

namespace _1104_Service
{
    [ServiceContract]     //서비스 계약[인터페이스에...] 
    public interface IHelloWorld
    {
        [OperationContract]   //메시지 계약
        string SayHello();
    }
}
