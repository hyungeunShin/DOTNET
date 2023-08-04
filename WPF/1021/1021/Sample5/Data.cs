using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1021.Sample5
{
    class Data : INotifyPropertyChanged               //<---1)
    {
        public event PropertyChangedEventHandler PropertyChanged;   //<---2)

        #region 프로퍼티가 변경되었을 때 WPF 바인딩 시스템에 통지 
        private string message;
        public string Message 
        { 
            get { return message; } 
            set {
                message = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Message"));  //<-----
            }
        }       

        private int? number;
        public int? Number
        {
            get { return number; }
            set
            {
                number = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Number"));  //<-----
            }
        }

        #endregion 

        public Data() { }
        public Data(string name,int age)
        {
            Message = name;
            Number = age;
        }        
    }
}
