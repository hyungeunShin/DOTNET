using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1101_실습
{
    class ReadXML
    {

        public string Title { get; private set; }

        public string WF { get; private set; }

        ReadXML(string title, string wf)
        {
            Title = title;
            WF = wf;
        }

        public override string ToString()
        {
            return "지역: " + Title + ", 날씨: " + WF;
        }

        public static ReadXML MakeNews(XmlReader reader)
        {
            string title = string.Empty;
            string wf = string.Empty;

            reader.ReadToDescendant("city");
            title = reader.ReadElementContentAsString("city", "");

            reader.ReadToNextSibling("data");
            reader.ReadToDescendant("wf");
            wf = reader.ReadElementContentAsString("wf", "");

            return new ReadXML(title, wf);
        }
    }
}
