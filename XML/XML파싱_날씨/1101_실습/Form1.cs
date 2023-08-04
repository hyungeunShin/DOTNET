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

namespace _1101_실습
{
    public partial class Form1 : Form
    {
        private List<Location> locations = new List<Location>();        

        public Form1()
        {
            InitializeComponent();
        }

        //전국(108)        서울경기(109)        강원도(105)
        private void button1_Click(object sender, EventArgs e)
        {
            int idx = -1;
            if (comboBox1.SelectedIndex == 0)                idx = 108;
            else if (comboBox1.SelectedIndex == 1)           idx = 109;
            else if (comboBox1.SelectedIndex == 2)          idx = 105;
            string url = "http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=" + idx;

            XmlUrlResolver resolver = new XmlUrlResolver();
            resolver.Credentials = System.Net.CredentialCache.DefaultCredentials;

            XmlReaderSettings settings = new XmlReaderSettings();
            settings.XmlResolver = resolver;

            XmlReader reader = XmlReader.Create(url, settings);

            locations.Clear();

            while (reader.Read())
            {
                if (reader.IsStartElement("location"))
                {
                    _1101_실습.Location location = _1101_실습.Location.MakeLocation(reader);
                    if (location != null)
                        locations.Add(location);
                }
            }

            reader.Close();

            PrintListBox();
        }

        private void PrintListBox()
        {
            listBox1.Items.Clear();
            foreach (Location location in locations)
            {
                listBox1.Items.Add(location);
            }
        }
    }
}
