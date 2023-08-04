using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1021.Sample9_1
{
    //class People : List<Person>
    class People : ObservableCollection<Person>
    {
        public People()
        {
            Add(new Person(1, "홍길동", "010-1111-1111", 10, true));
            Add(new Person(2, "일지매", "010-2222-2222", 20, false));
            Add(new Person(3, "임꺽정", "010-3333-3333", 30, true));            
        }
    }
}
