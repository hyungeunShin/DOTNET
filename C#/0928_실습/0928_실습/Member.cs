using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0928_실습
{
    /// <summary>
    /// Member 데이터 클래스
    /// </summary>
    public class Member
    {
        public string Name        {            get;            private set;        }
        public string Addr        {            get;            set;                }

        public Member(string name, string addr)
        {
            Name = name;
            Addr = addr;
        }
    }
}
