using System;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;

namespace _1007_Sample
{
    class DragDropHandler
    {        
        private Control myparent = null;  // Form

        private bool isDragging = false;
        private Point offset;
        public DragDropHandler(Control myparent)
        {
            this.myparent = myparent;
        }
        
        #region DragDropHandler 멤버
        public void DragDrop_MouseDown(object sender, MouseEventArgs e)
        {
            Control mycontrol = (Control)sender;
            this.isDragging = true;
            this.offset = new Point(e.X, e.Y);
            mycontrol.BringToFront();
        }
        public void DragDrop_MouseMove(object sender, MouseEventArgs e)
        {
            Control mycontrol = (Control)sender;
            if (this.isDragging == true)
            {
                String str = String.Format("e.x={0},e.y={1} offset.x={2},offset.y={3} my.x={4},my.y={5}", 
                    e.X, e.Y, offset.X, offset.Y, mycontrol.Left, mycontrol.Top);
                Debug.WriteLine(str); //디버깅할 때 출력
                this.myparent.Text = str;

                mycontrol.Left = mycontrol.Left + (e.X - offset.X);
                mycontrol.Top = mycontrol.Top + (e.Y - offset.Y);
            }
            else
            {
                Console.Write("A");
            }
        }
        public void DragDrop_MouseUp(object sender, MouseEventArgs e)
        {
            this.isDragging = false;
        }
        
        public void DragDrop_AddControl(Control sender)
        {
            sender.MouseDown += this.DragDrop_MouseDown;
            sender.MouseUp += this.DragDrop_MouseUp;
            sender.MouseMove += this.DragDrop_MouseMove;
        }
        #endregion
    }

}
    