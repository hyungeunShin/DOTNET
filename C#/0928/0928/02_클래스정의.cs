using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace _0928
{
    //1. delegate 정의(동기방식 예제)
    delegate void DelResult(int num);

    abstract class Operation        //추상클래스
    {
        //2. delegate 레퍼런스 변수 선언
        public DelResult GetResult = null;

        public int Num1 { get; set; }
        public int Num2 { get; set; }
        public int Result { get; protected set; }

        public Operation(int n1, int n2)
        {
            Num1 = n1;
            Num2 = n2;
        }

        public abstract int Cal1();                 //추상메서드
        public abstract void Cal2(DelResult d);    //추상메서드
    }

    class Add : Operation
    {
        public Add(int n1, int n2) : base(n1, n2) { }

        public override int Cal1()
        {
            for (int i = 0; i < 10; i++)
                Thread.Sleep(500);      //using System.Threading;

            return  Num1 + Num2;
        }

        public override void Cal2(DelResult d)
        {
            GetResult = d;      //등록
            
            Result = Num1 + Num2;

            //결과 생성
            GetResult(Result);  // del 호출
        }
    }

    class Sub : Operation
    {
        public Sub( int n1, int n2) : base(n1, n2) { }

        public override int Cal1()
        {
            return Num1 - Num2;
        }

        public override void Cal2(DelResult d)
        {
            GetResult = d;      //등록

            Result = Num1 - Num2;

            //결과 생성
            GetResult.Invoke(Result);  // del 호출
        }
    }
}
