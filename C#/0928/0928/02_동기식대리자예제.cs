using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0928
{
    class Class1
    {
        //일반적 객체 사용 코드
        static void Exam1()
        {
            Operation[] oper = new Operation[2];
            oper[0] = new Add(10, 20);
            oper[1] = new Sub(10, 20);

            //호출
            Console.WriteLine("Add : " + oper[0].Cal1());
            Console.WriteLine("Sub : " + oper[1].Cal1());
        }

        //delegate 사용예(Callback)
        static void Result(int result)
        {
            Console.WriteLine("결과 : " + result);
        }

        static void Exam2()
        {
            Add add = new Add(10, 20);   //3--del관련해서 callback 함수 등록
            add.Cal2(Result);

            Sub sub = new Sub(10, 20);  //3--del관련해서 callback 함수 등록
            sub.Cal2(Result);
        }

        public static void Main(String[] args)
        {
            Exam1();
        }
    }
}
