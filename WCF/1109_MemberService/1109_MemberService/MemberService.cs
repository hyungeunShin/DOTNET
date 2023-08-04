using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1109_MemberService
{
    class MemberService : IMemberService
    {
        private SqlConnection con = new SqlConnection();

        private void DB_Open()
        {
            const string connstring = @"Server=DESKTOP-22SLDHT\SQLEXPRESS;database=WB34;uid=yhy;pwd=yhy";
            con.ConnectionString = connstring;
            con.Open();
        }

        private void DB_Close()
        {
            if (con.State == ConnectionState.Open)
            {
                con.Close();
            }
        }

        public bool Insert(string name, string phone)
        {
            DB_Open();

            try
            {
                string sql = string.Format("INSERT INTO Member(MName, MPhone )VALUES('{0}','{1}');",
                                            name, phone);
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
                DB_Close();
            }
        }

        public bool Delete(int number)
        {
            try
            {
                DB_Open();
                string sql = string.Format("DELETE from Member WHERE MNumber = {0};",
                                            number);
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
                DB_Close();
            }
        }

        public bool update(int gnumber, int mnumber)
        {
            try
            {
                DB_Open();
                string sql = string.Format("UPDATE Member SET GNumber = {0} WHERE MNumber = {1};",
                                            gnumber, mnumber);
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
                DB_Close();
            }
        }

        //그리뷰에 출력
        public DataTable SelectAll_Table()
        {
            try
            {
                DB_Open();
                string sql = "SELECT * from Member;";
                SqlDataAdapter ad = new SqlDataAdapter();
                ad.SelectCommand = new SqlCommand(sql, con);

                DataSet ds = new DataSet();
                ad.FillSchema(ds, SchemaType.Mapped);
                ad.Fill(ds);

                return ds.Tables[0];
            }
            finally
            {
                DB_Close();
            }
        }

        //Member
        //public List<Member> Select_All()
        //{
        //    try
        //    {
        //        DB_Open();
        //        string sql = "SELECT * from Member;";
        //        SqlCommand cmd = new SqlCommand(sql, con);
        //        SqlDataReader reader = cmd.ExecuteReader();

        //        List<Member> members = new List<Member>();
        //        while (reader.Read())
        //        {
        //            int number = (int)reader["MNumber"];
        //            string name = (string)reader["MName"];
        //            string phone = (string)reader["MPhone"];
        //            int gnumber = (int)reader["GNumber"];

        //            members.Add(new Member(number, name, phone, gnumber));
        //        }
        //        return members;
        //    }
        //    catch
        //    {
        //        return null;
        //    }
        //    finally
        //    {
        //        DB_Close();
        //    }
        //}

        //Member

        public Member Select_Number(int mnumber)
        {
            try
            {
                DB_Open();

                string sql = string.Format("SELECT * from Member WHERE MNumber = {0};",
                                            mnumber);
                SqlCommand cmd = new SqlCommand(sql, con);
                SqlDataReader reader = cmd.ExecuteReader();

                Member members = null;

                while (reader.Read())
                {
                    int number = (int)reader["MNumber"];
                    string name = (string)reader["MName"];
                    string phone = (string)reader["MPhone"];
                    int gnumber = (int)reader["GNumber"];

                    members = new Member(number, name, phone, gnumber);
                }
                return members;
            }
            catch
            {
                return null;
            }
            finally
            {
                DB_Close();
            }
        }

        //Member+GroupMember --> 번호, 이름, 핸드폰, 그룹번호, 그룹이름을 출력
        public DataTable Select_Group(int gnumber)
        {
            try
            {
                DB_Open();

                string sql = string.Format("SELECT MNumber, MName, MPhone, Member.GNumber,Gname from Member, MemberGroup WHERE Member.GNumber = {0} AND MemberGroup.GNumber = {0};",
                                        gnumber);
                SqlDataAdapter ad = new SqlDataAdapter();
                ad.SelectCommand = new SqlCommand(sql, con);

                DataSet ds = new DataSet();
                ad.FillSchema(ds, SchemaType.Mapped);
                ad.Fill(ds);

                return ds.Tables[0];
            }
            catch
            {
                return null;
            }
            finally
            {
                DB_Close();
            }
        }

    }
}
