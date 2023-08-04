using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    static class MyLibrary
    {
        #region 콘솔 처리 기능
        public static void ConsoleClear()
        {
            Console.Clear();
        }

        public static void ConsolePause()
        {
            Console.WriteLine("\n아무 키나 누르세요");
            Console.ReadKey();
        }
        #endregion 

        #region 입력기능
        public static string InputString(string msg)
        {
            Console.Write(msg + " : ");
            return Console.ReadLine();
        }

        public static int InputInteger(string msg)
        {
            Console.Write(msg + " : ");
            return int.Parse(Console.ReadLine());
        }
        #endregion 
    }

}
