using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/*
 * 프로퍼티(Property)
 * OOP get/set메서드의 대용.
 * 특수한 형태의 함수이지만 변수처럼 사용할 수 있다.
 * 사용 위치에 따라 자동으로 set, get 결정
 * - 대입연산의 좌측에 있으면 set
 * - 그 외 모든 경우는 get
 */ 
namespace _0923_1
{
    class Employee
    {
        //맴버 필드는 소문자.
        private readonly int birthYear;
        private string name;
        private int age;

        # region 프로퍼티 : 권장사항(이제는 내부든 외부든 제공되는 프로퍼티를 사용해라)
        public int BirthYear
        {
            get { return birthYear; }
        }

        public string Name
        {
            get { return name;  }
            private set { name = value; } //외부에서는 사용할 수 없다.
        }

        public int Age
        {
            get { return age;   }
            set { age = value;  }
        }
        #endregion 

        //생성자(객체 초기화), 오버로딩가능... & 소멸자(자세히 확인)        
        public Employee(int b, string n)
        {
            birthYear = b;
            Name = n;      //set프로퍼티를 사용, n --> value로 전달!
            Age = 0;
        }
        ~Employee()
        {

        }   

        //메서드(오버로딩)
        public void Print()
        {
            Console.WriteLine("{0}, {1}, {2}", BirthYear, Name, Age);
        }
    }
   
    //set 필터링!
    class Employee1
    {
        private int age;

        public int Age
        {
            get { return age;  }
            set
            {
                if (value <= 0 && value > 200)
                    throw new Exception("잘못된 나이입니다"); //return;
                age = value;
            }
        }
    }

    //자동 프로퍼티
    // private int age;         //1
    // public int Age       { get{return age;} set { age = value; }}    //2
    // private string name;     //3
    // public string Name   {get{return name;} private set{ name = value; }}    //4
    //
    class Employee2
    {
        public int Age { get; set; }   //1,2동시에 생성(맴버필드의 이름은 모른다)
        public string Name { get; private set;  }   //3,4
    }


    class Class2
    {
        public static void Main(string[] args)
        {
            Employee emp = new Employee(10, "홍길동");
            emp.Print();

            //emp.Name = "김길동";
            emp.Age = 20;

            emp.Print();
            Console.WriteLine("{0}, {1}, {2}", emp.BirthYear, emp.Name, emp.Age);
        }
    }
}
