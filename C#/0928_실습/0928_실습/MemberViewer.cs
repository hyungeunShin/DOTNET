using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0928_실습
{
    /// <summary>
    /// 게시자(이벤트 핸들러 작성, 핸들러를 이벤트에 등록)
    /// </summary>
    class MemberViewer
    {
        public MemberViewer()
        {
            MemberManager mm = MemberManager.Singleton;

            //이벤트 처리기 등록
            mm.AddMemberEventHandler += new AddMemberEvent(OnAddMemberEventHandler);
            mm.DelMemberEventHandler += OnDelMemberEventHandler;
        }

        #region 이벤트 핸들러
        void OnAddMemberEventHandler(object obj, AddMemberEventArgs e)
        {
            Console.WriteLine("회원이 추가되었습니다.");
            Console.WriteLine("이름:{0} 주소:{1}", e.Name, e.Addr);
        }

        void OnDelMemberEventHandler(object obj, DelMemberEventArgs e)
        {
            Console.WriteLine("회원이 삭제되었습니다.");
            Console.WriteLine("이름:{0} ", e.Name);
        }
        #endregion 
    }
}
