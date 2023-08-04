using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1006_실습
{
    public partial class AddForm : Form
    {
        #region 프로퍼티
        public string ShapeName
        {
            get { return textBox1.Text;  }
            set { textBox1.Text = value; }
        }

        public ShapeType ShapeType
        {
            get 
            {
                ShapeType s;
                switch (comboBox1.SelectedIndex)
                {
                    case 1: s = ShapeType.RECT; break;
                    case 2: s = ShapeType.ELLIPSE; break;
                    case 3: s = ShapeType.TRAIANGLE; break;
                    default: s = ShapeType.NONE; break;
                }
                return s;
            }
            set
            {
                switch (value)
                {
                    case ShapeType.RECT: comboBox1.SelectedIndex = 1; break;
                    case ShapeType.ELLIPSE: comboBox1.SelectedIndex = 2; break;
                    case ShapeType.TRAIANGLE: comboBox1.SelectedIndex = 3; break;
                    default: comboBox1.SelectedIndex = 0; break;
                }
            }
        }

        public Color ShapeColor
        {
            get 
            {
                return Color.FromArgb(
                    (int)numericUpDown1.Value,
                    (int)numericUpDown2.Value,
                    (int)numericUpDown3.Value);
            }
            set
            {
                numericUpDown1.Value = value.R;
                numericUpDown2.Value = value.G;
                numericUpDown3.Value = value.B;

                //---픽처컨트롤에 색상 출력
                using (Graphics gh = pictureBox1.CreateGraphics())
                {
                    gh.FillRectangle(new SolidBrush(value), pictureBox1.ClientRectangle);
                }
            }
        }

        public Point ShapePoint
        {
            get { return new Point(int.Parse(textBox2.Text), int.Parse(textBox3.Text)); }
            set 
            {
                textBox2.Text = value.X.ToString();
                textBox3.Text = value.Y.ToString();
            }
        }

        #endregion

        public AddForm()
        {
            InitializeComponent();
        }

        public AddForm(Shape sh)
        {
            InitializeComponent();

            InitData(sh);

            //콤보박스에 자동으로 enum 정보를 추가(개선 작업)
        }
        
        private void InitData(Shape sh)
        {
            textBox1.Text = sh.Name;

            switch (sh.ShapeType)
            {
                case ShapeType.RECT: comboBox1.SelectedIndex = 1;       break;
                case ShapeType.ELLIPSE: comboBox1.SelectedIndex = 2;    break;
                case ShapeType.TRAIANGLE: comboBox1.SelectedIndex = 3;  break;
                default: comboBox1.SelectedIndex = 0;                   break;
            }

            numericUpDown1.Value = sh.BackColor.R;
            numericUpDown2.Value = sh.BackColor.G;
            numericUpDown3.Value = sh.BackColor.B;

            textBox2.Text = sh.ShapePoint.X.ToString();
            textBox3.Text = sh.ShapePoint.Y.ToString();
        }
        
        public Shape GetShape()
        {
            ShapeType s;
            switch (comboBox1.SelectedIndex)
            {
                case 1: s = ShapeType.RECT;         break;
                case 2: s = ShapeType.ELLIPSE;      break;
                case 3: s = ShapeType.TRAIANGLE;    break;
                default: s = ShapeType.NONE;        break;
            }

            return new Shape(textBox1.Text, s,
                Color.FromArgb((int)numericUpDown1.Value, (int)numericUpDown2.Value, (int)numericUpDown3.Value),
                new Point(int.Parse(textBox2.Text), int.Parse(textBox3.Text)));
        }

        //종료버튼
        private void button2_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        //색상다이얼로그...
        private void button1_Click(object sender, EventArgs e)
        {
            colorDialog1.Color = ShapeColor;
            if( colorDialog1.ShowDialog() == DialogResult.OK)
            {
                ShapeColor = colorDialog1.Color;
            }
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            Color color = ShapeColor;
            ShapeColor = Color.FromArgb((int)numericUpDown1.Value, color.G, color.B);
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            Color color = ShapeColor;
            ShapeColor = Color.FromArgb(color.R, (int)numericUpDown2.Value, color.B);
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            Color color = ShapeColor;
            ShapeColor = Color.FromArgb(color.R, color.G, (int)numericUpDown3.Value);
        }
    }
}
