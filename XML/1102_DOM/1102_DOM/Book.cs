using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1102_DOM
{
    class Book
    {
        internal string Title           { get; private set; }
        internal string Link            { get; private set; }
        internal string Image           { get; private set; }
        internal string Author          { get; private set; }
        internal int Price              { get; private set; }
        internal int Discount           { get; private set; }
        internal string Publisher       { get; private set; }
        internal string PubDate         { get; private set; }
        internal string Description     { get; private set; }

        internal Book(string title, string link, string image, string author, int price,
            int discount, string publisher, string pubdate, string description)
        {
            Title = title;
            Link = link;
            Image = image;
            Author = author;
            Price = price;
            Discount = discount;
            Publisher = publisher;
            PubDate = pubdate;
            Description = description;
        }

        static internal Book MakeBook(XmlNode xn)
        {
            XmlNode title_node = xn.SelectSingleNode("title");
            string title = ConvertString(title_node.InnerText);

            XmlNode link_node = xn.SelectSingleNode("link");
            string link = ConvertString(link_node.InnerText);

            XmlNode image_node = xn.SelectSingleNode("image");
            string image = ConvertString(image_node.InnerText);

            XmlNode author_node = xn.SelectSingleNode("author");
            string author = ConvertString(author_node.InnerText);

            XmlNode price_node = xn.SelectSingleNode("price");
            int price = int.Parse(price_node.InnerText);

            XmlNode discount_node = xn.SelectSingleNode("discount");
            int discount = int.Parse(discount_node.InnerText);

            XmlNode publisher_node = xn.SelectSingleNode("publisher");
            string publisher = ConvertString(publisher_node.InnerText);

            XmlNode pubdate_node = xn.SelectSingleNode("pubdate");
            string pubdate = ConvertString(pubdate_node.InnerText);

            XmlNode description_node = xn.SelectSingleNode("description");
            string description = ConvertString(description_node.InnerText);

            return new Book(title, link, image, author, price, discount, publisher, pubdate,description);
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

        public override string ToString()
        {
            return Title;
        }
    }
}
