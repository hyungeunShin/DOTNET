using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1007_Sample
{
    public partial class Form4 : Form
    {
        DragDropHandler ddrop = null;
        public Form4()
        {
            InitializeComponent();

            ddrop = new DragDropHandler(this);
            ddrop.DragDrop_AddControl(this.button1);
            ddrop.DragDrop_AddControl(this.label1);
            ddrop.DragDrop_AddControl(this.checkBox1);
            ddrop.DragDrop_AddControl(this.radioButton1);
        }
    }
}
