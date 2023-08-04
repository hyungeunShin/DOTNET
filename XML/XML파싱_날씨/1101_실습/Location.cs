using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1101_실습
{
    class Data
    {
        public string Mode { get; private set; }
        public string TmEf { get; private set; }
        public string Wf { get; private set; }      //날씨예보
        public string Tmn { get; private set; }
        public string Tmx { get; private set; }
        public string Reliability { get; private set; }  //신뢰도
        public string RnSt { get; private set; }        //강수확률?

        public Data(string mode, string tmef, string wf, string tmn, string tmx, string reliability, string rnst)
        {
            Mode = mode;
            TmEf = tmef;
            Wf = wf;
            Tmn = tmn;
            Tmx = tmx;
            Reliability = reliability;
            RnSt = rnst;
        }

        public static Data MakeData(XmlReader reader)
        {
            reader.ReadToDescendant("mode");
            string mode = reader.ReadElementContentAsString("mode", "");

            reader.ReadToNextSibling("tmEf");
            string tmEf = reader.ReadElementContentAsString("tmEf", "");

            reader.ReadToNextSibling("wf");
            string wf = reader.ReadElementContentAsString("wf", "");

            reader.ReadToNextSibling("tmn");
            string tmn = reader.ReadElementContentAsString("tmn", "");

            reader.ReadToNextSibling("tmx");
            string tmx = reader.ReadElementContentAsString("tmx", "");

            reader.ReadToNextSibling("reliability");
            string reliability = reader.ReadElementContentAsString("reliability", "");

            reader.ReadToNextSibling("rnSt");
            string rnSt = reader.ReadElementContentAsString("rnSt", "");

            return new Data(mode, tmEf, wf, tmn, tmx, reliability, rnSt);
        }
    }

    class Location
    {
        public string Province { get; private set;  }
        public string City { get; private set; }

        public List<Data> Datas { get; private set; }

        public Location(string province, string city, List<Data> datas)
        {
            Province = province;
            City = city;
            Datas = datas;
        }

        public static Location MakeLocation(XmlReader reader)
        {  
            reader.ReadToDescendant("province");
            string province = reader.ReadElementContentAsString("province", "");

            reader.ReadToNextSibling("city");
            string city = reader.ReadElementContentAsString("city", "");

            List<Data> datas = new List<Data>();
            int count = 0;
            while (reader.Read())
            {
                if (count == 13)
                    break;
                if (reader.IsStartElement("data"))
                {       
                    Data data = Data.MakeData(reader);
                    if (data != null)
                    {
                        datas.Add(data);
                        count++;
                    }
                }
            }

            return new Location(province, city, datas);
        }

        public override string ToString()
        {
            return Province + ", " + City + ", " + Datas.Count;
        }
    }
}
