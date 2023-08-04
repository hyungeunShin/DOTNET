using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1102_DOM
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            XmlDom.Exam_5_1("data1.xml");
            textBox1.Text = XmlDom.ReadXml2("data1.xml");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            XmlDom.Exam_5_2("data2.xml");
            textBox1.Text = XmlDom.ReadXml2("data2.xml");
        }
    }
}
