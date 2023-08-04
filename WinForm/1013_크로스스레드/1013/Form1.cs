using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1013
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           // SetNameThread();
            Thread tr = new Thread(SetNameThread);
            tr.Start();
        }

        private void SetNameThread()
        {
            //if (textBox1.InvokeRequired)
            //{
            //    Action<string> del = SetText;
            //    textBox1.Invoke(del, new object[] { "AAA" });
            //}
            //else
            //{
            //    textBox1.Text = "AAA";
            //}
            if (textBox1.InvokeRequired)
            {
                Action<string> del = (msg) => { textBox1.Text = msg; };
                textBox1.Invoke(del, new object[] { "AAA" });
            }
            else
            {
                textBox1.Text = "AAA";
            }
        }

        public void SetText(string msg)
        {
            textBox1.Text = msg;
        }

    }
}
