using System;
using System.Collections;
using System.Collections.Generic;

namespace _0927_실습
{
    class Account : IComparable
    {
        public int AccId                { get; private set; }
        public string Name              { get; private set; }
        public int Balance              { get; protected set; }
        public DateTime AccDateTime     { get; private set;  }
        public string AccDate           { get; private set; }
        public string AccTime           { get; private set; }

        public Account(int accid, string name) : this(accid, name, 0)
        {
            //AccId = accid;
            //Name = name;
            //Balance = 0;
        }

        public Account(int accid, string name, int balance)
        {
            AccId = accid;
            Name = name;
            Balance = balance;
            AccDateTime = DateTime.Now; //현재 날짜 시간 저장.
            AccDate = string.Format("{0:000#}-{1:0#}-{2:0#}",
                AccDateTime.Year, AccDateTime.Month, AccDateTime.Day);
            AccTime = string.Format("{0:0#}:{1:0#}:{2:0#}",
                AccDateTime.Hour, AccDateTime.Minute, AccDateTime.Second);
        }

        public virtual void AddMoney(int money)
        {
            if (money <= 0)
                throw new Exception("잘못된 금액이 전달되었습니다.");
            Balance += money;
        }

        public void MinMoney(int money)
        {
            if (money <= 0)
                throw new Exception("잘못된 금액이 전달되었습니다.");
            if (money > Balance)
                throw new Exception("잔액이 부족합니다.");
            Balance -= money;
        }

        public virtual void Print()
        {
            Console.Write("[{0}]\t{1}\t{2}원\t{3} {4}", AccId, Name, Balance, AccDate, AccTime);
        }

        public virtual void Println()
        {
            Console.WriteLine("계좌번호 : " + AccId);
            Console.WriteLine("이   름 : " + Name);
            Console.WriteLine("잔   액 : " + Balance);
            Console.WriteLine("일   시 : {0} {1}", AccDate, AccTime);
        }

        public int CompareTo(object obj)
        {
            Account acc = obj as Account;
            if (acc == null)
            {
                throw new ApplicationException("Account 개체가 아닙니다.");
            }
            return AccId - acc.AccId;   //+, 0, -
        }
    }

    //정렬 클래스 
    class NameComparer : IComparer<Account>
    {
        public int Compare(Account x, Account y)
        {
            return x.Name.CompareTo(y.Name);
        }
    }

    class BalanceComparer : IComparer<Account>
    {
        public int Compare(Account x, Account y) // IComparer에서 약속한 기능 구현
        {
            return x.Balance - y.Balance;
        }
    }

}
