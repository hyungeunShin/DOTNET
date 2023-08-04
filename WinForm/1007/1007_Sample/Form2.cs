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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            DragDropEffects effect = ((Control)sender).DoDragDrop(sender, DragDropEffects.Move);
        }

        private void panel1_DragDrop(object sender, DragEventArgs e)
        {
            Control mycontrol = (Control)e.Data.GetData(typeof(Button));
            Panel panel = (Panel)sender;

            panel.Controls.Add(mycontrol);
            mycontrol.Location = panel1.PointToClient(new Point(e.X, e.Y));
        }

        private void panel1_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(typeof(Button)))
            {
                e.Effect = DragDropEffects.Move;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void panel2_DragDrop(object sender, DragEventArgs e)
        {
            Control mycontrol = (Control)e.Data.GetData(typeof(Button));
            if (mycontrol == null)
            {
                mycontrol = (Control)e.Data.GetData(typeof(ListBox));
                if(mycontrol == null)
                {
                    mycontrol = (Control)e.Data.GetData(typeof(TextBox));
                }
            } 
            
            Panel panel = (Panel)sender;

            panel.Controls.Add(mycontrol);
            mycontrol.Location = panel2.PointToClient(new Point(e.X, e.Y));
        }        

        private void panel2_DragEnter(object sender, DragEventArgs e)
        {
            e.Effect = DragDropEffects.Move;
        }
    }
}
