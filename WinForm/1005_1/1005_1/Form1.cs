using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1005_1
{
    //기본 코드
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = string.Format("{0}, {1}", e.X, e.Y);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string msg = textBox1.Text;

            listBox1.Items.Add(msg);

            textBox1.Text = "";

            textBox1.Focus();
        }
    }
}
