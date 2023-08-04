using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0928_실습
{
    /// <summary>
    /// 실행 흐름을 담당하는 클래스
    /// </summary>
    class Application
    {
        #region 싱글톤 : 하나의 객체만 만들수 있는 클래스
        private Application() { }

        static Application()  //정적 생성자(최초 한번만)
        {
            Singleton = new Application();//단일체 생성
        }
        static public Application Singleton { get; private set; }
        #endregion          

        private MemberManager mm = MemberManager.Singleton;

        private MemberViewer mv = new MemberViewer();       //<-----------

        public void Run()
        {
            while(true)
            {
                Console.Clear();                
                MenuPrint();
                ConsoleKey key = Console.ReadKey().Key;
                Console.Write("\b");
                switch (key)
                {                  
                    case ConsoleKey.Escape: return;
                    case ConsoleKey.D1: mm.AddMember();     break;
                    case ConsoleKey.D2: mm.DelMember();     break;
                    case ConsoleKey.D3: mm.SelMember();     break;
                    case ConsoleKey.D4: mm.UpMember();      break;
                }
                Console.ReadKey();
            }
        }

        private void MenuPrint()
        {
            Console.WriteLine("--------------------------------------------------");
            Console.WriteLine("[ESC] 프로그램 종료");
            Console.WriteLine("[1] 회원 추가");
            Console.WriteLine("[2] 회원 삭제");
            Console.WriteLine("[3] 회원 검색");
            Console.WriteLine("[4] 회원 수정");
            Console.WriteLine("--------------------------------------------------");
        }
    }
}
