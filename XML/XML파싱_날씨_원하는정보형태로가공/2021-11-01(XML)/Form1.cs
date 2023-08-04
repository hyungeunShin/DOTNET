using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace _2021_11_01_XML_
{
    public partial class Form1 : Form
    {
        private List<City> cities = new List<City>();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string url = "https://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=133";
            textBox1.Text = Test.ReadXml3_2(url);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string url = "https://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=133";
            cities.Clear();           
            string cityname = string.Empty;
            XmlReader reader = XmlReader.Create(url);
            while (reader.Read())
            {  
                reader.MoveToContent();

                if (reader.IsStartElement("city"))
                {                                       
                    string name = reader.ReadElementContentAsString("city", "");
                    reader.MoveToContent();
                    City city = City.MakeCity2(name, reader);
                    if (city != null)
                        cities.Add(city);
                    cityname = city.Name;
                }
                else if (reader.IsStartElement("data"))
                {    
                    City city = City.MakeCity2(cityname, reader);
                    if (city != null)
                        cities.Add(city);                    
                }
            }
            reader.Close();
            PrintListBox();
            MessageBox.Show("3");
        }


        //ListBox에 출력
        private void PrintListBox()
        {
            listBox1.Items.Clear();
            foreach (City city in cities)
            {
                listBox1.Items.Add(city);  //book.ToString()
            }
        }
    }
}
