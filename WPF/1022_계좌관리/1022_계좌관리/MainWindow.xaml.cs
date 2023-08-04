using _1022_계좌관리.Bank;
using System;
using System.Collections.Generic;
using System.ComponentModel;
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

namespace _1022_계좌관리
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            grid.DataContext = BankControl.Singleton.Accounts;
        }

        //계좌 개설
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                Account acc = (Account)FindResource("newdeleteAcc");
                BankControl.Singleton.Accounts.Add(acc);
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        //계좌 삭제
        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            try
            {
                BankContainer con = BankControl.Singleton.Accounts;
                Account acc = (Account)FindResource("newdeleteAcc");
                if (con.Remove(con.Find(acc.Number)) == false)
                    throw new Exception("없는 계좌번호입니다.");
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        //입금
        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            try
            {
                BankContainer con = BankControl.Singleton.Accounts;
                Account acc = (Account)FindResource("inoutAcc");
                con.Input(acc.Number, acc.Balance);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        //출금
        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            try
            {
                BankContainer con = BankControl.Singleton.Accounts;
                Account acc = (Account)FindResource("inoutAcc");
                con.Oupput(acc.Number, acc.Balance);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
