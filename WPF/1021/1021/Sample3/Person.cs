using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1021.Sample3
{
    class Person : INotifyPropertyChanged               //<---1)
    {
        public event PropertyChangedEventHandler PropertyChanged;   //<---2)

        #region 프로퍼티가 변경되었을 때 WPF 바인딩 시스템에 통지 
        private string name;
        public string Name 
        { 
            get { return name; } 
            set { 
                name = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Name"));  //<-----
            }
        }

        private string phone;
        public string Phone 
        { 
            get { return phone; }
            set
            {
                phone = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Phone"));  //<-----
            }
        }

        private int? age;
        public int? Age 
        {
            get { return age; }
            set
            {
                age = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Age"));  //<-----
            }
        }

        #endregion 

        public Person() { }
        public Person(string name, string phone, int age)
        {
            Name = name;
            Phone = phone;
            Age = age;
        }        
    }
}
