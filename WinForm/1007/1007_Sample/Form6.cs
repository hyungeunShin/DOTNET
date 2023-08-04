using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//더블버퍼링
namespace _1007_Sample
{
    public partial class Form6 : Form
    {
        public Image ImgSample { get; set; }
        private int imagesize = 0;

        public Form6()
        {
            InitializeComponent();
            //this.DoubleBuffered = true;
        }

        private void Form6_Load(object sender, EventArgs e)
        {
            ImgSample = Image.FromFile("ocean.jpg");
            timer1.Start();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics gh = e.Graphics;
            gh.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;
            gh.FillRectangle(Brushes.Yellow, new Rectangle(new Point(0, 0), this.ClientSize));
            gh.DrawImage(ImgSample, 50, 50, ImgSample.Width+ imagesize, ImgSample.Height+ imagesize);
        }
        //0.1초
        private void timer1_Tick(object sender, EventArgs e)
        {
            imagesize++;
            Invalidate();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            this.DoubleBuffered = checkBox1.Checked;
        }
    }
}
