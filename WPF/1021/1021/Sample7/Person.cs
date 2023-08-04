using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Data;

namespace _1021.Sample7
{
    class Person : INotifyPropertyChanged               //<---1)
    {
        public event PropertyChangedEventHandler PropertyChanged;   //<---2)

        #region 프로퍼티가 변경되었을 때 WPF 바인딩 시스템에 통지 
        private int? shortNumber;
        public int? ShortNumber
        {
            get { return shortNumber; }
            set
            {
                shortNumber = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("ShortNumber"));  //<-----
            }
        }

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

        private bool? male;
        public bool? Male
        {
            get { return male; }
            set
            {
                male = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Male"));  //<-----
            }
        }

        #endregion 

        public Person() { }
        public Person(int? shortnumber, string name, string phone, int age, bool? male)
        {
            ShortNumber = shortnumber;
            Name = name;
            Phone = phone;
            Age = age;
            Male = male;
        }        
    }

    //예외처리클래스 등록
    public class AgeValidationRule : ValidationRule
    {
        public int Min { get; set; }
        public int Max { get; set; }

        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {            
            try
            {
                int age = int.Parse((string)value);

                if (Min > age || age > Max)
                    throw new Exception(string.Format("나이는 {0}~{1}사이 입력 가능", Min, Max));

                return ValidationResult.ValidResult;    //정상.
            }
            catch(Exception ex)
            {
                return new ValidationResult(false, ex.Message);
            }
        }
    }


    //형식변환기 등록!!!!
    [ValueConversion(/* 원본 형식 */ typeof(bool), /* 대상 형식 */ typeof(bool))]
    public class MaleToFemaleConverter : IValueConverter
    {
        // 데이터 속성을 UI 속성으로 변경할 때
        public object Convert(object value, Type targetType, object parameter,System.Globalization.CultureInfo culture)
        {
            if (targetType != typeof(bool?))
                return null;
            bool? male = (bool?)value;
            if (male == null)
                return null;
            else
                return !(bool?)value;
        }
        // UI 속성을 데이터 속성으로 변경할 때
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            if (targetType != typeof(bool?))
                return null;
            bool? male = (bool?)value;
            if (male == null)
                return null;
            else
                return !(bool?)value;
        }
    }

    [ValueConversion(/* 원본 형식 */ typeof(bool), /* 대상 형식 */ typeof(string))]
    public class BoolToStringConverter : IValueConverter
    {
        // 데이터 속성을 UI 속성으로 변경할 때
        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            bool? male = (bool?)value;
            if (male == true)
                return "남성";
            else if (male == false)
                return "여성";
            else if (male == null)
                return "";
            else
                return "";
        }
        // UI 속성을 데이터 속성으로 변경할 때
        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string male = (string)value;
            if (male == "남성")
                return true;
            else if (male == "여성")
                return false;
            else
                return null;
        }
    }
}
