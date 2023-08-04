using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace _2021_11_01_XML_
{
    static class Test
    {
        #region URL 경로를 통해서 XMLReader객체 생성

        public static string ReadXml3_2(string url)
        {
            XmlUrlResolver resolver = new XmlUrlResolver();
            resolver.Credentials = System.Net.CredentialCache.DefaultCredentials;   // 자격 증명

            XmlReaderSettings settings = new XmlReaderSettings();
            settings.XmlResolver = resolver;
            XmlReader reader = XmlReader.Create(url, settings);

            string str = Read1(reader);
            reader.Close();
            return str;
        }

        public static string Read1(XmlReader reader)
        {
            string str = "";

            while (reader.Read())
            {
                //if (reader.NodeType == XmlNodeType.Element)
                //{
                str += reader.ReadInnerXml();//.ReadOuterXml();
                //}
            }
            return str;
        }

        #endregion 
    }
}
