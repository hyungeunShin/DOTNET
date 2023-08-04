using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 구조화된 예외처리
 *  try ~ catch
 *  try ~ finally
 *  try ~ catch ~ finally
 *  
 *  - try     : 예외가 발생될 가능성이 있는 영역 
 *  - catch   : 유일하게 중첩이 가능하다.
 *              예외가 발생했을 때만 호출
 *  - finally : 예외 발생과 무관하게 항상 호출되는 영역
 */ 

namespace _0923_1
{
    class Class2
    {
        #region try~catch문 
        static void foo(string data)
        {
            try
            {
                int number = int.Parse(data);
                Console.WriteLine("number = {0}", number);
            }
            catch(FormatException ex)
            {
                Console.WriteLine("Format예외 처리 = {0}", ex.Message);
            }
            catch(ArgumentNullException ex)
            {
                Console.WriteLine("Null예외 처리 = {0}", ex.Message);
            }
            catch(Exception ex)     //예외클래스의 최상위 클래스(업케스팅)
            {
                Console.WriteLine("예외 처리 = {0}", ex.Message);
            }
            finally
            {
                Console.WriteLine("무조건 호출");
            }
        }

        static void Exam1()
        {
            foo("123");
            foo("ab123");
            foo(null);
        }
        #endregion


        #region throw
        static void ShowMessage(string msg)
        {
            if (msg == null)
                throw new Exception("null이 전달되었습니다.");
            Console.WriteLine("전달된 문자열 : " + msg);
        }

        static void Exam2()
        {
            try
            {
                ShowMessage("메시지 출력");
                ShowMessage(null);
            }
            catch( Exception ex)
            {
                Console.WriteLine("예외처리 : " + ex.Message);
            }
        }

        #endregion 

        public static void Main(string[] args)
        {
            Exam2();
        }
    }
}
