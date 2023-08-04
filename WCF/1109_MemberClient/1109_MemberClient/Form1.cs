using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using _1109_MemberClient.ServiceReference1;

namespace _1109_MemberClient
{
    public partial class Form1 : Form
    {
        MemberServiceClient memberService = new MemberServiceClient();

        public Form1()
        {
            InitializeComponent();
        }

        #region 서비스 연결관리
        private void Form1_Load(object sender, EventArgs e)
        {
            memberService.Open();

            Print();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            memberService.Close();
        }
        #endregion

        #region 출력관리

        //숫자만 입력
        private void KryPress(object sender, KeyPressEventArgs e)
        {
            if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))
            {
                e.Handled = true;
            }
        }

        //데이터 그리드뷰에 출력
        private void Print()
        {
            DataTable dt = memberService.SelectAll_Table();
            dataGridView1.DataSource = dt;
            //label15.Text = string.Format("등록된 회원 수 : " + dt.Rows.Count.ToString());
        }
        #endregion

        #region 기능

        //입력
        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                string name = textBox1.Text;
                string phone = textBox2.Text;

                bool result = memberService.Insert(name, phone);

                if (result == true)
                {
                    MessageBox.Show("회원 등록 완료");
                    Print();
                }
                else
                {
                    MessageBox.Show("회원 등록 실패");
                }
                textBox1.Clear();
                textBox2.Clear();
            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");
            }
        }

        //삭제
        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox3.Text != "")
            {
                bool result = memberService.Delete(int.Parse(textBox3.Text));

                if (result == true)
                {
                    MessageBox.Show("회원 삭제 완료");
                    Print();
                }
                else
                    MessageBox.Show("회원 삭제 실패");
                textBox3.Clear();
            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");
            }
        }
        //수정
        private void button4_Click(object sender, EventArgs e)
        {
            int gnumber = int.Parse(textBox7.Text);
            int mnumber = int.Parse(textBox4.Text);

            if (gnumber == 0 || gnumber == 1 || gnumber == 2 || gnumber == 3 || gnumber == 4 || gnumber == 5 || gnumber == 6)
            {
                bool result = memberService.update(gnumber, mnumber);

                if (result == true)
                {
                    MessageBox.Show("회원 수정 완료");

                    textBox4.Clear();
                    textBox14.Clear();
                    textBox5.Clear();
                    textBox6.Clear();
                    textBox7.Clear();
                    textBox7.ReadOnly = true;
                    Print();
                }
                else
                    MessageBox.Show("회원 수정 실패");
            }
            else
            {
                MessageBox.Show("0~6사이의 그룹번호를 입력해주세요.");
            }
        }


        //회원번호로 검색 --> 오류 : 그룹번호가 null일 때 오류발생 --> Gnumber의 default를 0으로 바꿈
        private void button3_Click(object sender, EventArgs e)
        {
            if (textBox4.Text != "")
            {
                int mnumber = int.Parse(textBox4.Text);

                Member mem = memberService.Select_Number(mnumber);
                if (mem == null)
                {
                    MessageBox.Show("mem==null");
                    textBox7.ReadOnly = false;
                }
                textBox14.Text = mem.MNumber.ToString();
                textBox5.Text = mem.MName;
                textBox6.Text = mem.MPhone;
                textBox7.Text = mem.GNumber.ToString();

                textBox7.ReadOnly = false;
            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");
            }
        }

        //그룹번호로 검색
        private void button5_Click(object sender, EventArgs e)
        {
            int gnumber = int.Parse(textBox8.Text);

            if (gnumber == 0 || gnumber == 1 || gnumber == 2|| gnumber == 3|| gnumber == 4|| gnumber == 5|| gnumber == 6)
            {
                DataTable dt = memberService.Select_Group(gnumber);
                dataGridView2.DataSource = dt;

                textBox8.Clear();
            }
            else
            {
                MessageBox.Show("0~6사이의 그룹번호를 입력해주세요.");
            }
        }


        #endregion

    }
}
