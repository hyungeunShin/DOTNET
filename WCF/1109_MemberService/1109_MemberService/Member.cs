using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.Text;
using System.Threading.Tasks;

namespace _1109_MemberService
{
    [DataContract]
    class Member
    {
        [DataMember]
        public int MNumber { get; set; }

        [DataMember]
        public string MName { get; set; }

        [DataMember]
        public string MPhone { get; set; }

        [DataMember]
        public string GName { get; set; }

        [DataMember]
        public int GNumber { get; set; }


        public Member(int mnumber, string mname, string phone, int gnumber)
        {
            MNumber = mnumber;
            MName = mname;
            MPhone = phone;
            GNumber = gnumber;
        }

        public Member(int mnumber, string mname, string phone, string gname, int gnumber)
        {
            MNumber = mnumber;
            MName = mname;
            MPhone = phone;
            GName = gname;
            GNumber = gnumber;
        }

    }
}
