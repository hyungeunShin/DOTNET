using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008_실습
{
    
    public enum ShapeType { 선택하세요, 컴퓨터, IT, 게임, 기타 }

    [Serializable()]
    public class Student
    {
   
        public int Number { get; set; }
        public string Name { get; set; }
        public ShapeType Stype { get; set; }

        private int grade;
        public int Grade
        {
            get { return grade; }
            set
            {
                if (value <= 0 && value > 4)
                {
                    grade = -1;
                    throw new Exception("해당학년은 존재하지 않습니다");
                }
                grade = value;
            }
        }

        public Student()
        {
        }

        public Student(int number1, string name1, ShapeType stype1, int grade1)
        {
            Number = number1;
            Name = name1;
            Stype = stype1;
            Grade = grade1;
        }

        public override string ToString()
        {
            return string.Format("{0}, {1}, {2}, {3}", Number, Name, Stype, Grade);
        }

        public void Print()
        {
            MessageBox.Show("[학번]\n " + Number + "[이름]\n " + Name + "[학과]\n " + Stype + "[학년]\n " + Grade);
        }

        static public int TypetoIndex(string major)
        {
            int idx = -1;
            switch(major)
            {
                case "컴퓨터":    idx = 1; break;
                case "IT":       idx = 2; break;
                case "게임":     idx = 3; break;
                case "기타":     idx = 4; break;
            }
            return idx;
        }


        //public class DataCompare : IEqualityComparer<student>
        //{
        //    public bool Equals(student x, student y)
        //    {
        //        if (string.Equals(x.Number.ToString(), y.Number.ToString(), StringComparison.OrdinalIgnoreCase) &&
        //            string.Equals(x.Name, y.Name, StringComparison.OrdinalIgnoreCase))
        //        {
        //            return true;
        //        }
        //        return false;
        //    }
        //    public int GetHashCode(student obj)
        //    {
        //        return obj.Name.GetHashCode();
        //    }
        //}
    }
}
