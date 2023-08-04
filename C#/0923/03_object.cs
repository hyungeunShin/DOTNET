using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
모든 타입들은 object의 자식이다.(암묵적) - OOP의 상속문법
class Object;

박싱(Boxing)
언박싱(unBoxing)
 */

namespace _0923_1
{
    class Class1
    {
        public static void Main(string[] args)
        {
            object obj = 3;

            int number = (int)obj;

            Console.WriteLine("{0}", number); // 3
        }
    }
}
