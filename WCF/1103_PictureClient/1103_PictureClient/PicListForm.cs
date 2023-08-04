using _1103_PictureClient.localhost;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1103_PictureClient
{
    public partial class PicListForm : Form
    {
        private PictureService pic = new PictureService();

        public string SelectedImage
        {
            get { return listBox1.SelectedItem.ToString(); }
        }

        public PicListForm()
        {
            InitializeComponent();

            string[] strPicList = pic.GetPictureList();

            listBox1.DataSource = strPicList;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
            Close();
        }
    }
}
