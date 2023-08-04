using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;

namespace _1104_StudentService
{
    class Program
    {
        static void Main(string[] args)
        {
            ServiceHost host = new ServiceHost(typeof(StudentService));

            host.Open();
            Console.WriteLine("Press Any Key to stop the Service");
            Console.ReadKey(true);
            host.Close();
        }
    }
}
