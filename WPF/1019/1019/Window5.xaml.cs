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
//버튼은 터널링 이벤트 발생
//버블링 이벤트는 발생되지 않음
namespace _1019
{
    /// <summary>
    /// Window5.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window5 : Window
    {
        public Window5()
        {
            InitializeComponent();
        }

        //버튼에 마우스다운을 발생!
        private void Button_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Title = "Button_MOuseDown";
        }

        private void Window_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Title = "Window_MOuseDown";
        }

        //터널링
        private void Window_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            Title = "Window_Preview_MOuseDown";
        }

        private void Button_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {  
            Title = "Button_Preview_MOuseDown";
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Title = "버튼 클릭!";
        }
    }
}
