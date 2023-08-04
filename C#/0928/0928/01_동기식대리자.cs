using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * [대리자]
 * 1. 대리자 정의(필요한 정보 : 함수의 리턴타입, 매개변수 리스트]
 *     --> 클래스가 생성
 * 2. 객체 생성 , 함수를 등록(함수의 이름을 등록, 이름이 없는 함수 등록)
 * ---------------------------------------------------------------
 * 3. 객체를 이용해 등록한 함수를 호출!
 *    - 동기식 호출
 *      1) 2번에서 생성된 객체 이름을 이용하여 함수처럼 호출
 *      2) 암묵적으로만들어진 클래스 내의 invoke 함수를 호출
 *      * 1,2번은 동일한 결과물(1번 호출은 2번의 invoke 함수를 내부적 호출)
 *    - 비동기식 호출    
 */
namespace _0928
{
    //1. 대리자 정의(일반적으로 클래스 외부)
    delegate float DemoDele(int a, int b);

    class Program
    {
        //2. 객체 생성(맴버필드, 지역변수)
        DemoDele del1 = new DemoDele(Add);  //static이면 자유롭게 저장!  1)등록
        DemoDele del2;
        public DemoDele del3;

        //인스턴스 맴버 내부에서 사용!!!!!!
        public Program()
        {
            del2 = new DemoDele(Sub);       //2등록)
        }

        static float Add(int n1, int n2)
        {
            return (float)n1 + n2;
        }

        public float Sub(int n1, int n2)
        {
            return (float)n1 - n2;
        }

        //static 매서드( 이 안에서는 static 만 접근 가능!!!!)
        static void Main(string[] args)
        {
            Program p = new Program();
            p.del3 = p.Sub;                 //3등록)     
            //---------------------------------------------------
            //사용(동기식)
            Console.WriteLine("static맴버 함수 호출 : {0}", p.del1(10, 20));
            Console.WriteLine("static맴버 함수 호출 : {0}", p.del1.Invoke(10, 20));

            Console.WriteLine("인스턴스 맴버 함수 호출 : {0}", p.del2(10, 20));
            Console.WriteLine("인스턴스 맴버 함수 호출 : {0}", p.del2.Invoke(10, 20));

            Console.WriteLine("인스턴스 맴버 함수 호출 : {0}", p.del3(10, 20));
            Console.WriteLine("인스턴스 맴버 함수 호출 : {0}", p.del3.Invoke(10, 20));
        }
    }
}
