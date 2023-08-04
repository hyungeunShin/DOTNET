using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 배열은 참조 타입이다.
 * 1) 차원(Rank),  선언 시 , 로 구분된 개수
 *     int[] arr; 1차원   in[,] arr; 2차원
 * 2) 인덱스(Index)
 *     개별 값들을 찾아 갈 수 있는 정보
 * 3) 요소(Element)
 *     개별 값
 */ 
namespace _0923_1
{
    class Class1
    {
        #region 1차원배열
        static void Exam1_Print(int[] arr) //주소...
        {
            Console.WriteLine("RANK : {0}, LENGTH : {1}", arr.Rank, arr.Length);

            foreach (int i in arr)
                Console.Write("{0,3}", i);  //printf("%3d");
            Console.WriteLine();

            for (int i = 0; i < arr.Length; i++)
                Console.Write("{0,3}", arr[i]);
            Console.WriteLine();
        }

        static void Exam1()
        {
            int[] arr1 = new int[5];  //관리 힙에 저장, 모두 0으로 초기화 
            //2,3번은 동일한 코드
            int[] arr2 = new int[5] { 1, 2, 3, 4, 5 };
            int[] arr3 = { 1, 2, 3, 4, 5 };

            Exam1_Print(arr1);
            Exam1_Print(arr2);
            Exam1_Print(arr3);
        }
        #endregion

        #region 2차원배열
        static void Exam2_Print(int[,] arr) //주소...
        {
            Console.WriteLine("RANK : {0}, LENGTH : {1}", arr.Rank, arr.Length);

            foreach (int i in arr)
                Console.Write("{0,3}", i);  //printf("%3d");
            Console.WriteLine();

            for (int i = 0; i < arr.GetLength(0); i++)
                for(int j=0; j<arr.GetLength(1); j++)
                    Console.Write("{0,3}", arr[i,j]);
            Console.WriteLine();
        }

        static void Exam2()
        {
            int[,] arr1 = new int[2,3];  //관리 힙에 저장, 모두 0으로 초기화 
            //2,3번은 동일한 코드
            int[,] arr2 = new int[2,3] { { 1, 2, 3 }, { 4, 5, 6 } };
            int[,] arr3 = { { 1, 2, 3 }, { 4, 5, 6 } };

            Exam2_Print(arr1);
            Exam2_Print(arr2);
            Exam2_Print(arr3);
        }
        #endregion

        #region 가변배열(2차 이상 배열인데, 행마다 열의 크기가 다른 배열)
        static void Exam3_Print(int[][] arr) //주소...
        {
            //Length : 행의 개수
            Console.WriteLine("RANK : {0}, LENGTH : {1}", arr.Rank, arr.Length);

            foreach (int[] a in arr)
                foreach(int value in a)
                    Console.Write("{0,3}", value);  //printf("%3d");
            Console.WriteLine();

            for (int i = 0; i < arr.GetLength(0); i++)
                for (int j = 0; j < arr[i].Length; j++)  //<-----------------
                    Console.Write("{0,3}", arr[i][j]);
            Console.WriteLine();
        }

        static void Exam3()
        {
            int[][] arr1 = new int[3][];  //첫번째 new연산을 통해 행의 개수
            arr1[0] = new int[5];
            arr1[1] = new int[3];
            arr1[2] = new int[2] { 1, 2 };

            //2,3번은 동일한 코드
            int[][] arr2 = new int[3][] { new int[5], new int[3], new int[2] { 1, 2 } };

            Exam3_Print(arr1);
            Exam3_Print(arr2);
        }
        #endregion

        #region 배열 복사(Array 클래스에서 지원하는 Copy,  Buffer.BlockCopy )
        static void Exam4()
        {
            int[] arr = new int[5] { 1, 2, 3, 4, 5 };
            int[] arr1 = new int[5];

            //arr --> arr1 
            //직접 복사
            for (int i = 0; i < arr.Length; i++)
                arr1[i] = arr[i];

            //제공되는 함수 활용
            Array.Copy(arr, 0, arr1, 0, arr.Length);   //<------------------------
            Buffer.BlockCopy(arr, 0, arr1, 0, arr.Length);

            //결과 출력
            foreach(int value in arr1)
            {
                Console.Write("{0,3}", value);
            }
            Console.WriteLine();
        }

        #endregion

        #region 배열 정렬(Array 클래스에 Sort 메서드, 오름차순 정렬)
        static void Exam5()
        {
            int[] arr = new int[100];

            Random r = new Random();
            for (int i = 0; i < arr.Length; i++)
                arr[i] = r.Next(0, 9999); //0은 포함, 9999는 불포함

            foreach (int value in arr)
                Console.Write("{0,5}", value);
            Console.WriteLine();

            Array.Sort(arr);
            Console.WriteLine("\n정렬 후 결과");
            foreach (int value in arr)
                Console.Write("{0,5}", value);
            Console.WriteLine();

            Array.Reverse(arr);  //뒤집기
            Console.WriteLine("\n뒤집기 결과");
            foreach (int value in arr)
                Console.Write("{0,5}", value);
            Console.WriteLine();
        }
        #endregion 
        
        public static void Main(string[] args)
        {
            Exam5();
        }
    }
}
