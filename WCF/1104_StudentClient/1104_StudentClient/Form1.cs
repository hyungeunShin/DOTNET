using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using _1104_StudentClient.ServiceReference1;

namespace _1104_StudentClient
{
    public partial class Form1 : Form
    {
        StudentServiceClient studentService = new StudentServiceClient();

        public Form1()
        {
            InitializeComponent();
        }

        
        #region DB Load
        private void Form1_Load(object sender, EventArgs e)
        {
            studentService.Open();
            Print();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            studentService.Close();
        }

        //데이터 출력
        private void Print()
        {
            DataTable dt = studentService.SelectAll_Table();
            dataGridView1.DataSource = dt;
            label13.Text = string.Format("현재 등록된 회원 수 : " + dt.Rows.Count.ToString());
        }
        #endregion

        #region int textbox 숫자만 입력받기
        private void textBox4_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))
            {
                e.Handled = true;
            }
        }

        private void textBox5_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))
            {
                e.Handled = true;
            }
        }

        private void textBox8_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))
            {
                e.Handled = true;
            }
        }
        #endregion

        #region 기능
        //회원가입
        private void button1_Click(object sender, EventArgs e)
        {
            if (textBox1.Text != "")
            {
                string name = textBox1.Text;
                int grade = int.Parse(comboBox1.SelectedItem.ToString());
                string major = comboBox3.SelectedItem.ToString();

                bool result = studentService.InsertMember(name, grade, major);

                if (result == true)
                {
                    textBox1.Clear();
                    MessageBox.Show("회원 등록 완료");
                    Print();
                }
                else
                    MessageBox.Show("회원 등록 실패");

            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");
            }
        }

        //삭제
        private void button2_Click(object sender, EventArgs e)
        {
            if (textBox4.Text != "")
            {
                bool result = studentService.DeleteMember(int.Parse(textBox4.Text));

                if (result == true)
                {
                    MessageBox.Show("회원 삭제 완료");
                    textBox4.Clear();
                    Print();
                }
                else
                    MessageBox.Show("회원 삭제 실패");
            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");
            }
        }

        //수정
        private void button3_Click(object sender, EventArgs e)
        {
            if (textBox5.Text != "")
            {
                int number = int.Parse(textBox5.Text);
                int grade = int.Parse(comboBox2.SelectedItem.ToString());

                bool result = studentService.UpdateMember(number, grade);

                if (result == true)
                {
                    MessageBox.Show("회원 수정 완료");
                    textBox5.Clear();
                    Print();
                }
                else
                    MessageBox.Show("회원 수정 실패");
            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");

            }
        }

        //검색
        private void button4_Click(object sender, EventArgs e)
        {
            if (textBox8.Text != "")
            {
                int number = int.Parse(textBox8.Text);
                Student stu = studentService.SelectMember(number);
                textBox9.Text = stu.Name;
                textBox7.Text = stu.Grade.ToString();
                textBox10.Text = stu.Major;
                textBox11.Text = stu.Date.ToString();
            }
            else
            {
                MessageBox.Show("정보를 입력해주세요");
            }
        }
        #endregion

    }
}
