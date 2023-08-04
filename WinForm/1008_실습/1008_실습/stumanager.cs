using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008_실습
{
    public class StuManager
    {
        private List<Student> students = new List<Student>();
        public List<Student> Students { get { return students; } }

        #region 싱글톤 하나의 객체만 만들수 있는 클래스
        private StuManager() { }

        static StuManager()
        {
            Singleton = new StuManager();         // 단일체 생성
        }

        static public StuManager Singleton { get; private set; }

        #endregion


        //저장기능
        public bool Add(int number1, string name1,ShapeType stype1, int grade1)
        {
            try
            {
                foreach (Student stu in students)
                {
                    if (stu.Number == number1)
                        throw new Exception("동일한 학번이 존재합니다.");
                }
                students.Add(new Student(number1, name1, stype1, grade1));
                return true;
            }
            catch(Exception ex)
            {
                MessageBox.Show("저장 실패" + ex.Message);
                return false;
            }
        }
        public bool Add(Student sd)
        {
            try
            {
                foreach (Student stu in students)
                {
                    if (stu.Number == sd.Number)
                        throw new Exception("동일한 학번이 존재합니다.");
                }
                students.Add(sd);
                return true;
            }
            catch (Exception ex)
            {
                MessageBox.Show("저장 실패" + ex.Message);
                return false;
            }
        }

        //검색기능
        public Student NumberToStudent(int number)
        {
            //student stu = students.Find(data => data.Number == number);
            //if (stu != null)
            //    return stu;
            //return null;  
            return students.Find(data => data.Number == number);
        }

        //삭제기능
        public bool Delete(int number)
        {
            try
            {
                Student stu = NumberToStudent(number);
                if (stu == null)
                    throw new Exception("해당 번호가 없다.");
               
               students.Remove(stu);
               return true;
            }
            catch(Exception ex)
            {
                MessageBox.Show("삭제 실패" + ex.Message);
                return false;
            }
        }

        //수정기능
        public bool Update(int number, ShapeType type, int grade)
        {
            try
            {
                Student stu = NumberToStudent(number);
                if (stu == null)
                    throw new Exception("해당 번호가 없다.");

                stu.Stype = type;
                stu.Grade = grade;
                return true;
            }
            catch(Exception ex)
            {
                MessageBox.Show("수정 실패" + ex.Message);
                return false;
            }
        }
    }
}
