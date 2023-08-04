using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//더블버퍼링_직접 코딩(메모리 비트맵)
namespace _1007_Sample
{
    public partial class Form7 : Form
    {
        public Image ImgSample { get; set; }
        private int imagesize = 0;

        //더블버퍼링을 위해 메모리비트맵생성
        BufferedGraphicsContext context;
        BufferedGraphics graphics;

        public Form7()
        {
            InitializeComponent();
        }

        private void Form7_Load(object sender, EventArgs e)
        {
            ImgSample = Image.FromFile("ocean.jpg");           
            //----------------------------------------------
            context = BufferedGraphicsManager.Current;
            context.MaximumBuffer = new Size(this.Width, this.Height);
            graphics = context.Allocate(CreateGraphics(), new Rectangle(0, 0, this.Width, this.Height));
            graphics.Graphics.Clear(Color.Yellow);
            //----------------------------------------------
            //SetClientSizeCore(800, 600);

            timer1.Start();
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            graphics.Render(e.Graphics);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            imagesize++;

            //--------메모리 비트맵에 이미지를 출력----
            graphics.Graphics.DrawImage(ImgSample, 50, 50, ImgSample.Width + imagesize, ImgSample.Height + imagesize);
            Invalidate();
        }
    }
}
