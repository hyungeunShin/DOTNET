using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1109_MemberService
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceHost host = new ServiceHost(typeof(MemberService));

            host.Open();
            Console.WriteLine("Press Any Key to stop the Service");
            Console.ReadKey(true);
            host.Close();
        }
    }
}
