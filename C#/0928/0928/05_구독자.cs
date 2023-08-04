using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
//구독자
//1) 이벤트 핸들러 함수를 정의
//2) 정의된 핸들러 함수를 이벤트에 등록
namespace _0928
{
    class Class4
    {
        private Operation op = new Operation();
        Class4()
        {
            //핸들러 함수 등록
            op.CalAdd += OnAddHandler;
            op.CalSub += OnSubHandler;
        }

        //핸들러 함수
        void OnAddHandler(object obj, CalEventArgs e)
        {
            Console.WriteLine("덧셈연산이 수행되었다.");
            Console.WriteLine("{0} {1} {2} = {3}",
                e.Number1, e.Oper, e.Number2, e.Result);
        }

        void OnSubHandler(object obj, CalEventArgs e)
        {
            Console.WriteLine("뺄셈연산이 수행되었다.");
            Console.WriteLine("{0} {1} {2} = {3}",
                e.Number1, e.Oper, e.Number2, e.Result);
        }

        //operation 함수 호출
        public void Run()
        {
            op.Add(10, 20);
            op.Sub(10, 20);
        }

        public static void Main(String[] args)
        {
            Class4 c = new Class4();
            c.Run();
        }
    }
}
