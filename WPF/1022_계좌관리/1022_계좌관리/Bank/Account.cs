using System;
using System.ComponentModel;
using System.Globalization;
using System.Windows.Controls;

namespace _1022_계좌관리.Bank
{
    class Account : INotifyPropertyChanged               
    {
        public event PropertyChangedEventHandler PropertyChanged;   

        #region 프로퍼티가 변경되었을 때 WPF 바인딩 시스템에 통지 
        private int number;
        public int Number
        {
            get { return number; }
            set
            {
                number = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Number"));  //<-----
            }
        }

        private string name;
        public string Name
        {
            get { return name; }
            set
            {
                name = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Name"));  //<-----
            }
        }

        private int balance;
        public int Balance
        {
            get { return balance; }
            set
            {
                balance = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("Balance"));  //<-----
            }
        }

        private DateTime newTime;
        public DateTime NewTime
        {
            get { return newTime; }
            set
            {
                newTime = value;
                if (PropertyChanged != null)
                    PropertyChanged(this, new PropertyChangedEventArgs("NewTime"));  //<-----
            }
        }
               

        #endregion 

        public Account() { }
        public Account(int number, string name) : this(number, name, 0)
        {
        }

        public Account(int number, string name, int balance) 
        {
            Number = number;
            Name = name;
            Balance = balance;
            NewTime = DateTime.Now;
        }
   
        public void InputMoney(int money)
        {
            Balance += money;
        }

        public void OutputMoney(int money)
        {
            if (money > Balance)
                return;
            Balance -= money;
        }
    }

    //예외처리클래스 등록
    public class MoneyValidation : ValidationRule
    {
        public override ValidationResult Validate(object value, CultureInfo cultureInfo)
        {
            try
            {
                int money = int.Parse((string)value);

                if (money <= 0)
                    throw new Exception(string.Format("마이너스 금액 입력 불가"));

                return ValidationResult.ValidResult;    //정상.
            }
            catch (Exception ex)
            {
                return new ValidationResult(false, ex.Message);
            }
        }
    }

}
