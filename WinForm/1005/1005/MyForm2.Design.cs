using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;

namespace _1005
{
    //디자이너에 의해 자동으로 생성되는 코드들..
    partial class MyForm2 : Form
    {
        private Button button1 = new Button();

        public void Init()
        {
            this.Text = "세번째 Form";
            this.BackColor = Color.SeaShell;

            this.MouseMove += MyForm2_MouseMove;

            //버튼처리
            button1.Text = "클릭!";
            button1.SetBounds(10, 10, 100, 30);
            button1.Click += Button1_Click;
            this.Controls.Add(button1);

            this.Show();
        }

    }
}
