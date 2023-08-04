using System;
using System.Runtime.Remoting.Messaging;
using System.Threading;

namespace _0928
{
    //비동기 연산 처리
    delegate int AddDelete(int n1, int n2);

    //콜백 처리
    delegate void GetResult(int result);                //1)

    class Add
    {
        //콜백 변수 선언
        private GetResult GetResult = null;             //2)

        //비동기 결과 획득
        void ResultFunc(IAsyncResult iar)
        {
            object obj = iar.AsyncState; //BeginInvoke의 마지막 전달 인자를 얻어옴

            AsyncResult ar = iar as AsyncResult;
            AddDelete dele = ar.AsyncDelegate as AddDelete;//대리자 개체 참조
            // Console.WriteLine("결과값 : " + dele.EndInvoke(iar));
            GetResult(dele.EndInvoke(iar));             //5)
        }

        //비동기 연산코드
        public void Cal(GetResult de, int n1, int n2)   //3)
        {
            GetResult = de; //콜백 등록.                //4)

            AddDelete del = InnerCal;
            del.BeginInvoke(n1, n2, ResultFunc, null);
        }
        public int InnerCal(int n1, int n2)
        {
            for (int i = 0; i < 20; i++)
                Thread.Sleep(500);      //using System.Threading;

            return n1 + n2;
        }      
    }
}
