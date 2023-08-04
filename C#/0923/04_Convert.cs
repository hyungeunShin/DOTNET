using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
Convert 클래스
- 기본 데이터 형식을 변환하기 위해서 제공되는 클래스
- 정적 메서드로 제공.(클래스 맴버)
  CTS타입들 : ToInt32(), Boolean, Char, DateTime, Double, Decimal...
https://docs.microsoft.com/ko-kr/dotnet/api/system.convert?redirectedfrom=MSDN&view=net-5.0
 */

namespace _0923_1
{
    class Class2
    {
        public static void Main(string[] args)
        {
            string numberString = "123";
            bool isnumber = true;

            //모든 타입들 -> int 
            int number = Convert.ToInt32(numberString);
            int bnumber = Convert.ToInt32(isnumber);

            //문자열 -> int 
            int number1 = int.Parse(numberString);
        }
    }
}
