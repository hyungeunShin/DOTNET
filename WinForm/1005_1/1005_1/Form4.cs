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
    public partial class Form4 : Form
    {
        public Image MyImage { get; private set; }

        public Form4()
        {
            InitializeComponent();

            MyImage = null;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Image imageFile = Image.FromFile("ocean.jpg");
            Graphics gh = Graphics.FromImage(imageFile);

            //글자 -> 이미지에 출력!
            Font font   = new Font("돋음", 20);
            Brush brush = Brushes.Pink;
            gh.DrawString("이미지에 글자쓰기", font, brush, 10, 10);           

            MyImage = imageFile;

            this.Invalidate();

            gh.Dispose();

            //저장
            imageFile.Save("ocean.bmp", System.Drawing.Imaging.ImageFormat.Bmp);
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics grfx = e.Graphics;
            if (MyImage != null)
                grfx.DrawImage(MyImage, 10,60);
        }
    }
}
