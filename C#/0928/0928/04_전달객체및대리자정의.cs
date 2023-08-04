using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 산술연산 기능 구현
 * [게시자] 산술연산 클래스(덧셈, 뺄셈)
 * [구독자] 산술연산을 사용하는 클래스
 * 
 * - 이벤트 : 연산이 수행되면 연산에 사용되었던(피연산자2, 연산자, 결과값) 정보를 발생
 */ 
namespace _0928
{
    //0 : 델리게이트에 사용할 이벤트 전달인자 정의
    class CalEventArgs : EventArgs
    {
        public int Number1  { get; private set; }
        public int Number2  { get; private set; }
        public char Oper    { get; private set; }
        public int Result   { get; private set; }

        public CalEventArgs(int num1, int num2, char op, int result)
        {
            Number1 = num1;
            Number2 = num2;
            Oper    = op;
            Result  = result;
        }
    }

    //1 : 델리게이트 정의
    delegate void CalEvent(object obj, CalEventArgs e);
}
