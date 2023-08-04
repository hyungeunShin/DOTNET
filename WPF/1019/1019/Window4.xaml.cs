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
    /// Window4.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window4 : Window
    {
        public string Msg { get; set; }
        public Window4()
        {
            InitializeComponent();
        }
        #region 버블링 (자식 -> 부모) 일반적인 메시지 흐름
        private void Label_MouseDown_1(object sender, MouseButtonEventArgs e)
        {
            Msg += "Label_버블링->";
        }

        private void StackPanel_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "StackPanel_버블링->";
        }

        private void Label_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "Label_버블링->";  
        }

        private void Canvas_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "Canvas_버블링->";
        }

        private void Window_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "Window_버블링";
            //Title = Msg; // 지금까지 발생한 라우트된 이벤트를 출력한다.
            //Msg = "";

            string msg = "sender : " + sender.GetType().ToString() + ", e.Source : " +
                e.Source.GetType().ToString();
            Title = msg;            
        }
        #endregion

        #region 터널링(부모->자식)

        private void Window_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "Window_터널링->";
        }
        private void Canvas_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "Canvas_터널링->";
        }

        private void Label_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "Label_터널링->";
        }

        private void StackPanel_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            Msg += "StackPanel_터널링->";
        }

        private void Label_PreviewMouseDown_1(object sender, MouseButtonEventArgs e)
        {
            Msg += "Label_터널링->";
        }
        #endregion


    }
}
