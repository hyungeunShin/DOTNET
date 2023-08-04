using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923_1
{
    class Class1
    {
        //기본값 
        static void Foo(int x, int y = 5, int z = 7)
        {
            Console.WriteLine("{0}, {1}, {2}", x, y, z);
        }

        public static void Main(string[] args)
        {
            Foo(10, 20, 30);    //10,20,30
            Foo(10, 20);        //10,20,7
            Foo(10);            //10,5,7
            //-------------------------------------------
            //Named 파라미터 
            Foo(10, z:20);      // 10, 5, 20
            Foo(z: 30, x: 10);  // 10, 5, 30
        }
    }
}
