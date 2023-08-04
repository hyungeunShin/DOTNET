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
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            Keyboard.Focus(this.ID);
        }

        private void LoginBtn_Click(object sender, RoutedEventArgs e)
        {
            var viewModel = (LoginViewModel)FindResource("loginview");
            if(string.IsNullOrEmpty(viewModel.LoginID))
            {
                MessageBox.Show("아이디를 입력해주세요");
                Keyboard.Focus(this.ID);
                return;
            }
            if(string.IsNullOrEmpty(viewModel.LoginPasswd))
            {
                MessageBox.Show("비밀번호를 입력해주세요");
                Keyboard.Focus(this.Passwd);
                return;
            }
            doLogin(viewModel.LoginID, viewModel.LoginPasswd);
        }
        // TextBox의 Text 속성에 바인딩할 때,포커스를 잃을 때만 소스가 업데이트 되기 때문에 문제가 발생합니다.
        //https://docs.microsoft.com/ko-kr/dotnet/api/system.windows.data.binding.updatesourcetrigger?view=netframework-4.0&f1url=%3FappId%3DDev10IDEF1%26l%3DKO-KR%26k%3Dk(SYSTEM.WINDOWS.DATA.BINDING.UPDATESOURCETRIGGER);k(TargetFrameworkMoniker-%2522.NETFRAMEWORK%252cVERSION%253dV4.0%2522);k(DevLang-CSHARP)%26rd%3Dtrue

        private bool doLogin(string id, string pw)
        {
            MessageBox.Show(string.Format("{0}, {1}", id, pw));
            return true;            
        }
    }
}
