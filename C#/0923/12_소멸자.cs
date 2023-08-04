using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 소멸자
 * ~클래스명();
 * 객체의 소멸은 GC가 한다. --> 언제 소멸자가 호출될지 모른다.(메모리 부족)
 * C# 소멸자(Destructor) 표현보다는 Finalizer라는 표현을 사용한다.
 * - 필요없이 소멸자를 만들면 안된다.
 * 
 * 생성자()
 * {
 *     file.Open();
    }
 * ~소멸자()
 * {
 *    file.Close();
 * }
 */ 
namespace _0923_1
{
    //객체 사용이 끝나면 null처리 하자..
    class Sample
    { 
        public Sample()         {            Console.WriteLine("생성자");        }
        ~Sample()               {            Console.WriteLine("소멸자");        }
    }

    //객체 소멸처리 코드 예제 
    // Dispose() 약속된 함수 : 비관리 리소스(파일, 소켓, DB)를 정리하는 함수
    class Sample1 : IDisposable
    {
        public Sample1()    { Console.WriteLine("생성자-파일을 OPEN"); }
        ~Sample1()          { Console.WriteLine("소멸자");  Close();  }

        private void Close()
        {
            Console.WriteLine("파일을 Close()");
        }

        public void Dispose()   //약속된 함수
        {
            Console.WriteLine("Dispose 호출");
            Close();

            GC.SuppressFinalize(this);  //더 이상 소멸자를 부르지 말라.
        }
    }


    class Class1
    {
        static void Exam1()
        {
            Sample s = new Sample();
            s = null;               //가비지 컬렉터 동작시 소멸자 호출...
            //delete s;
            //아래 코드를 직접 사용할 일은 없다.
            GC.Collect();                   //가비지 컬렉터 수행하는 코드(힙메모리전체를스캔)
            GC.WaitForPendingFinalizers();  //가비지 컬렉터 수행 완료시 까지 기다림.

            Console.WriteLine("프로그램 종료");
        }
        
        static void Exam2()
        {
            //Sample1 객체를 더 이상 사용하지 않겠다... Dispose를 호출하면 된다.
            //실수로 Dispose를 호출 안했다.--> 어쩔수없이 소멸자에서 비관리자원 Close하게 된다.
            Sample1 s1 = new Sample1();
            //사용
            s1.Dispose();  // GC 호출시 소멸자 호출 X
        }

        //Dispose
        static void Exam3()
        {
            //이 객체를 이 범위안에서 사용할래...
            using ( Sample1 s1 = new Sample1())  // IDisposable을 상속!
            {
                //사용..
            } //끝날때 자동으로 Dispose 호출
        }
        
        public static void Main(string[] args)
        {
            Exam3();
        }
    }
}
