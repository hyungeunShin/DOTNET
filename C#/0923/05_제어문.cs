using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 제어문
 * 1) 분기문 
 * (if, else if, else) 기존 C언어와 동일
 * (switch) : 변경처리 <-------------------------------
 * (goto) : 기존 C언어와 동일
 * 2) 반복문
 * while, do~while : 기존 C언어와 동일
 * for : 기존 C언어와 동일(배열, 컬렉션 부분 순회 가능)
 * foreach : 새로 추가 : 배열, 컬렉션 전체 순회 <----------------------------------
 */ 
namespace _0923_1
{
    class Class1
    {
        enum myMenu { None, Insert, Select, Update, Delete, Exit };

        //if else if else
        static void Exam1()
        {
            while(true)
            {
                Console.Clear();        //system("cls");
                Console.WriteLine("-----------------------------------------------------------");
                Console.WriteLine("[F1] Insert [F2] Select [F3] Update [F4] Delete [F5] Exit");
                Console.WriteLine("-----------------------------------------------------------");
                ConsoleKeyInfo info =  Console.ReadKey();
                if (info.Key == ConsoleKey.F1)
                    Console.WriteLine("Insert");
                else if (info.Key == ConsoleKey.F2)
                    Console.WriteLine("Select");
                else if (info.Key == ConsoleKey.F3)
                    Console.WriteLine("Update");
                else if (info.Key == ConsoleKey.F4)
                    Console.WriteLine("Delete");
                else if (info.Key == ConsoleKey.F5)
                    return;
                else
                    Console.WriteLine("잘못 입력하셨습니다.");
                //system("pause")
                Console.WriteLine("\n아무키나 누르세요");
                Console.ReadKey();
            }
        }

        //switch
        //C언어 : 비교값이 정수(int, char)
        //C#언어 :  int,char, string...(실수를 제외한 모든 타입이 가능)
        static void Exam2()
        {
            while (true)
            {
                Console.Clear();        //system("cls");
                Console.WriteLine("-----------------------------------------------------------");
                Console.WriteLine("[F1] Insert [F2] Select [F3] Update [F4] Delete [ESC] Exit");
                Console.WriteLine("-----------------------------------------------------------");
                ConsoleKeyInfo info = Console.ReadKey();
                switch(info.Key)
                {
                    case ConsoleKey.F1: Console.WriteLine("Insert"); break;
                    case ConsoleKey.F2: Console.WriteLine("Select"); break;
                    case ConsoleKey.F3: Console.WriteLine("Update"); break;
                    case ConsoleKey.F4: Console.WriteLine("Delete"); break;
                    case ConsoleKey.Escape: return;
                    default: Console.WriteLine("잘못 입력하셨습니다."); break;
                }                
                //system("pause")
                Console.WriteLine("\n아무키나 누르세요");
                Console.ReadKey();
            }
        }

        static void Exam3()
        {
            while (true)
            {
                Console.Clear();        //system("cls");
                Console.WriteLine("-----------------------------------------------------------");
                Console.WriteLine("[명령어]");
                Console.WriteLine("insert, select, update, delete, exit");
                Console.WriteLine("-----------------------------------------------------------");
                switch (Console.ReadLine())
                {
                    case "insert": Console.WriteLine("Insert"); break;
                    case "select": Console.WriteLine("Select"); break;
                    case "update": Console.WriteLine("Update"); break;
                    case "delete": Console.WriteLine("Delete"); break;
                    case "exit": return;
                    default: Console.WriteLine("잘못 입력하셨습니다."); break;
                }
                //system("pause")
                Console.WriteLine("\n아무키나 누르세요");
                Console.ReadKey();
            }
        }

        //goto, 가독성 저해된다. 따라서 사용 지양...
        static void Exam4()
        {
            int result = 0;

            for(int i=0; i<=10; i++)
            {          

                result += i;

                if (i == 5)
                    goto Jump;  //Jump 라벨로 이동
            }
            Console.WriteLine("for문 결과 : {0}", result);

        Jump:
            Console.WriteLine("goto 결과 : {0}", result);
        }

        //for & foreach 배열(참조타입)
        static void Exam6()
        {
            int result = 0;
            int[] numbers = new int[10]; //배열은 참조타입

            for(int i=0; i< numbers.Length; i++)  //배열은 자신의 요소의 개수
            {
                numbers[i] = i + 1; 
            }

            foreach( int i in numbers) //시작~마지막
            {
                result += i;
            }

            Console.WriteLine("SUM = {0}", result);
        }

        //while & do~while
        static void Exam7()
        {
            int result = 0;
            int i = 1;
            int max = 10;
            while( i <= max)
            {
                result += i;
                i++;
            }
            Console.WriteLine("SUM = {0}", result);

            int result1 = 0;
            int i1 = 1;
            int max1 = 10;
            do
            {
                result1 += i1;
                i1++;
            } while (i1 <= max1);
            Console.WriteLine("SUM = {0}", result1);
        }

        //break  & continue;
        static void Exam8()
        {
            int result = 0;
            for(int i=1; i<=100; i++)
            {
                if (i > 10)
                    break;   //반복문 종료

                if (i % 2 == 0)
                    continue; // 현재 처리를 건너 띄고 다음 루프 실행 

                result += i;
            }
            Console.WriteLine("1~ 9사이의 값 중 홀수만 더하기 : {0}", result);
        }

        public static void Main(string[] args)
        {
            Exam8();
        }
    }
}
