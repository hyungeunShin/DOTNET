using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace _1019
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        private void Window_MouseMove(object sender, MouseEventArgs e)
        {
            if(canvas.IsMouseOver)
            {
                this.Title = "Canvas위에 마우스 있다";

                if (canvas.IsMouseDirectlyOver == false)
                    Title += " + Canvas의 자식인 Ellipse 위에 있음";
            }
            else
            {
                this.Title = "Canvas위에 마우스 없다";
            }
        }
    }
}
