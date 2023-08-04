using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//게시자
//1) 이벤트 선언
//2) 이벤트 발생
namespace _0928
{
    class Operation
    {
        //1) 이벤트 선언
        public event CalEvent CalAdd = null;
        public event CalEvent CalSub = null;

        public int Result { get; set; }

        public void Add(int num1, int num2)
        {
            Result = num1 + num2;

            //2)이벤트 발생
            if (CalAdd != null)     
            {
                CalAdd(this, new CalEventArgs(num1, num2, '+', Result));
            }
        }

        public void Sub(int num1, int num2)
        {
            Result = num1 - num2;

            //2)이벤트 발생
            if (CalSub != null)
            {
                CalSub(this, new CalEventArgs(num1, num2, '-', Result));
            }
        }
    }
}
