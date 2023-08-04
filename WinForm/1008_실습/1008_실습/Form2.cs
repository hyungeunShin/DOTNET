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
    public partial class Form2 : Form
    {
        #region 프로퍼티 
        public int Number
        {
            get { return int.Parse(textBox1.Text); }
          
        }

        public string Name1
        {
            get { return textBox2.Text; }
           
        }

        public ShapeType ShapeType
        {
            get
            {
                ShapeType s;
                switch (comboBox1.SelectedIndex)
                {
                    case 1: s = ShapeType.컴퓨터; break;
                    case 2: s = ShapeType.IT; break;
                    case 3: s = ShapeType.게임; break;
                    case 4: s = ShapeType.기타; break;
                    default: s = ShapeType.선택하세요; break;
                }
                return s;
            }
           
        }

        public int Grade
        {
            get { return int.Parse(comboBox2.Text); }
           
        }
        #endregion

        public Form2()
        {
            InitializeComponent();
        }


        private void button1_Click_1(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;

            this.Close();
        }

        public Student GetStudentInfo()
        {

            Student stu = new Student(Number, Name1, ShapeType, Grade);
            return stu;
        }
    }
}
