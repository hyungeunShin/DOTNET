using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008_실습
{
    static class StudentFileIO
    {

        public static void LoadFile(List<Student> members)
        {
            try
            {
                using (FileStream fs = new FileStream("Studentlist.txt", FileMode.Open, FileAccess.Read))
                {
                    BinaryFormatter bf = new BinaryFormatter();
                    List<Student> stulist = (List<Student>)bf.Deserialize(fs);
                    List<Student> list = members;
                    members.AddRange(stulist);

                    //members = list.Distinct(new student.DataCompare()).ToList();
                    MessageBox.Show("저장파일을 불러왔습니다.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
            public static void SaveFile(List<Student> stulist)
            {
                try
                {
                    using (FileStream fs = new FileStream("Studentlist.txt", FileMode.Create, FileAccess.Write))
                    {
                        BinaryFormatter bf = new BinaryFormatter();
                        bf.Serialize(fs, stulist);
                    }
                    MessageBox.Show("파일저장에 성공했습니다!", "알림", MessageBoxButtons.OK);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
    }
}