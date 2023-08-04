using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 1. 모든 맴버에 접근 지정자를 붙힌다. <------------------------------
 *     기본 접근지정자  private
 * 2. 맴버 필드 --> 데이터 은닉!
 * 3. 생성자 : 맴버 필드 초기화
 * 4. 소멸자는 접근지정자를 사용할 수 없다.<--------------------------------
 * 5. get & set 메서드 <--------------------사용 안함 --> 프로퍼티......
 *    맴버 필드를 노출시키는 메서드 
 */ 
namespace _0923_1
{
    class Employee
    {
        //맴버 필드(상수-readonly, const, 변수)
        private readonly int BirthYear;
        private string Name;

        //생성자(객체 초기화), 오버로딩가능... & 소멸자(자세히 확인)        
        public Employee(int b, string n)
        {
            BirthYear = b;
            Name = n;
        }
        ~Employee()
        {

        }

        //get & set 메서드 --> 프로퍼티
        public int getBirthYear()           { return BirthYear; }
        public string getName()             { return Name;  }
        public void setName(string value)   { Name = value; }

        //메서드(오버로딩)
        public void Print()
        {
            Console.Write("{0}, {1}", BirthYear, Name);
        }
    }

    class Class1
    {
        public static void Main(string[] args)
        {

        }
    }
}
