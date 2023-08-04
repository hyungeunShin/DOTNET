using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using _1103_Client.localhost;
using _1103_Client.localhost1;

namespace _1103_Client
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ShowHelloService s = new ShowHelloService();
            textBox1.Text = s.ShowHello();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int num1 = int.Parse(textBox2.Text);
            int num2 = int.Parse(textBox3.Text);

            CalService cs = new CalService();
            textBox4.Text = cs.Add(num1, num2).ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int number = int.Parse(textBox5.Text);
            CalService cs = new CalService();

            cs.SetNumber(number);
            textBox6.Text = cs.GetNumber().ToString();
        }
    }
}
