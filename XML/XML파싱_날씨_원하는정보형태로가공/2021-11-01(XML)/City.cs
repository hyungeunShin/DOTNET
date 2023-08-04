using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _2021_11_01_XML_
{
    public class City
    {
        internal string Name { get; private set; }
        internal string Mode { get; private set; }
        internal string Day { get; private set; }
        internal string Condition { get; private set; }
        internal int MinT { get; private set; }
        internal int MaxT { get; private set; }
        internal int Rain { get; private set; }

        public City(string name, string mode, string day, string condition, int minT, int maxT, int rain)
        {
            Name = name;
            Mode = mode;
            Day = day;
            Condition = condition;
            MinT = minT;
            MaxT = maxT;
            Rain = rain;
        }

        public override string ToString()
        {
            string msg = "[도시명]" + Name + "\t" + "[Day]" + Day + "\t" + "[Condition]" + Condition + "\t" + "[온도] (" + MinT + "," + MaxT + ")" +
                "\t" + "[강수확률]" + Rain+"\r\n";
            return msg;
        }

        internal static City MakeCity2(string city, XmlReader xr)
        {
            string name = city;
            string mode = string.Empty;
            string day = string.Empty;
            string condition = string.Empty;
            int minT = 0;
            int maxT = 0;
            int rain = 0;

            xr.ReadToDescendant("mode");
            mode = xr.ReadElementContentAsString("mode", "");

            xr.ReadToNextSibling("tmEf");
            day = xr.ReadElementContentAsString("tmEf", "");

            xr.ReadToNextSibling("wf");
            condition = xr.ReadElementContentAsString("wf", "");

            xr.ReadToNextSibling("tmn");
            string temp = xr.ReadElementContentAsString("tmn", "");
            minT = int.Parse(temp);

            xr.ReadToNextSibling("tmx");
            temp = xr.ReadElementContentAsString("tmx", "");
            maxT = int.Parse(temp);

            xr.ReadToNextSibling("rnSt");
            temp = xr.ReadElementContentAsString("rnSt", "");
            rain = int.Parse(temp);

            return new City(name, mode, day, condition, minT, maxT, rain);
        }

    }
}
