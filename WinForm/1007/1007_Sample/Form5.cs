using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1007_Sample
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }
        private const int WM_MOUSEMOVE = 0x200;  //#define WM_MOUSEMOVE 0x200
        protected override void WndProc(ref Message m)
        {            
            switch (m.Msg)
            {
                case WM_MOUSEMOVE:                   
                    Point p = new Point(m.LParam.ToInt32());
                    this.Text = p.X + "," + p.Y;
                    //base.WndProc(ref m);
                    //base.DefProc(ref m);
                    return;
            }
            base.WndProc(ref m);
        }

        private void Form5_MouseMove(object sender, MouseEventArgs e)
        {
            this.Text = "마우스무브 " + e.X + "," + e.Y;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            for (long i = 0; i < 10000000000000; i++)
            {
                double d = i * 0.453432F * 0.23423D;
            }
            this.Text = "DoEvents() 사용 안함 완료";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            for (long i = 0; i < 10000000000000; i++)
            {
                double d = i * 0.453432F * 0.23423D;
                if (i % 1000000 == 0)
                    Application.DoEvents();
            }
            this.Text = "DoEvents() 사용함 완료";
        }

        private void Form5_MouseDown(object sender, MouseEventArgs e)
        {
            using(Graphics gh = this.CreateGraphics())
            {
                gh.DrawRectangle(new Pen(Color.Red), e.X - 25, e.Y - 25, 50, 50);
            }
        }

        private void Form5_Click(object sender, EventArgs e)
        {
           //버튼 클릭!
        }
    }
}
