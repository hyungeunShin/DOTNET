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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //시작점(A)
        private void label1_MouseDown(object sender, MouseEventArgs e)
        {
            DragDropEffects effect = ((Control)sender).DoDragDrop(sender, DragDropEffects.Move);
            //if (effect == DragDropEffects.Move)
            //{
            //    Label myLabel = sender as Label;           

            //}
        }

        //끝점(B)
        private void panel1_DragDrop(object sender, DragEventArgs e)
        {
            //MessageBox.Show("TEST");
            this.Text = "패널1";
            //1. 드래그 시작 라벨(A)
            Control mycontrol = (Control)e.Data.GetData(typeof(Label));
            //2. 드래그를 처리할 패널(B)
            Panel panel = (Panel)sender;

            //무엇을 할 것인가?
            panel.Controls.Add(mycontrol);
            mycontrol.Location = panel1.PointToClient(new Point(e.X, e.Y));
            this.Text = "패널2";
        }

        private void panel1_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(typeof(Label)))
            {
                e.Effect = DragDropEffects.Move;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }

        }

        int i = 0;
        private void label1_GiveFeedback(object sender, GiveFeedbackEventArgs e)
        {
            this.Text = e.Effect.ToString() + i++;
        }


    }
}
