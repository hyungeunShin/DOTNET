using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0928_실습
{
    /// <summary>
    /// AddMember에 추가시 필요한 정보를 사용자 입력
    /// </summary>
    static class InputAddMember
    {
        public static Member Input()
        {
            Console.WriteLine("이름을 입력하세요.");
            string name = Console.ReadLine();

            Console.WriteLine("주소를 입력하세요.");
            string addr = Console.ReadLine();

            return new Member(name, addr);
        }
    }
}
