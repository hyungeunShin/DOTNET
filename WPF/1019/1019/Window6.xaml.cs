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
    /// Window6.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window6 : Window
    {
        public Shape Shape { get; set; }
        
        public Window6()
        {
            InitializeComponent();

            Shape = new Shape(new Point(100, 100), 100, Color.FromRgb(255, 0, 0));

            //메뉴 UI초기화
            SetColorMenu(false, true, true);
            SetRectMenu(true, false, false);
            
            //상태바 초기화
            statuscolor.Text = Shape.ShapeColor.ToString();
            statussize.Text = Shape.ShapeSize.ToString();
            statuspoint.Text = Shape.ShapePoint.ToString();
        }

        private void MenuItem_Click(object sender, RoutedEventArgs e)
        {
            this.Close();           
        }

        //색상 변경
        private void MenuItem_Click_1(object sender, RoutedEventArgs e)
        {
            if ((MenuItem)sender == menu_Red || (MenuItem)sender == menu_Red1)
            {
                Shape.ShapeColor = Color.FromRgb(255, 0, 0);
                SetColorMenu(false, true, true);
            }
            else if ((MenuItem)sender == menu_Green || (MenuItem)sender == menu_Green1)
            {
                Shape.ShapeColor = Color.FromRgb(0, 255, 0);
                SetColorMenu(true, false, true);
            }
            else if ((MenuItem)sender == menu_Blue || (MenuItem)sender == menu_Blue1)
            {
                Shape.ShapeColor = Color.FromRgb(0, 0, 255);
                SetColorMenu(true, true, false);
            }
            rect.Fill = new SolidColorBrush(Shape.ShapeColor);
            statuscolor.Text = Shape.ShapeColor.ToString();
        }

        //색상 메뉴 UI 변경
        private void SetColorMenu(bool red, bool green, bool blue)
        {
            menu_Red.IsEnabled = menu_Red1.IsEnabled = red;
            menu_Green.IsEnabled = menu_Green1.IsEnabled = green;
            menu_Blue.IsEnabled = menu_Blue1.IsEnabled = blue;
        }

        //크기 변경
        private void menu_Rect50_Click(object sender, RoutedEventArgs e)
        {
            if ((MenuItem)sender == menu_Rect50 ||(MenuItem)sender == menu_Rect501)
            {
                Shape.ShapeSize = 50;
                SetRectMenu(true, false, false);
            }
            if ((MenuItem)sender == menu_Rect100 || (MenuItem)sender == menu_Rect1001)
            {
                Shape.ShapeSize = 100;
                SetRectMenu(false, true, false);
            }
            if ((MenuItem)sender == menu_Rect150 || (MenuItem)sender == menu_Rect1501)
            {
                Shape.ShapeSize = 150;
                SetRectMenu(false, false, true);
            }
            rect.Width = Shape.ShapeSize;
            rect.Height = Shape.ShapeSize;
            statussize.Text = Shape.ShapeSize.ToString();
        }

        private void SetRectMenu(bool r50, bool r100, bool r150)
        {
            menu_Rect50.IsChecked = menu_Rect501.IsChecked = r50;
            menu_Rect100.IsChecked = menu_Rect1001.IsChecked = r100;
            menu_Rect150.IsChecked = menu_Rect1501.IsChecked = r150;
        }

        //위치 변경
        private void Canvas_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            Shape.ShapePoint = e.GetPosition(canvas);
            Canvas.SetLeft(rect, Shape.ShapePoint.X);
            Canvas.SetTop(rect, Shape.ShapePoint.Y);

            statuspoint.Text = string.Format("{0},{1}", (int)Shape.ShapePoint.X, (int)Shape.ShapePoint.Y);
        }
    }
}
