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
    /// Window2.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window2 : Window
    {
        public Window2()
        {
            InitializeComponent();
        }

        private void canvas_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            Point pos = e.GetPosition(canvas);

            //도형 객체 생성
            Rectangle rt = new Rectangle();
            rt.Width = 50;
            rt.Height = 50;
            rt.Stroke = new SolidColorBrush(Colors.Blue);
            rt.Fill = new SolidColorBrush(Colors.Yellow);
            //생성되는 모든 도형이 동일한 메시지 핸들러를 갖게 된다.
            rt.MouseRightButtonDown += Rt_MouseRightButtonDown;

            //canvas에 배치
            Canvas.SetLeft(rt, pos.X);
            Canvas.SetTop(rt, pos.Y);

            //canvas에 사각형을 추가(자식 엘리먼트)
            canvas.Children.Add(rt);
        }

        private void Rt_MouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            Rectangle r = (Rectangle)sender;
            r.Fill = new SolidColorBrush(Color.FromRgb(255, 0, 0));
        }
    }
}
