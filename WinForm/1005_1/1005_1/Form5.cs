using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1005_1
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            //예제1)
            //Graphics gh = e.Graphics;

            ////Pen pen = new Pen(Brushes.Red, 3);                    //Brush, width
            ////Pen pen = new Pen(new SolidBrush(Color.Red), 3);      //Brush, width
            //Pen pen = new Pen(Color.Red, 3);                        //Color, width

            ////path
            //GraphicsPath gp = new GraphicsPath();

            ////그림1
            //gp.AddLine(10, 10, 100, 100);
            //gp.AddEllipse(50, 50, 100, 100);
            //gp.CloseFigure();       //닫음

            ////그림2
            //gp.StartFigure();
            //gp.AddArc(300, 300, 50, 50, 90, 270);
            //gp.AddLine(250, 200, 370, 350);

            ////지금까지 열린 그림을 닫음
            //gp.CloseAllFigures();

            ////그림3
            //gp.AddPie(30, 300, 70, 70, 90, 270);


            ////출력(Draw, Fill)
            //gh.DrawPath(pen, gp);   
            //gp.Dispose();


            //예제2)
            //Graphics g = e.Graphics;

            //GraphicsPath shape = new GraphicsPath();
            //shape.AddEllipse(0, 0, 100, 100);
            ////shape.AddRectangle(new Rectangle(100, 0, this.Width - 100, this.Height));
            //shape.AddLine(100, 100, 0, 200);
            //shape.AddLine(0, 200, 200, 200);
            //shape.CloseFigure();

            //this.Region = new Region(shape);
            //shape.Dispose();
            //g.DrawString("GraphicsPath와 Region 응용", this.Font, Brushes.Black, 120, 30);

            //예제3) 클리핑
            //Graphics g = e.Graphics;
            //Pen p = new Pen(Color.Black);
            //p.DashStyle = DashStyle.Dot;
            //g.DrawRectangle(p, 100, 100, 100, 100);
            //g.DrawRectangle(p, 10, 10, 50, 50);
            //g.DrawRectangle(p, 150, 150, 200, 200);

            //// 클리핑 영역 지정
            //g.SetClip(new Rectangle(100, 100, 100, 100));

            //// 클리핑 영역에서만 출력이 이루어지게 됨
            //g.FillRectangle(Brushes.Black, 10, 10, 50, 50);
            //g.FillRectangle(Brushes.Red, 150, 150, 200, 200);

            //예제4) 클리핑
            //Bitmap bmp = new Bitmap("태극기.gif");

            //FontFamily ff = new FontFamily("궁서체");

            //Graphics g = e.Graphics;

            //g.FillRectangle(Brushes.Pink, this.ClientRectangle);

            //GraphicsPath gp = new GraphicsPath();
            //gp.AddString("여러문자열", ff, (int)FontStyle.Bold, 150, new Point(5, 20), StringFormat.GenericDefault);
            //// 글자의 영역만 클리핑 설정
            //g.SetClip(gp);
            //// 설정된 영역에 그림 출력
            //g.DrawImage(bmp, this.ClientRectangle);

            //g.Dispose();

        }
    }
}
