using System;
using System.Collections.Generic;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1013_LINQ
{
    public partial class Form1 : Form
    {
        private List<Member> members = new List<Member>();        

        public Form1()
        {
            InitializeComponent();
            members.Add(new Member("홍길동", 10));
            members.Add(new Member("김길동", 30));
            members.Add(new Member("이길동", 12));
            members.Add(new Member("최길동", 12));
            members.Add(new Member("공길동", 20));
            members.Add(new Member("허길동", 21));
            ListViewPrint();
            ListViewPrint3(listView3, members);
            ListViewPrint3(listView5, members);
            ListViewPrint3(listView7, members);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            comboBox1.SelectedIndex = 0;           
        }

        private void ListViewPrint3(ListView view, IEnumerable<Member> members)
        {
            view.Items.Clear();

            foreach (Member mem in members)
            {
                view.Items.Add(new ListViewItem(new string[] { mem.Name, mem.Age.ToString() }));
            }
        }

        #region 첫번째 페이지 람다식을 활용한 정렬

        //저장버튼 클릭
        private void button1_Click(object sender, EventArgs e)
        {
            if(textBox1.Text != "" || textBox2.Text != "")
            {
                Member mem = new Member(textBox1.Text, int.Parse(textBox2.Text));
                members.Add(mem);
                textBox1.Text = "";
                textBox2.Text = "";
                ListViewPrint();
            }
        }

        //정렬버튼 클릭
        private void button2_Click(object sender, EventArgs e)
        {
            Member[] membercopys = new Member[members.Count];
            members.CopyTo(membercopys);

            if(comboBox1.SelectedIndex == 1)//이름(오름차순) 
            {
                Array.Sort<Member>(membercopys,
                    (mem1, mem2) => { return mem1.Name.CompareTo(mem2.Name);}                    
                    );
            }
            else if (comboBox1.SelectedIndex == 2)//이름(내림차순)
            {
                Array.Sort<Member>(membercopys,
                    (mem1, mem2) =>{return mem2.Name.CompareTo(mem1.Name);}
                    );
            }
            else if (comboBox1.SelectedIndex == 3)//나이(오름차순)
            {
                Array.Sort<Member>(membercopys,
                    (mem1, mem2) => { return mem1.Age - mem2.Age; }
                    );
            }
            else if (comboBox1.SelectedIndex == 4)//나이(내림차순)
            {
                Array.Sort<Member>(membercopys,
                    (mem1, mem2) => { return mem2.Age - mem1.Age; }
                    );
            }
            ListViewSortPrint(membercopys);

        }

        //정렬결과 출력 함수
        private void ListViewSortPrint(Member[] members)
        {
            listView2.Items.Clear();

            foreach (Member mem in members)
            {
                listView2.Items.Add(new ListViewItem(new string[] { mem.Name, mem.Age.ToString() }));
            }
        }

        private void ListViewPrint()
        {
            listView1.Items.Clear();

            foreach(Member mem in members)
            {
                listView1.Items.Add(new ListViewItem(new string[] { mem.Name, mem.Age.ToString() }));
            }
        }

        #endregion

        #region 두번째 페이지 LINQ를 활용한 정렬

        //정렬버튼 클릭
        private void button3_Click(object sender, EventArgs e)
        {
            //Member[] membercopys;// = new Member[members.Count];           
            //membercopys = members.ToArray(); 
            if(comboBox2.SelectedIndex == 0)
            {
                var members1 = from data in members
                               select data;
                ListViewPrint3(listView4, members1);
            }
            else if (comboBox2.SelectedIndex == 1)//이름(오름차순) 
            {
                var members1 = from data in members
                               orderby data.Name
                               select data;
                ListViewPrint3(listView4, members1);
            }
            else if (comboBox2.SelectedIndex == 2)//이름(내림차순)
            {
                var members1 = from data in members
                               orderby data.Name descending
                               select data;
                ListViewPrint3(listView4, members1);
            }
            else if (comboBox2.SelectedIndex == 3)//나이(오름차순)
            {
                var members1 = from data in members
                               orderby data.Age
                               select data;
                ListViewPrint3(listView4, members1);
            }
            else if (comboBox2.SelectedIndex == 4)//나이(내림차순)
            {
                var members1 = from data in members
                               orderby data.Age descending
                               select data;
                ListViewPrint3(listView4, members1);
            }
            
        }

        //private void ListViewPrint1(ListView view, ICollection<Member> members)
        //{
        //    view.Items.Clear();

        //    foreach (Member mem in members)
        //    {
        //        view.Items.Add(new ListViewItem(new string[] { mem.Name, mem.Age.ToString() }));
        //    }
        //}
        
        //private void ListViewPrint2(ListView view, IOrderedEnumerable<Member>members)
        //{
        //    view.Items.Clear();

        //    foreach (Member mem in members)
        //    {
        //        view.Items.Add(new ListViewItem(new string[] { mem.Name, mem.Age.ToString() }));
        //    }
        //}

       
        #endregion

        #region 세번째 페이지 LINQ를 활용한 필터링

        //필터링버튼 클릭
        private void button4_Click(object sender, EventArgs e)
        {
            if( radioButton1.Checked == true) //이름
            {
                string name = textBox3.Text;

                var result = from data in members
                             where data.Name == name
                             select data;
                ListViewPrint3(listView6, result);
            }
            else //나이보다 많은사람을 오름차순 정렬해줘(나이를 기준으로)
            {
                int age = int.Parse(textBox3.Text);

                var result = from data in members
                             where data.Age > age
                             orderby data.Age
                             select data;

                ListViewPrint3(listView6, result);
            }

        }
        #endregion

        #region 네번째 페이지 LINQ를 활용한 그룹핑
        private void button5_Click(object sender, EventArgs e)
        {
            int age = int.Parse(textBox4.Text);
            var result = from member in members
                         //orderby member.Age
                         group member by member.Age < age into g
                         select new { GroupKey = g.Key, members = g };

            int check = 1;
            foreach (var Group in result)  //2개의 컬렉션이 저장!
            {
                List<Member> temp = new List<Member>();
                foreach (var mem in Group.members)
                {
                    temp.Add(new Member(mem.Name, mem.Age));
                }
                if (check == 1)
                {
                    ListViewPrint3(listView8, temp);
                    check++;
                }
                else
                    ListViewPrint3(listView9, temp);
            }

            //foreach (var Group in result)  //2개의 컬렉션이 저장!
            //{
            //    MessageBox.Show(string.Format("나이가 {0}미만? : {1}", age, Group.GroupKey));
            //    foreach (var mem in Group.members)
            //    {
            //        MessageBox.Show(string.Format(" {0}, {1}", mem.Name, mem.Age));
            //    }
            //}
        }

        //min, max, average등의 결과 보기
        private void button6_Click(object sender, EventArgs e)
        {
            var heightStat = from member in members
                             select new
                             {
                                 AgeMax = members.Max<Member>(a => a.Age),
                                 AgeMin = members.Min<Member>(a => a.Age),
                                 AgeAverage = members.Average(a => a.Age)
                             };

            foreach (var item in heightStat)
            {
                label6.Text = item.AgeMax + ", ";
                label6.Text += item.AgeMin + ", ";
                label6.Text += item.AgeAverage;
            }
        }
        #endregion

    }
}
