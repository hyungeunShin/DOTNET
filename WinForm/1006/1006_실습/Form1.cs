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
    public partial class Form1 : Form
    {
        //설정 정보
        private Shape curShape = new Shape("-", ShapeType.ELLIPSE, Color.Aqua, new Point(10, 20));

        public Shape CurShape
        {
            get { return curShape; }
            set { curShape = value; }
        }
     
        public Form1()
        {
            InitializeComponent();
            //컨트롤에 이벤트가 전달되기 전에 미리 키 이벤트를 받겠다는 표현
            this.KeyPreview = true;
        }

        #region 메뉴 핸들러

        private void 다른이름으로저장SToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 불러오기LToolStripMenuItem_Click(object sender, EventArgs e)
        {

        }

        private void 프로그램종료XToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void 등록IToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "등록 기능을 선택하였습니다.";

            if (Form1UI.InputShape(curShape) == true)
            {
                ShapeControl.Singleton.Add(
                    CurShape.Name, CurShape.ShapeType, CurShape.BackColor, CurShape.ShapePoint);
                Form1UI.ComboBoxInit(comboBox1, ShapeControl.Singleton.Shapes);
                Invalidate();
            }
        }

        private void 삭제DToolStripMenuItem_Click(object sender, EventArgs e)
        {
            toolStripStatusLabel1.Text = "삭제 기능을 선택하셨습니다.";
        }
        #endregion

        #region 메뉴 상태 관리 핸들러
        private void menuStrip1_MenuActivate(object sender, EventArgs e)
        {
            //굵게ToolStripMenuItem.Checked = (PenWidth == 5);            
            //파란색ToolStripMenuItem.Enabled = (Shape != eShape.LINE);
            다른이름으로저장SToolStripMenuItem.Enabled = false;
            불러오기LToolStripMenuItem.Enabled = false;
        }
        #endregion

        #region 타이머 핸들러
        private void timer1_Tick(object sender, EventArgs e)
        {
            DateTime dt = DateTime.Now;
            toolStripStatusLabel2.Text = 
                string.Format("{0:0#}:{1:0#}:{2:0#}", dt.Hour, dt.Minute, dt.Second);  
        }
        #endregion

        #region Window 핸들러
        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Start();
            timer1_Tick(sender, e);
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            timer1.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        { 
            ShapeControl.Singleton.PrintAll(e.Graphics);
        }
        
        #endregion

        //방향 이동
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            ShapeControl.Singleton.MoveShapeAll(e.KeyCode);
            Invalidate();
        }        


        //입력 
        private void button1_Click(object sender, EventArgs e)
        {
            string name = (string)comboBox1.SelectedItem;
            ShapeControl.Singleton.MessagePrint(name, textBox1.Text);
            Invalidate();
        }
    }
}
