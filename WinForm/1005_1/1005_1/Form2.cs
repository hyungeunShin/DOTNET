using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1005_1
{
    public class NewColorForm : Form
    {
        public string StrText { get; set; }
        public NewColorForm(string str)
        {
            this.Text = str;
            SetStyle(ControlStyles.SupportsTransparentBackColor, true);
        }

        //무효화 영역 처리.(이벤트 등록 or 재정의)
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics gh = e.Graphics; //Win32 BeginPaint로 획득한 DC

            gh.DrawString(StrText, this.Font, new SolidBrush(Color.Black), 10, 7);
        }
    }


    public partial class Form2 : Form
    {
        private Array arr;
        private NewColorForm[] childform;

        public Form2()
        {
            InitializeComponent();

            //여러개의 form을 답을 수 있도록 속성 변경 
            this.IsMdiContainer = true;

           // enum 타입이 갖고 있는 모든 정보를 획득!(KnownColor)
            arr = System.Enum.GetValues(typeof(KnownColor));
            childform = new NewColorForm[arr.Length];

            for(int i=0; i<arr.Length; i++)
            {
                childform[i] = new NewColorForm(arr.GetValue(i).ToString());
                childform[i].StrText = arr.GetValue(i).ToString();
                //색상의 문자열로 Color 정보 획득!
                childform[i].BackColor = Color.FromName(arr.GetValue(i).ToString());
                childform[i].SetBounds(0, 0, 200, 50);
                childform[i].MdiParent = this;  //부모 지정
                childform[i].Show();
            }
        }

        //Color
        //1) 141개의 색상이 미리 정의되어 있다.
        //   AliceBlue(0)~ Transparent(141) : 투명색
        //2) FromArgb 메서드 제공
        //   Color color = Color.FromArgb(255,0,0);     //알파:0(불투명), Red, 
        //   Color color = Color.FromArgb(255,255,0,0); //알파:255(완전투명), Red
        //   Color color = Color.FromArgb(0x7800FF00);  //투명도78을 갖는 green
        private void button1_Click(object sender, EventArgs e)
        {
            //자식들을 정렬.
            this.LayoutMdi(MdiLayout.TileVertical);
        }
    }
}
