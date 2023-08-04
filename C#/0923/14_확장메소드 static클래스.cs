using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 확장 메소드
 * 이미 존재하는 클래스(클래스 변경 없이) 맴버에 메소드를 추가할 수 있는 문법
 */ 
namespace _0923_1
{
    //class 앞에 static 이 붙으면
    //1) 객체 생성 불가능한 클래스
    //2) 모든 맴버가 static
    static class ExtenstionMethod
    {
        //(this int number)
        //int 타입에 IsEven 메서드를 추가 
        public static bool IsEven(this int number)
        {
            bool isEven = (number % 2) == 0 ? true : false;
            return isEven;
        }

        public static bool PlusNumber(this float number)
        {
            if (number > 0.0f)
                return true;
            else
                return false;
        }
    }

    class Class2
    {
        public static void Main(string[] args)
        {
            int number = 3;
            Console.WriteLine("{0}", number.IsEven());

            float fnumber = -10.123f;
            Console.WriteLine("{0}", fnumber.PlusNumber());            

            if (number % 2 == 1)
                Console.WriteLine("홀수");
            else
                Console.WriteLine("짝수");
        }
    }
}
