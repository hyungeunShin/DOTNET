using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1013_LINQ
{
    class Member
    {
        public string Name { get; set; }
        public int Age { get; set; }

        public Member() { }
        public Member(string name, int age)
        {
            Name = name;
            Age = age;
        }

        public override string ToString()
        {
            return Name + "," + Age;
        }
    }
}
