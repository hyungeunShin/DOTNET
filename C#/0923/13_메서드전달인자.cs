using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 메서드 전달 인자
 * 1) value  : 기본형 타입의 값 전달,   전달인자가 초기화(0)
 * 2) ref    : 기본형 타입의 주소 전달, 전달인자가 초기화(0), 값 변경이 선택적
 * 3) out    : 기본형 타입의 주소 전달, 전달인자가 초기화(X), 값 변경이 강제적
 * 4) params :C언어의 가변형인자(...)
 */ 

namespace _0923_1
{
    class Class1
    {
        static void Exam1(int number, ref int n1, out int n2)
        {
            number++;
            n1++;  //선택적
            n2 = 10; //강제적
        }
       
        static void Exam2(string msg, params object[] args)
        {
            Console.WriteLine(msg);
            foreach(var items in args)
            {
                Console.WriteLine(items + " ");
            }
        }

        static void Exam3(string msg, params int[] args)
        {
            Console.WriteLine(msg);
            foreach (var items in args)
            {
                Console.WriteLine(items + " ");
            }
        }

        public static void Main(string[] args)
        {
            int number = 0;
            int number1 = 10;
            int number2;
            Exam1(number, ref number1, out number2);

            Console.WriteLine("{0}, {1}, {2}", number, number1, number2);  // 0, 11,10


            Exam2("첫번째", 10);
            Exam2("두번째", 10, 20, 'a', 10.23);
            Exam3("세번째", new int[] { 1, 2, 3, 4, 5 });
        }
    }
}
