using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1022_계좌관리.Bank
{
    class BankControl
    {
        #region 싱글톤
        private BankControl() { }
        static BankControl()
        {
            Singleton = new BankControl();

        }
        static public BankControl Singleton { get; private set; }
        #endregion

        private BankContainer accounts = new BankContainer();
        public BankContainer Accounts {  get { return accounts; } }
    }
}
