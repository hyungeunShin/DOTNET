using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * delegate
 * 1) 동기식   : 대부분 콜백 용도로 활용
 * 2) 비동기식 : 오래 걸리는 연산을 호출하는 용도로 활용
 */ 
namespace _0928
{

    class Class1
    {
        //연산이 오래 걸리기 때문에
        static void Exam1()
        {
            Add add = new Add();
            Console.WriteLine(add.InnerCal(10, 20));
        }

        //비동기 처리하겠다.
        static void Exam2()
        {
            Add add = new Add();

            add.Cal(Exam2_Result, 10, 20);
            Console.WriteLine("비동기 호출 후 바로 리턴");

            Console.ReadKey();
        }

        //콜백.
        static void Exam2_Result(int result)
        {
            Console.WriteLine("비동기 결과 : " + result);
        }

        public static void Main(String[] args)
        {
            Exam2();
        }
    }
}
