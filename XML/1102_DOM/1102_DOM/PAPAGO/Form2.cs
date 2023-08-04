using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1102_DOM
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            textBox1.Text = "안녕하세요!";
        }

        private void button1_Click(object sender, EventArgs e)
        {           

            string msg = textBox1.Text;

            string json = Papago.Trans("ko", "ja", msg);

            textBox2.Text = Papago.JsonParsing(json);
        }
    }
}
