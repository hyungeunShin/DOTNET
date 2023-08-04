using System;
using System.Collections.Generic;

namespace _0927_실습
{
    class AccountControl
    {
		private List<Account> accounts = new List<Account>();

		public AccountControl()
		{
			
		}
				
		public void PrintAll()
		{
			Console.WriteLine("저장개수 : " + accounts.Count);
			
			foreach(Account acc in accounts)
			{
				acc.Print();
				Console.WriteLine();
			}
			Console.WriteLine();
		}

		public void Insert()
		{
			try
			{
				int accnumber = MyLibrary.InputInteger("계좌번호");
				string name = MyLibrary.InputString("이름");
				int balance = MyLibrary.InputInteger("입금액");

				Account acc = new Account(accnumber, name, balance);

				accounts.Add(acc);
				Console.WriteLine("저장 성공");
			}
			catch (Exception ex)
			{
				Console.WriteLine("저장 실패 : " + ex.Message);
			}
		}

        #region 검색-전통적 방식
        public void Select1()
		{
			try
			{
				int accnumber = MyLibrary.InputInteger("계좌번호");
				int idx = NumberToIdx(accnumber);
				accounts[idx].Println();
			}
			catch(Exception ex)
            {
				Console.WriteLine("오류 : " + ex.Message);
            }
		}
		private int NumberToIdx(int value)
		{
			for (int i = 0; i < accounts.Count; i++)
			{
				Account acc = accounts[i];
				if (acc.AccId == value)
					return i;
			}
			throw new Exception("해당 계좌번호는 존재하지 않습니다.");
		}
        #endregion

        #region -C#의 find 함수 활용 
		public void Select2()  //람다식....
        {
			try
			{
				int accnumber = MyLibrary.InputInteger("계좌번호");
				number = accnumber; 
				Account acc = accounts.Find(FindNumber); //함수 전달
				acc.Println();
			}
			catch (Exception ex)
			{
				Console.WriteLine("오류 : " + ex.Message);
			}
		}
		static int number = 0;	//FindNumber 함수에서 사용.!
		//함수
		private static bool FindNumber(Account acc)
        {
			return (acc.AccId == number);
        }

        #endregion 
        		
		//전통적
		public void Update_Input()
        {
            try
            {
                int number = MyLibrary.InputInteger("계좌번호");
                int money = MyLibrary.InputInteger("입금액");

                int idx = NumberToIdx(number);
                accounts[idx].AddMoney(money);
                Console.WriteLine("입금되었습니다.");
            }
            catch (Exception ex)
            {
				Console.WriteLine("에러 : " + ex.Message);
            }
        }

		public void Update_Output()
		{
			try
			{
				int number = MyLibrary.InputInteger("계좌번호");
				int money = MyLibrary.InputInteger("출금액");

				int idx = NumberToIdx(number);
				accounts[idx].MinMoney(money);
				Console.WriteLine("출금되었습니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("에러 : " + ex.Message);
			}
		}
		
		//find
		public void Delete()
		{
			try
			{
				int accnumber = MyLibrary.InputInteger("계좌번호");
				number = accnumber;
				Account acc = accounts.Find(FindNumber); //함수 전달
				if (acc == null)
					throw new Exception("없다");
				accounts.Remove(acc);				
				Console.WriteLine("삭제되었습니다.");
			}
			catch (Exception ex)
			{
				Console.WriteLine("오류 : " + ex.Message);
			}
		}		
	
		public void Sort_Id()
        {
			accounts.Sort();	//Account 클래스에 정의된 ID로 정렬(오름차순)
        }

		public void Sort_Name()
        {
			accounts.Sort(new NameComparer());
			
        }

		public void Sort_Balance()
        {
			accounts.Sort(new BalanceComparer());
		}
	}
}

/*
int accnumber = MyLibrary.InputInteger("계좌번호");
number = accnumber; 
Account acc = accounts.Find(FindNumber); //함수 전달
Console.WriteLine("오류 : " + ex.Message);


static int number = 0;	//FindNumber 함수에서 사용.!
//함수
private static bool FindNumber(Account acc)
{
	return (acc.AccId == number);
}

//라이브러리의 FIND함수
Account Find( bool FindNumber(Account) )
{
  for(Account acc in accounts)
  {
		if(FindNumber(acc) == true)		//반복적으로 함수가 호출.
		 return acc;
  }
  return null;
}
*/