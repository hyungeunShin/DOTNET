using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923_1
{
    enum Country { Korea, China, Japan}

    class C_Employee
    {
        //맴버 필드(외부 접근 허용 : public)
        public int BirthYear;
        public string Name; 
    }

    struct S_Employee
    {
        //맴버 필드(외부 접근 허용 : public)
        public int BirthYear;
        public string Name;
    }


    class Program
    {
        /// <summary>
        /// 기본형 타입 사용 예 
        /// 모든 형식은 사용되기 전 반드시 초기화 필요
        /// </summary>
        static void Exam1()
        {
            int number1 = 123;              //C#
            System.Int32 number2 = 123;     //CTS

            //formate
            Console.WriteLine("number1 : {0}\t number2 : {1}", number1, number2);

            //문자열 형태 출력
            //문자열 + 타입 ==> 문자열 + 문자열 => 통합문자열
            Console.WriteLine("number1 : " + number1 + "\t" + "number2 : " + number2);

            double number3 = 123;  //int가 암시적으로 double 형 변환 
            double number4 = 123D;
            Console.WriteLine("{0}, {1}", number3, number4);

           // int number5;  //쓰레기 
           // Console.WriteLine(number5); //모든 형식은 사용되기 전 반드시 초기화 필요
        }

        /// <summary>
        /// enum 타입(C#에서 상당히 많이 활용, 정해진 범위 내에서 사용)
        /// 타입 정의이기 때문에 class밖에서 정의
        /// </summary>
        static void Exam2()
        {
            Country location1 = Country.Korea;
            Country location2 = (Country)1;     //Country.Chinal;
            int location3 = (int)location1;     //0

            Console.WriteLine("location1 : {0}", location1);
            Console.WriteLine("location2 : {0}", location2);
            Console.WriteLine("location3 : {0}", location3);
            Console.WriteLine("location3 : {0}", (Country)location3);
        }

        /// <summary>
        /// 기본 입출력(Read, ReadLine, ReadKey:기능키)
        /// </summary>
        static void Exam3()
        {
            Console.WriteLine("뒤에 \n자동으로 추가");
            Console.Write("내가 직접\n");

            Console.Write("문자 하나를 입력 : ");
            int ch = Console.Read();
            Console.WriteLine("문자 : {0}, 숫자 : {1}", (char)ch, ch); //유니코드 
            Console.ReadLine();     //개행 문자를 획득해 버림...

            Console.Write("ReadLine 함수를 이용한 문자열 입력 : ");
            string str = Console.ReadLine();
            Console.WriteLine("문자열 : {0}", str);

            Console.Write("ReadKey를 이용한 정보 입력 : ");
            ConsoleKeyInfo info =  Console.ReadKey();  //_getch()
            if( info.Key == ConsoleKey.F1 )
            {
                Console.WriteLine("F1");
            }
        }

        /// <summary>
        /// 기본형 타입에 대한 입력처리( string ReadLine())
        /// </summary>
        static void Exam4()
        {
            string name, temp;
            int age;
            float weight; 
            char gender;

            Console.Write("이름 : ");
            name = Console.ReadLine();

            Console.Write("나이 : ");
            temp = Console.ReadLine();
            age = int.Parse(temp);

            Console.Write("몸무게 : ");
            weight = float.Parse(Console.ReadLine());

            Console.Write("성별(남/여) : ");
            gender = char.Parse(Console.ReadLine());

            Console.WriteLine("{0}, {1}, {2}, {3}", name, age, weight, gender);
        }

        /// <summary>
        /// Nullable 형식 
        /// 기본형 타입은 null을 저장할 수 없다. 
        /// int age = -1;  //값이 저장되어 있다. 
        /// 기본형타입에 ?를 붙히면 nullable 형식이 된다. 
        /// - System.Nullbale<T> 구조체 형식이 된다.
        ///   HasValue  속성 : null이면 false, 값이 저장되어 있으면 true
        ///   Value 속성     :값이 있으면 값을 반환, null이면 출력이 없음.
        /// </summary>
        static void Exam5()
        {
            int? number1 = null;
            int? number2 = 10;

            if (number1.HasValue)
                Console.WriteLine("{0}, {1}", number1, number1.Value);
            else
                Console.WriteLine("값이 저장되지 않았다");

            if (number2.HasValue)
                Console.WriteLine("{0}, {1}", number2, number2.Value);
            else
                Console.WriteLine("값이 저장되지 않았다");

            number2 = null;
            Console.WriteLine("number2의 값 : {0}", number2);
        }

        /// <summary>
        /// ?? 연산자 
        /// nullable 타입이 실제 null과 관계없이 연산 구문을 쉽게 작성하기 위한 용도.
        /// </summary>
        static void Exam6()
        {
            int? number = null;

            int result1 = ((number ==null) ? 0 :(int)number) *
                                ((number == null) ? 0 : (int)number);
            Console.WriteLine(result1);

            int result2 = (number ?? 0) * (number ?? 0);
            Console.WriteLine(result2);
        }

        /// <summary>
        /// 참조 형식(클래스타입)
        /// -상단에 간단한 클래스 정의(Employee)
        /// </summary>
        static void Exam7()
        {
            C_Employee emp1;            // 주소를 저장할 공간 
            emp1 = new C_Employee();    // 관리힙에 C_Employee객체가 생성 됨(저장공간 생성)
            emp1.BirthYear = 2021;
            emp1.Name = "홍길동";           

            C_Employee emp2 = emp1;     // emp1이 갖고 있는 주소를 저장
            Console.WriteLine("{0}, {1}", emp1.BirthYear, emp1.Name);  //2021, 홍길동
            Console.WriteLine("{0}, {1}", emp2.BirthYear, emp2.Name);  //2021, 홍길동

            emp1.Name = "허길동";
            Console.WriteLine("{0}, {1}", emp1.BirthYear, emp1.Name);  //2021, 허길동
            Console.WriteLine("{0}, {1}", emp2.BirthYear, emp2.Name);  //2021, 허길동
        }

        /// <summary>
        /// 값 형식(구조체 타입)
        /// -상단에 간단한 클래스 정의(Employee)
        /// S_Employee  emp1;                     //스택에 생성
        /// S_Employee  emp2 = new S_Employee();  //스택에 생성
        /// </summary>
        static void Exam8()
        {
            S_Employee emp1;            // 스택 저장 공간 생성 
            emp1.BirthYear = 2021;
            emp1.Name = "홍길동";

            S_Employee emp2 = new S_Employee();     // 스택에 저장공간 생성
            emp2 = emp1;
            Console.WriteLine("{0}, {1}", emp1.BirthYear, emp1.Name);  //2021, 홍길동
            Console.WriteLine("{0}, {1}", emp2.BirthYear, emp2.Name);  //2021, 홍길동

            emp1.Name = "허길동";
            Console.WriteLine("{0}, {1}", emp1.BirthYear, emp1.Name);  //2021, 허길동
            Console.WriteLine("{0}, {1}", emp2.BirthYear, emp2.Name);  //2021, 홍길동
        }

        /// <summary>
        /// 변수 선언 방법
        /// 1) 명시적 형식 사용
        /// 2) var 형식
        /// 3) dynamic 형식
        /// </summary>
        static void Exam9()
        {
            int number1 = 10;

            //컴파일 시점에서 형식이 정해진다.
            //var --> int 
            var number2 = 10.123;

            //런타임 시점에서 형식이 정해진다.
            //컴파일시에는 형식이 정해지지 않는다.
            dynamic number3 = 10;
        }

        /// <summary>
        /// 상수 
        /// const     : const int MAX = 10;, 클래스 맴버 필드로 사용시 옆 형태로만 사용 가능.
        /// readonly  : 클래스의 맴버 필드로만 사용 가능하다.(생성자를 통해 초기화 가능)
        /// </summary>
        static void Exam10()
        {
            const int MAX = 10;      //생성과 동시에 초기화를 통해 상수
            //readonly int MAX = 20; //지역변수로 사용 불가
        }

        static void Main(string[] args)
        {
            Exam9();

            Console.ReadKey();
        }
    }
}
