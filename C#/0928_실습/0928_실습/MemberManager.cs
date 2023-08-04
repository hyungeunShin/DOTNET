using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0928_실습
{
    /// <summary>
    /// Member 관리 클래스 
    /// </summary>
    class MemberManager
    {
        #region 싱글톤 : 하나의 객체만 만들수 있는 클래스
        //객체를 외부에서 생성할 수 없도록 생성자를 은닉
        //내부에서 하나의 객체를 생성하는 코드를 작성
        //생성된 객체를 외부로 노출!
        private MemberManager() { }

        static MemberManager()  //정적 생성자(최초 한번만)
        {
            Console.WriteLine("정적 생성자");
            Singleton = new MemberManager();//단일체 생성
        }
        static public MemberManager Singleton { get; private set; }

        #endregion

        public event AddMemberEvent AddMemberEventHandler = null;
        public event DelMemberEvent DelMemberEventHandler = null;

        //저장소(key:이름, value:Member)
        Dictionary<string, Member> members = new Dictionary<string, Member>();

        #region 기능메서드
        public void AddMember()
        {
            //1. 정보 입력 & 2. 객체 생성
            Member mem = InputAddMember.Input();

            //3. 저장
            if (members.ContainsKey(mem.Name))
            {
                Console.WriteLine("이미 존재하는 이름입니다.");
                return;
            }
            
            members.Add(mem.Name, mem);
            Console.WriteLine("저장되었습니다.");

            if (AddMemberEventHandler != null) //이벤트 핸들러가 등록되어 있을 때
            {
                AddMemberEventHandler(this, new AddMemberEventArgs(mem));
            }
        }

        public void DelMember()
        {
            //1. 정보 입력
            string name = InputDelMember.Input();

            //3. 체크
            if (members.ContainsKey(name) == false)
            {
                Console.WriteLine("없는 이름입니다.");
                return;
            }

            if (members.Remove(name) == true)
            {
                Console.WriteLine("삭제 되었습니다.");

                if (DelMemberEventHandler != null) //이벤트 핸들러가 등록되어 있을 때
                {
                    DelMemberEventHandler(this, new DelMemberEventArgs(name));
                }
            }
            else
                Console.WriteLine("삭제 되지 않았습니다.");
        }
        
        public void SelMember()
        {
            try
            {
                //1. 정보 입력
                string name = InputDelMember.Input();

                //2. 정보 획득
                Member mem = members[name];

                //3. 결과 출력
                Console.WriteLine("[이름] " + mem.Name);
                Console.WriteLine("[주소] " + mem.Addr);
            }
            catch(Exception ex)
            {
                Console.WriteLine("오류 : " + ex.Message);
            }
        }
        
        public void UpMember()
        {            
            try
            {
                //1. 정보 입력
                Member mem = InputAddMember.Input();

                //2. 정보 획득
                Member rmem = members[mem.Name];

                //3. 연산
                rmem.Addr = mem.Addr;

                //4. 결과 출력
                Console.WriteLine("수정되었습니다.");
            }
            catch (Exception ex)
            {
                Console.WriteLine("오류 : " + ex.Message);
            }
        }

        #endregion

    }
}
