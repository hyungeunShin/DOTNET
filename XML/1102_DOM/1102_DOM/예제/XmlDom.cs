using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _1102_DOM
{
    static class XmlDom
    {
        public static void Exam_5_1(string filename)
        {
            XmlDocument doc = new XmlDocument();
            doc.LoadXml("<?xml version=\"1.0\" encoding=\"utf-8\"?>" +
            "<books>" +
            "<book>" +
            "<title> ADO.NET </title>" +
            "</book>" +
            "</books>");
            doc.Save(filename);
        }

        public static void Exam_5_2(string filename)
        {
            XmlDocument doc = new XmlDocument();

            XmlDeclaration xmldecl = doc.CreateXmlDeclaration("1.0", null, null);
            doc.InsertBefore(xmldecl, doc.DocumentElement);

            XmlComment comment = doc.CreateComment("XML 노드 삽입 ");
            doc.AppendChild(comment);

            //첫번째 요소 - 루트요소
            XmlElement root = doc.CreateElement("books");
            doc.AppendChild(root);

            XmlElement elem_book = doc.CreateElement("book");
            elem_book.InnerText = "XML.NET";
            doc.DocumentElement.AppendChild(elem_book);

            XmlElement elem_price = doc.CreateElement("price");
            elem_price.InnerText = 12000.ToString();
            doc.DocumentElement.AppendChild(elem_price);

            elem_book.SetAttribute("price", "12000");

            XmlAttribute attr = doc.CreateAttribute("count");
            attr.Value = "50";
            elem_price.Attributes.Append(attr);

            //-------------------요소의 내부에 ----
            XmlElement elem_sample = doc.CreateElement("sample");
            elem_sample.InnerText = 12000.ToString();
            elem_price.AppendChild(elem_sample);
            //--------------------------------------

            doc.Save(filename);
        }

        //기존 코드 
        public static string ReadXml2(string fileanme)
        {
            XmlReader xreader = XmlReader.Create(fileanme); //XmlReader 개체 생성

            XmlWriterSettings settings = new XmlWriterSettings();
            settings.Indent = true;

            StringBuilder sb = new StringBuilder();
            XmlWriter xwriter = XmlWriter.Create(sb, settings); //XmlWriter 개체 생성

            while (xreader.Read())
            {
                if (xreader.NodeType == XmlNodeType.Element)
                {
                    xwriter.WriteStartElement(xreader.Name);
                    xwriter.WriteAttributes(xreader, false); //xreader의 현재 특성을 쓰기
                    if (xreader.IsEmptyElement)
                    {
                        xwriter.WriteEndElement();
                    }
                }
                else if (xreader.NodeType == XmlNodeType.EndElement)
                {
                    xwriter.WriteEndElement();
                }
                else if (xreader.NodeType == XmlNodeType.Text)
                {
                    xwriter.WriteValue(xreader.Value);             //값 출력
                }
            }
            xwriter.Close();
            xreader.Close();

            return sb.ToString();
        }

    }
}
