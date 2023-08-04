using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;

namespace _1104_StudentService
{
    class StudentService : IStudentService
    {
        private SqlConnection con = new SqlConnection();             

        private void Open()
        {
            const string connstring = @"Server=DESKTOP-NTTAC6K\SQLEXPRESS;database=WB34;uid=nayoun;pwd=nayoun";
            con.ConnectionString = connstring;
            con.Open();
        }

        private void Close()
        {
            if (con.State == ConnectionState.Open)
            {
                con.Close();
            }
        }

        public bool InsertMember(string name, int grade, string major)
        {
            Open();

            try
            {
                string sql = string.Format("Insert into Member values('{0}', {1}, '{2}', getdate());", name, grade, major);
                SqlCommand cmd = new SqlCommand(sql, con);
                if (cmd.ExecuteNonQuery() <= 0)
                    throw new Exception("오류");
                return true;
            }
            catch (Exception)
            {
                return false;
            }
            finally
            {
                Close();
            }
        }

        public bool DeleteMember(int number)
        {     
            try
            {
                Open();
                string sql = string.Format("delete from Member where Number = {0};", number);
                SqlCommand cmd = new SqlCommand(sql, con);
                if (cmd.ExecuteNonQuery() <= 0)
                    throw new Exception("오류");
                return true;
            }
            catch(Exception)
            {
                return false;
            }
            finally
            {
                Close();
            }
        }

        public bool UpdateMember(int number, int grade)
        {
            try
            {
                Open();
                string sql =
                string.Format("UPDATE member SET grade = {0} WHERE number = {1}; ", grade, number);
                SqlCommand cmd = new SqlCommand(sql, con);
                if (cmd.ExecuteNonQuery() <= 0)
                    throw new Exception("오류");
                return true;
            }
            catch (Exception)
            {
                return false;
            }
            finally
            {
                Close();
            }
        }


        #region Select
        public DataTable SelectAll_Table()
        {
            try
            {
                Open();
                string sql = "select * from member;";
                SqlDataAdapter ad = new SqlDataAdapter();
                ad.SelectCommand = new SqlCommand(sql, con);

                DataSet ds = new DataSet();
                ad.FillSchema(ds, SchemaType.Mapped);
                ad.Fill(ds);

                return ds.Tables[0];
            }
            finally
            {
                Close();
            }
        }

        List<Student> IStudentService.SelectAll()
        {
            try
            {
                Open();
                string sql = "select * from member;";
                SqlCommand cmd = new SqlCommand(sql, con);
                SqlDataReader reader = cmd.ExecuteReader();

                List<Student> students = new List<Student>();
                while (reader.Read())
                {                    
                    int num = (int)reader["Number"];
                    string name = (string)reader["Name"];
                    int grade = (int)reader["Grade"];
                    string major = (string)reader["Major"];
                    DateTime date = (DateTime)reader["DateTime"];

                    students.Add(new Student(num, name, grade, major, date));
                }
                return students;
            }
            finally
            {
                Close();
            }
        }

        //검색쿼리문
        public Student SelectMember(int number)
        {
            try
            {
                Open();

                string sql = string.Format("select * from Member where Number={0}", number);
                SqlCommand cmd = new SqlCommand(sql, con);
                SqlDataReader reader = cmd.ExecuteReader();

                Student stu = null;

                while (reader.Read())
                {
                    int num = (int)reader["Number"];
                    string name = (string)reader["Name"];
                    int grade = (int)reader["Grade"];
                    string major = (string)reader["Major"];
                    DateTime date = (DateTime)reader["DateTime"];

                    stu = new Student(num, name, grade, major, date);
                }
                return stu;
            }
            catch
            {
                return null;
            }
        }

        #endregion

    }
}
