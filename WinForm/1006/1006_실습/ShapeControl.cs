using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;
using System.Windows.Forms;

namespace _1006_실습
{
    class ShapeControl
    {
        //저장 정보
        private List<Shape> shapes = new List<Shape>();
        public List<Shape> Shapes {  get { return shapes; } }

        #region 싱글톤 : 하나의 객체만 만들수 있는 클래스
        private ShapeControl() { }

        static ShapeControl()  //정적 생성자(최초 한번만)
        {
            Singleton = new ShapeControl();//단일체 생성
        }
        static public ShapeControl Singleton { get; private set; }

        #endregion
    
        //저장
        public void Add( string name, ShapeType type, Color color, Point pt)
        {
            shapes.Add(new Shape(name, type, color, pt));
        }

        //전체 출력
        public void PrintAll(Graphics gh)
        {
            foreach (Shape s in shapes)
            {
                DrawShape(s, gh);
            }
        }

        //하나의 도형 출력
        private void DrawShape(Shape sh, Graphics gh)
        {
            if (sh.ShapeType == ShapeType.ELLIPSE)
            {
                gh.FillEllipse(new SolidBrush(sh.BackColor),
                    sh.ShapePoint.X, sh.ShapePoint.Y, 100, 100);
            }
            else if (sh.ShapeType == ShapeType.RECT)
            {
                gh.FillRectangle(new SolidBrush(sh.BackColor),
                    sh.ShapePoint.X, sh.ShapePoint.Y, 100, 100);
            }
            else if (sh.ShapeType == ShapeType.TRAIANGLE)
            {
                Point pt = sh.ShapePoint;
                Point[] points = { new Point(pt.X, pt.Y), new Point(pt.X-50, pt.Y+100),
                                   new Point(pt.X+50, pt.Y+100)};
                gh.FillPolygon(new SolidBrush(sh.BackColor), points);
            }

            gh.DrawString(sh.Name, new Font("Arial", 10), Brushes.Black,
                new Point(sh.ShapePoint.X + 20, sh.ShapePoint.Y + 50));

            gh.DrawString(sh.Message, new Font("Arial", 10), Brushes.Black,
               new Point(sh.ShapePoint.X, sh.ShapePoint.Y - 10));
        }

        //케릭터 전체 이동
        public void MoveShapeAll(Keys key)
        {
            foreach (Shape s in shapes)
            {
                MoveShape(s, key);
            }
        }

        //하나의 케릭터 이동
        public void MoveShape(Shape s, Keys key)
        {
            if (key == Keys.Up)
            {
                s.ShapePoint = new Point(s.ShapePoint.X, s.ShapePoint.Y - 10);
            }
            else if (key == Keys.Down)
            {
                s.ShapePoint = new Point(s.ShapePoint.X, s.ShapePoint.Y + 10);
            }
            else if (key == Keys.Left)
            {
                s.ShapePoint = new Point(s.ShapePoint.X - 10, s.ShapePoint.Y);
            }
            else if (key == Keys.Right)
            {
                s.ShapePoint = new Point(s.ShapePoint.X + 10, s.ShapePoint.Y);
            }
        }
    
        //케릭터에 메시지 출력
        public void MessagePrint(string name, string msg)
        {
            Shape shape = shapes.Find(data => data.Name == name);
            if (shape != null)
            {
                shape.Message = msg;
            }
        }
    }
}
