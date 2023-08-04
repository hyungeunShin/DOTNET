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

namespace _1021
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        //private List<Person> persons = new List<Person>();
        //컬렉션 객체
        private People people = new People();

        //컬렉션의 특정 Person을 가리키는 객체
        private Person per = null;

        public MainWindow()
        {
            InitializeComponent();

            per = people[0];

            UpdateNameToUI();
            UpdatePhoneToUI();
            UpdateAgeToUI();
            UpdateListBox();
        }

        #region 데이터의 속성 --> UI 컨트롤 속성
        private void UpdateNameToUI()
        {
            if (per == null)
            {
                name.Text = "";
                nameLabel.Content = "";                
                return;
            }
            name.Text = per.Name;
            nameLabel.Content = per.Name;
        }

        private void UpdatePhoneToUI()
        {
            if (per == null)
            {
                phone.Text = "";
                phoneLabel.Content = "";
                return;
            }
            phone.Text = per.Phone;
            phoneLabel.Content = per.Phone;
        }

        private void UpdateAgeToUI()
        {
            if (per == null)
            {
                age.Text = "";
                ageLabel.Content = "";
                return;
            }            
            age.Text = per.Age.ToString();
            ageLabel.Content = per.Age.ToString();
        }

        private void UpdateListBox()
        {
            listbox.Items.Clear();

            foreach(Person per in people)
            {
                listbox.Items.Add(per);  //per.tostring();
            }
        }

        #endregion

        #region UI 컨트롤 속성 --> 데이터의 속성
        private void name_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Name = name.Text;
            nameLabel.Content = name.Text;
        }

        private void phone_TextChanged(object sender, TextChangedEventArgs e)
        {
            //per.Phone = phone.Text;
            phoneLabel.Content = phone.Text;
        }

        private void age_TextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                // per.Age = int.Parse(age.Text);
                ageLabel.Content = int.Parse(age.Text);
                //this.Title = per.Age.ToString();
            }
            catch(Exception)
            {
            }
        }
        #endregion

        private void listbox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if(listbox.SelectedIndex >= 0)
            {
                per = people[listbox.SelectedIndex];
                //화면 갱신
                UpdateNameToUI();
                UpdatePhoneToUI();
                UpdateAgeToUI();
            }
        }

        #region 기능(Insert, Delete, Update)
        private void addButton_Click(object sender, RoutedEventArgs e)
        {
            if (name.Text == "" || phone.Text == "" || age.Text == "")
            {
                MessageBox.Show("입력하세요");
                return;
            }
            Person per = new Person(name.Text, phone.Text, int.Parse(age.Text));
            people.Add(per);
            UpdateListBox();
        }

        private void removeButton_Click(object sender, RoutedEventArgs e)
        {
            if(listbox.SelectedIndex >=0)
            {
                //데이터 갱신
                people.RemoveAt(listbox.SelectedIndex);

                if (people.Count == 0)
                    per = null;
                else
                    per = people[0];

                //화면 갱신                
                UpdateListBox();
                UpdateNameToUI();
                UpdatePhoneToUI();
                UpdateAgeToUI();
            }
        }

        private void updateButton_Click(object sender, RoutedEventArgs e)
        {
            if (name.Text == "" || phone.Text == "" || age.Text == "")
            {
                MessageBox.Show("입력하세요");
                return;
            }

            per.Name = name.Text;
            per.Phone = phone.Text;
            per.Age = int.Parse(age.Text);

            UpdateNameToUI();
            UpdatePhoneToUI();
            UpdateAgeToUI();
            UpdateListBox();
        }
        #endregion 
    }
}
