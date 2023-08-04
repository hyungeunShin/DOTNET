using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/// <summary>
/// 인자 클래스 정의, 델리게이트 정의
/// </summary>
namespace _0928_실습
{
    #region AddMember에 대한 정의
    public class AddMemberEventArgs : EventArgs
    {
        public string Name        { get;            private set;        }
        public string Addr        { get;            private set;        }
        public Member Member      { get;            private set;     }
        
        public AddMemberEventArgs(Member member)
        {
            Name = member.Name;
            Addr = member.Addr;
            this.Member = member;
        }
    }

    public delegate void AddMemberEvent(object obj, AddMemberEventArgs e);
    #endregion

    #region DelMember에 대한 정의
    public class DelMemberEventArgs : EventArgs
    {
        public string Name { get; private set; }

        public DelMemberEventArgs(string name)
        {
            Name = name;
        }
    }

    public delegate void DelMemberEvent(object obj, DelMemberEventArgs e);

    #endregion
}
