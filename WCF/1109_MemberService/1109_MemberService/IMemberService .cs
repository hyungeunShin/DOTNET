using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1109_MemberService
{
    [ServiceContract]
    interface IMemberService
    {
        [OperationContract]
        bool Insert(string name, string phone);

        [OperationContract]
        bool Delete(int number);

        [OperationContract]
        bool update(int gnumber, int mnumber);

        [OperationContract]
        DataTable SelectAll_Table();

        //[OperationContract]
        //List<Member> Select_All();

        [OperationContract]
        Member Select_Number(int mnumber);

        [OperationContract]
        DataTable Select_Group(int gnumber);

    }
}
