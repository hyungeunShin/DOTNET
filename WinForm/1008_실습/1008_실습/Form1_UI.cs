using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1008_실습
{
    class Form1_UI
    {
        

        // 리스트뷰 초기화
        public static void ListViewInit(ListView listView, List<Student> students)
        {
            listView.Items.Clear();
           // students = students.Distinct(new DataCompare()).ToList();
            foreach (Student stu in students)
            {
                listView.Items.Add(new ListViewItem(new string[]
                           { string.Format("{0}",stu.Number), stu.Name, string.Format("{0}",stu.Stype), string.Format("{0}",stu.Grade)}));
            }
        }

        
    }
}
