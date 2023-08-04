using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace _1005
{
    //개발자가 사용하는 파일(핸들러..)
    partial class MyForm2
    {
        public MyForm2()
        {
            Init();
        }

        private void MyForm2_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = string.Format("{0}, {1}, {2}", e.X, e.Y, e.Button);
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            Random r = new Random();
            this.BackColor = Color.FromArgb(r.Next(0, 256), r.Next(0, 256), r.Next(0, 256));
        }
    }
}
