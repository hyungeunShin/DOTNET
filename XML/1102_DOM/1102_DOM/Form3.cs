using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1102_DOM
{
    public partial class Form3 : Form
    {
        private BookSearch search = new BookSearch();

        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string msg = textBox1.Text;
            if (search.Search(msg) == false)
                return;

            listBox1.Items.Clear();
            foreach (Book book in search.Books)
                listBox1.Items.Add(book);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex < 0)
                return;

            Book book = search.Books[listBox1.SelectedIndex];
            pictureBox1.Image = GetUrlImage(book.Image);
        }

        private Image GetUrlImage(string url)
        {
            using (WebClient client = new WebClient())
            {
                byte[] imgArray;
                imgArray = client.DownloadData(url);

                using (MemoryStream memstr = new MemoryStream(imgArray))
                {
                    Image img = Image.FromStream(memstr);
                    return img;
                }
            }
        }
    }
}
