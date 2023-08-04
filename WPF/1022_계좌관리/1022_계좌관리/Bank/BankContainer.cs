using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1022_계좌관리.Bank
{
    class BankContainer : ObservableCollection<Account>
    {
        //테스트용
        public BankContainer()
        {
            Add(new Account(111, "홍길동", 1000));
            Add(new Account(222, "일지매", 20000));
            Add(new Account(3333, "임꺽정", 5000));
        }

        public Account Find(int number)
        {
            foreach(Account acc in this)
            {
                if (acc.Number == number)
                    return acc;
            }
            return null;
        }
        
        public void Input(int number, int money)
        {
            Find(number).InputMoney(money);            
        }

        public void Oupput(int number, int money)
        {
            Account acc = Find(number);
            acc.OutputMoney(money);
        }
    }
}
