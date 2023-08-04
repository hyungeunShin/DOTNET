using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace _1102_DOM
{
    class BookSearch
    {
        private List<Book> books = new List<Book>();
        public List<Book> Books {  get { return books; } }

        //OPEN API를 이용해서 XML 문서를 획득!
        public bool Search(string msg)
        {
            string query = msg; // 검색할 문자열
            //string url = "https://openapi.naver.com/v1/search/book?query=" + query; // 결과가 JSON 포맷
            string url = "https://openapi.naver.com/v1/search/book.xml?display=20&query=" + query;  // 결과가 XML 포맷
    
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "c4SHrwgqacCk8In_S6LJ"); // 클라이언트 아이디
            request.Headers.Add("X-Naver-Client-Secret", "BmRv9H5xXw");       // 클라이언트 시크릿           
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            string status = response.StatusCode.ToString();
            if (status == "OK")
            {
                Stream stream = response.GetResponseStream();
                StreamReader reader = new StreamReader(stream, Encoding.UTF8);
                string text = reader.ReadToEnd();
                Parsing(text);      //<------------------------
                return true;
            }
            else
            {
                MessageBox.Show("Error 발생 = " + status);
                return false;
            }
        }
    
        //XML문서를 파싱해서 List에 저장!
        private void Parsing(string xmlstring)
        {
            books.Clear();

            XmlDocument doc = new XmlDocument();
            doc.LoadXml(xmlstring);

            XmlNode node = doc.SelectSingleNode("rss");
            XmlNode n = node.SelectSingleNode("channel");

            Book book = null;
            foreach (XmlNode el in n.SelectNodes("item"))
            {
                book = Book.MakeBook(el);
                books.Add(book);
            }
        }
    }
}
