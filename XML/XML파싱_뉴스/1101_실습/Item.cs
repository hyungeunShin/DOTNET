using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;

namespace _1101_실습
{
    class Item
    {
        public string Title { get; private set; }
        public string Link { get; private set;  }
        public string Description { get; private set;  }
        public string PubDate { get; private set;  }
        public string Guid { get; private set; }
        public string Creator { get; private set; }
        public string Date { get; private set; }

        public Item(string title, string link, string description, string pubDate, string guid, string creator, string date)
        {
            Title = title;
            Link = link;
            Description = description;
            PubDate = pubDate;
            Guid = guid;
            Creator = creator;
            Date = date;
        }

        private static int idx = 0;
        //<요소>값</요소>
        public static Item MakeItem(XmlReader reader) //item
        {
            reader.ReadToDescendant("title");
            string title = reader.ReadElementContentAsString("title", "");

            reader.ReadToNextSibling("link");
            string link = reader.ReadElementContentAsString("link", "");

            reader.ReadToNextSibling("description");
            string description = reader.ReadElementContentAsString("description", "");
            description = ConvertString(description);

            reader.ReadToNextSibling("pubDate");
            string pubDate = reader.ReadElementContentAsString("pubDate", "");

            reader.ReadToNextSibling("guid");
            string guid = reader.ReadElementContentAsString("guid", "");

            //------------
            XNamespace dc = "http://purl.org/dc/elements/1.1/";
            XDocument doc = XDocument.Load("https://www.korea.kr/rss/speech.xml");
            var creators = doc.Descendants(dc + "creator");
            string creator = creators.ElementAt(idx).Value;

            var dates = doc.Descendants(dc + "date");
            string date = dates.ElementAt(idx).Value; 

            return new Item(title, link, description, pubDate, guid, creator, date);
        }

        public override string ToString()
        {
            return Title;
        }

        private static string ConvertString(string str)
        {
            int sindex = 0;
            int eindex = 0;
            while (true)
            {
                sindex = str.IndexOf('<');
                if (sindex == -1)
                {
                    break;
                }
                eindex = str.IndexOf('>');
                str = str.Remove(sindex, eindex - sindex + 1);        
            }
            return str;
        }
    }
}
