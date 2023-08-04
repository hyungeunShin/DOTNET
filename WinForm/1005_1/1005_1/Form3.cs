using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*
 * 1. 마우스 L Button 클릭시 50 * 50 의 사각형 해당 위치에 출력!
 * 2. 사각형 출력시 내부 색상을 칠할 것
 * 3. 콤보박스에서 색상을 선택하면 그 색상으로 컨트롤 칠하기
 * 
 * Graphics 객체 사용
 * 방법1) LButton 클릭시 그래픽스 객체를 획득해 사각형 출력
 * 
 * 방법2) LButton 클릭시 좌표 정보를 저장 -> 무효화
 *        OnPaint에서 저장된 좌표 정보를 이용하여 출력
 *-----------------------------------------------------
 *Form_Load(초기화 과정)에서 컨트롤 초기화를 수행 -> 콤보박스에 색상을 추가.
 *콤보박스에서 색상을 선택 -> 컨트롤에 해당 색상으로 칠하기
 *        
 */ 
namespace _1005_1
{
    public partial class Form3 : Form
    {
        private List<Point> points = new List<Point>();

        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_MouseUp(object sender, MouseEventArgs e)
        {
            //첫번째 방식
            //Graphics gh = this.CreateGraphics();

            //gh.FillRectangle(new SolidBrush(Color.DarkGray), e.X, e.Y, 50, 50);
            //gh.DrawRectangle(new Pen(Color.Black), e.X, e.Y, 50, 50);

            //gh.Dispose();

            //두번째 방식
            points.Add( new Point(e.X, e.Y));

            //전체 무효화, 화면을 다시 그린다.
            this.Invalidate(); 

        }

        private void Form3_Paint(object sender, PaintEventArgs e)
        {
            Graphics gh = e.Graphics;

            foreach(Point pt in points)
            {
                gh.FillRectangle(new SolidBrush(Color.DarkGray), pt.X, pt.Y, 50, 50);
                gh.DrawRectangle(new Pen(Color.Black), pt.X, pt.Y, 50, 50);
            }
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            comboBox1.DrawMode = DrawMode.OwnerDrawVariable;

            Array arr = System.Enum.GetValues(typeof(KnownColor));               
            foreach (object str in arr)
            {
                comboBox1.Items.Add(str.ToString());
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string str = (string)comboBox1.SelectedItem;
            this.Text = str;
            Color col = Color.FromName(str);

            //pictureBox1.BackColor = col;
            Graphics gh = pictureBox1.CreateGraphics();
            gh.FillRectangle(new SolidBrush(col), pictureBox1.ClientRectangle);
            gh.Dispose();
        }

        //Form_Load에서 DrawMode를 변경
        //여기서 내가 직접 출력
        private void comboBox1_DrawItem(object sender, DrawItemEventArgs e)
        {
            Graphics gh = e.Graphics;
            
            Array arr = System.Enum.GetValues(typeof(KnownColor));
            string colorstr = arr.GetValue(e.Index).ToString();
            Brush brush = new SolidBrush(Color.FromName(colorstr));

            gh.DrawString(comboBox1.Items[e.Index].ToString(),
                    e.Font, brush, e.Bounds, StringFormat.GenericDefault);
        }
    }
}
