using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923_1
{
    class Student
    { 
        //자동프로퍼티 구현 
        public string Name      { get; set; }
        public int Age          { get; set; }
        public string Subject   { get; set; }

        public Student() { }

        public Student(string n, int a, string s)
        {
            Name = n;
            Age = a;
            Subject = s;
        }
    }

    class Class1
    {
        public static void Main(string[] args)
        {
            Student stu = new Student("홍길동", 10, "컴퓨터");

            Student sts1 = new Student()
            { 
                Name = "이길동",
                Age = 10,
                Subject = "IT"
            };

        }
    }
}
