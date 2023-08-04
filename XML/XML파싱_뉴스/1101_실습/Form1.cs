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
        private List<Item> items = new List<Item>();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string url = "https://www.korea.kr/rss/speech.xml";

            XmlUrlResolver resolver = new XmlUrlResolver();
            resolver.Credentials = System.Net.CredentialCache.DefaultCredentials;

            XmlReaderSettings settings = new XmlReaderSettings();
            settings.XmlResolver = resolver;

            XmlReader reader = XmlReader.Create(url, settings);

            items.Clear();

            while (reader.Read())
            {
                if (reader.IsStartElement("item"))
                {
                    Item item = Item.MakeItem(reader);
                    if (item != null)
                        items.Add(item);
                }
            }

            reader.Close();

            Print();
        }

        private void Print()
        {
            listBox1.Items.Clear();
            foreach (Item item in items)
            {
                listBox1.Items.Add(item);
            }
        }

        //제목 선택
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex < 0)
                return;

            Item item = items[listBox1.SelectedIndex];
            linkLabel1.Text = item.Link;

            textBox1.Text = item.Description;
            textBox2.Text = item.PubDate;
        }

        //링크 선택
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            webBrowser1.Navigate(linkLabel1.Text);
        }
    }
}
