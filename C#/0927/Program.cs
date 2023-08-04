using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0927_실습
{
    class Program
    {
		private AccountControl con = new AccountControl();

		private ConsoleKey MenuPrint()
		{
			Console.WriteLine("******************************************************");
			Console.WriteLine(" [ESC] 프로그램종료");
			Console.WriteLine(" [F1] 저장(Insert)");
			Console.WriteLine(" [F2] 검색-직접검색(Select)");
			Console.WriteLine(" [F3] 검색-C# find함수 활용(Select)");
			Console.WriteLine(" [F4] 수정-입금(Update)");
			Console.WriteLine(" [F5] 수정-출금(Update)");
			Console.WriteLine(" [F6] 삭제(Delete)");
			Console.WriteLine(" [F7] 정렬-계좌번호(SORT)");
			Console.WriteLine(" [F8] 정렬-이름(SORT)");
			Console.WriteLine(" [F9] 정렬-잔액(SORT)");
			Console.WriteLine("******************************************************");
			ConsoleKey key = Console.ReadKey().Key;
			Console.Write("\b");
			return key;
		}
		public void Init()
		{

		}
		public void Run()
		{
			while (true)
			{
				MyLibrary.ConsoleClear();

				con.PrintAll();
				switch (MenuPrint())
				{
					case ConsoleKey.F1: con.Insert();			break;
					case ConsoleKey.F2: con.Select1();			break;
					case ConsoleKey.F3: con.Select2();			break;
					case ConsoleKey.F4: con.Update_Input();		break;
					case ConsoleKey.F5: con.Update_Output();	break;
					case ConsoleKey.F6: con.Delete();			break;
					case ConsoleKey.F7: con.Sort_Id();			break;
					case ConsoleKey.F8: con.Sort_Name();		break;
					case ConsoleKey.F9: con.Sort_Balance();		break;
					case ConsoleKey.Escape: return;
				}

				MyLibrary.ConsolePause();
			}
		}
		public void Exit()
		{

		}

		static void Main(string[] args)
		{
			Program pr = new Program();

			pr.Init();
			pr.Run();
			pr.Exit();
		}
	}
}
