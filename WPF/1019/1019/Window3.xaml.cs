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
    /// Window3.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window3 : Window
    {
        public Window3()
        {
            InitializeComponent();
        }

        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            this.Title = e.Key.ToString();           
        }

        private void canvas_MouseMove(object sender, MouseEventArgs e)
        {
            if( (Keyboard.Modifiers & ModifierKeys.Shift) != 0)
            //if( Keyboard.IsKeyDown(Key.LeftShift)) //조합키
            {
                Ellipse ell = new Ellipse();
                ell.Width = 10;
                ell.Height = 10;
                ell.Stroke = new SolidColorBrush(Colors.Blue);
                ell.Fill = new SolidColorBrush(Colors.Yellow);

                //Ellipse를 Canvas 어디에 배치할 것인지 지정한다.
                Canvas.SetLeft(ell, e.GetPosition(canvas).X);
                Canvas.SetTop(ell, e.GetPosition(canvas).Y);

                // Ellipse를 위치시킨다.(그린다.)
                canvas.Children.Add(ell);
            }
        }
    }
}
