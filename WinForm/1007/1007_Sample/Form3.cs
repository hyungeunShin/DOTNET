using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
//파일 드래그앤 드랍
namespace _1007_Sample
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void listBox1_DragEnter(object sender, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                e.Effect = DragDropEffects.None;
            }
        }

        private void listBox1_DragDrop(object sender, DragEventArgs e)
        {
            string[] files = (string[])e.Data.GetData(DataFormats.FileDrop);

            foreach (string str in files)
            {
                listBox1.Items.Add(str);
            }
        }

        //리스트박스를 선택했을 때 호출되는 메서드
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                string path = (string)listBox1.SelectedItem;
                //파일Read -> textBox1에 출력
                char[] buf = new char[1024];
                int ret;
                StreamReader sr = new StreamReader(path);

                textBox1.Text = "";
                while (true)
                {
                    ret = sr.Read(buf, 0, 1024);
                    textBox1.Text += new string(buf, 0, ret);
                    if (ret < 1024)
                        break;
                }
                sr.Close();
            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
