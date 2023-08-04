using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008_실습
{
    public partial class Form1 : Form
    {
        StuManager con = StuManager.Singleton;

        public Form1()
        {
            InitializeComponent();
        }

        #region 메뉴
        private void 프로그램종료XToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void 회원정보입력AToolStripMenuItem_Click(object sender, EventArgs e)
        {            
            Form2 form = new Form2();
            if (form.ShowDialog() == DialogResult.OK)
            {
                Student stu = form.GetStudentInfo();

                if (con.Add(stu) == false)
                    return;
                PrintStudent(); 
            }
        }

        #endregion

        #region 윈도우 핸들러
        private void Form1_Load(object sender, EventArgs e)
        {
            //파일 불러오기...............................................
            불러오기GToolStripMenuItem_Click(sender, e);
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            저장하기SToolStripMenuItem_Click(sender, e);
        }

        #endregion

        public void PrintStudent()
        {
            List<Student> slist = con.Students;

            //리스트뷰 초기화
            listView1.Items.Clear();

            //라벨에 개수 출력
            textBox1.Text = string.Format("총 학생수: {0}명", slist.Count);

            //리스트뷰 전체 출력
            foreach (Student s in slist)
            {
                listView1.Items.Add(new ListViewItem(new string[] 
                { string.Format("{0}", s.Number), s.Name, string.Format("{0}", s.Stype), string.Format("{0}", s.Grade) }));
            }
        }
           
        //검색버튼 클릭
        private void button1_Click(object sender, EventArgs e)
        {
            int number = int.Parse(textBox2.Text);
    
            Student stu= con.NumberToStudent(number);
            if (stu != null)
            {
                textBox2.Text = stu.Number.ToString();
                textBox3.Text = stu.Name;
                comboBox1.Text = stu.Stype.ToString();
                comboBox2.Text = stu.Grade.ToString();
            }
        }

        //리스트뷰 클릭시 검색결과 출력
        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listView1.SelectedItems.Count == 0)
                return;
            else
            {
                int id = int.Parse(listView1.SelectedItems[0].SubItems[0].Text);
                string name = listView1.SelectedItems[0].SubItems[1].Text;
                string major = listView1.SelectedItems[0].SubItems[2].Text;
                int grade = int.Parse(listView1.SelectedItems[0].SubItems[3].Text);

                textBox2.Text = id.ToString();
                textBox3.Text = name;
                comboBox1.SelectedIndex = Student.TypetoIndex(major);
                comboBox2.SelectedIndex = grade-1;
            }
        }

        //삭제 버튼 클릭
        private void button2_Click(object sender, EventArgs e)
        {
            int num = int.Parse(textBox2.Text);
            if (con.Delete(num) == true)
            {
                PrintStudent();
                textBox2.Text = "";
                textBox3.Text = "";
                comboBox1.Text = "";
                comboBox2.Text = "";
            }
        }

        //수정 버튼 클릭
        private void button3_Click(object sender, EventArgs e)
        {
            int num = int.Parse(textBox2.Text);
            ShapeType type = (ShapeType)(comboBox1.SelectedIndex);
            int Grade = (comboBox2.SelectedIndex);
            if (con.Update(num, type, Grade+1) == true)
                PrintStudent();
        }

        private void 저장하기SToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StudentFileIO.SaveFile(con.Students);
        }

        private void 불러오기GToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StudentFileIO.LoadFile(con.Students);
            PrintStudent();
        }


    }
}
