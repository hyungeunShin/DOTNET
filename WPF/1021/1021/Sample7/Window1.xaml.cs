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

namespace _1021.Sample7
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {
        //private Person per = new Person("홍길동", "010-1111-1111", 20);
        private Person per = null;
        public Window1()
        {
            InitializeComponent();

            per = (Person)FindResource("person");

            //예외 핸들러 등록!
            Validation.AddErrorHandler(shortnumber, shortNumber_ValidationError);
            Validation.AddErrorHandler(age, shortNumber_ValidationError);

            //바인딩처리(XAML)
            //panel.DataContext = per;
        }

        private void shortNumber_ValidationError(object sender, ValidationErrorEventArgs e)
        {
            MessageBox.Show((string)e.Error.ErrorContent, "유효성 검사 실패");
            shortnumber.ToolTip = (string)e.Error.ErrorContent;
        }


        private void eraseButton_Click(object sender, RoutedEventArgs e)
        {
            per.Name = "";
            per.Phone = "";
            per.Age = null;
        }
    }
}
