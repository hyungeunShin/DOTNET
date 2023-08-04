using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 문자열
 * String & StringBuilder
 * - String 은 상수 문자열을 저장, 여기에 저장된 문자열은 변경이 불가능
 * - StringBuilder 는 수정할 수 있는 형태의 문자열이 저장
 * 일반적으로 String 타입을 많이 사용한다. 
 * ----------------------------------------------------------------------------
 * String
 * 유니코드(2byte)
 * 참조 형식 이지만 값형식 처럼 사용하는 기능을 지원!
 *   String str1 = new String("abc");
 *   String str2 = "abc";                  //<---(0)
 * 
 * 수정이 불가능하다.
 * String str3 = "abc";         //힙메모리에 "abc" 저장하는 공간을 생성, 주소를 반환
 * str3 = "abc"  + "def";       //다른 힙메모리에 "abcdef"를 저장하는 공간을 생성, 주소를 반환
 * Console.WriteLine(str3);   // abcdef 
 * 
 * https://docs.microsoft.com/ko-kr/dotnet/api/system.string?redirectedfrom=MSDN&view=net-5.0
 * 
 * 다양한 맴버 함수 : Length(프로퍼티), Format, Split, Substring, ToLower, ToUpper Trim, Replace
 */
namespace _0923_1
{
    class Class2
    {
        //포맷 지정
        //{위치번호,문자열정렬지정} ,   
        //{위치번호:문자열포맷}
        static void Exam1()
        {
            int number1 = 1;
            int number2 = 123;

            Console.WriteLine("number1 : {0,5}, number2 : {1:0000#}", number1, number2);
            Console.WriteLine("number1 : {0,-5}, number2 : {1:0000#}", number1, number2);
        }
       
        //숫자에 , 지정
        static void Exam2()
        {
            int number1 = 12345;
            int number2 = -12345;

            Console.WriteLine("number1 = {0:#,#;(#,#)}", number1);
            Console.WriteLine("number2 = {0}", number2.ToString("#,#;(#,#)"));
        }
        
        //특정 길이까지 남는 앞 부분을 0으로 채우기
        static void Exam3()
        {
            int number1 = 1;
            int number2 = 123;
            int number3 = 1234;

            Console.WriteLine("number1 : {0:00000}", number1);
            Console.WriteLine("number1 : {0:0000#}", number2);
            Console.WriteLine("number1 : {0}", number3.ToString("00000"));
        }

        //축약 문자열(@)
        static void Exam4()
        {
            string strPath1 = "c:\\windows\\System32";
            string strPath2 = @"c:\windows\System32";

            Console.WriteLine("{0}", strPath1);
            Console.WriteLine("{0}", strPath2);
        }

        //Split, Trim
        //직렬화 & 역직렬화
        static void Exam5()
        {
            //회원 객체 정보.
            Console.Write("이름 : ");      string name     = Console.ReadLine();
            Console.Write("나이 : ");      int age         = int.Parse(Console.ReadLine());
            Console.Write("몸무게 : ");    float weight    = float.Parse(Console.ReadLine());

            //직렬화
            string strInfo = name.Trim() + "@"+ age + "@"+ weight;
            Console.WriteLine("입력 정보 :" + strInfo);
            byte[] strInfobyte = Encoding.Default.GetBytes(strInfo);

            //byte배열(IO 전달 기본 타입)
            Console.WriteLine("입력 정보(byte[]) : " + strInfobyte);

            //-----------------------------------------------------------------
            //역직렬화
            string strInfo1 = Encoding.Default.GetString(strInfobyte);
            Console.WriteLine("역직렬화 정보 :" + strInfo1);

            //회원 객체 정보
            string[] filter = strInfo1.Split('@'); // 3등분.

            string name1 = filter[0];
            int age1 = int.Parse(filter[1]);
            float weight1 = float.Parse(filter[2]);

            Console.WriteLine("{0}, {1}, {2}", name1, age1, weight1);
        }

        //StringBuiler
        static void Exam6()
        {
            string text1 = "";

            //using System.Diagnostics;
            Stopwatch sw1 = Stopwatch.StartNew();
            for(int i=0; i<50000; i++)
            {
                text1 += i.ToString();  //문자열형태로 반환
            }
            sw1.Stop();

            StringBuilder text2 = new StringBuilder();
            Stopwatch sw2 = Stopwatch.StartNew();
            for (int i=0; i<50000; i++)
            {
                text2.Append(i.ToString());
            }
            sw2.Stop();

            Console.WriteLine("String           : {0} Millseconds", sw1.ElapsedMilliseconds);
            Console.WriteLine("StringBuilder    : {0} Millseconds", sw2.ElapsedMilliseconds);
        }

        public static void Main(string[] args)
        {
            Exam6();
        }
    }
}
