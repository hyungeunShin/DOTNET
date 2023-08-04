using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.Serialization;

namespace _1104_StudentService
{
    [DataContract]
    class Student
    {
        [DataMember]
        public int Number { get; set; }

        [DataMember]
        public string Name { get; set; }
       
        [DataMember]
        public int Grade { get; set; }
        
        [DataMember]
        public string Major { get; set; }

        [DataMember]
        public DateTime Date { get; set; }

        public Student(int number, string name, int grade, string major, DateTime date)
        {
            Number = number;
            Name = name;
            Grade = grade;
            Major = major;
            Date = date;
        }

        public Student(int number, string name, int grade, string major)
        {
            Number = number;
            Name = name;
            Grade = grade;
            Major = major;
            Date = DateTime.Now;
        }
    }
}
