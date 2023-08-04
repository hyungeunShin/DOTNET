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
using System.Windows.Shapes;

namespace _1021.Sample9_1
{
    /// <summary>
    /// Window1.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class Window1 : Window
    {     
        public Window1()
        {
            InitializeComponent();
            
            //예외 핸들러 등록!
            Validation.AddErrorHandler(shortnumber, shortNumber_ValidationError);
            Validation.AddErrorHandler(age, shortNumber_ValidationError);

            //바인딩처리(XAML)           
        }

        private void shortNumber_ValidationError(object sender, ValidationErrorEventArgs e)
        {
            MessageBox.Show((string)e.Error.ErrorContent, "유효성 검사 실패");
            shortnumber.ToolTip = (string)e.Error.ErrorContent;
        }


        private void eraseButton_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            Person person = (Person)view.CurrentItem;
            person.ShortNumber = null;
            person.Name = "";
            person.Phone = "";
            person.Age = null;
            person.Male = null;

            //listbox.Items.Refresh();
        }

        private void prev_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            view.MoveCurrentToPrevious();
            if( view.IsCurrentBeforeFirst)
            {
                view.MoveCurrentToFirst();
            }
        }

        private void next_Click(object sender, RoutedEventArgs e)
        {
            ICollectionView view = CollectionViewSource.GetDefaultView(FindResource("people"));
            view.MoveCurrentToNext();
            if (view.IsCurrentAfterLast)
            {
                view.MoveCurrentToLast();
            }
        }

        private void removeButton_Click(object sender, RoutedEventArgs e)
        {
            People people = (People)FindResource("people");

            if(listbox.SelectedIndex >= 0)
            {
                people.RemoveAt(listbox.SelectedIndex);
            }
        }
    }
}
