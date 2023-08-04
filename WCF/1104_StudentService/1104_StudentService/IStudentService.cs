using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.ServiceModel;
using System.Text;

namespace _1104_StudentService
{
    [ServiceContract]
    interface IStudentService
    {
        [OperationContract]
        bool InsertMember(string name, int grade, string major);

        [OperationContract]
        bool DeleteMember(int number);

        [OperationContract]
        bool UpdateMember(int number, int grade);

        [OperationContract]
        List<Student> SelectAll();

        [OperationContract]
        DataTable SelectAll_Table();

        [OperationContract]
        Student SelectMember(int number);

    }
}
