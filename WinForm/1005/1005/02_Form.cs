using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 * [Form]
 * 
 * Object <- MarshalByRefObject <- Component <- Control <- ScrollableControl <- ContainerControl <- Form
 * 
 *  Component : 윈폼 객체의 부모(출발점)
 *  Control   : 버튼, 텍스트, 라벨 등의 기반 클래스로 [키보드/마우스, 화면 출력 등] 기능 제공 받는다.
 *  ScrollableControl : 자동 스크롤 기능
 *  ContainerControl  : 폼에 다른 컨트롤들을 자식으로 담을 수 있는 속성 제공.
 * 
 *  : 컨트롤의 일종이다.
 *    표시할 영역이 화면에서 벗어나더라도 스크롤을 이용한 표시가 가능하다.
 *    다른 컨트롤들을 담을 수 있는 부모 컨트롤 기능이 가능하다.
 *    
 * [Form의 기본 이벤트]
 * Load        : 폼 초기화
 * FormClosed  : 폼 종료시
 * FormClosing : 펌 종료시작점(폼의 종료를 막을 수 있다.)
 * 
 * *이벤트*
 * 1, 2단계) 이벤트전달인자, 이벤트전달인자를 2번째 인자로 갖는 delegate
 * 3단계 ) delegate를 활용한 이벤트 생성(게시자)
 * ------------------------------------------------------------- 여기까지 제공됨.
 * 4단계 ) 이벤트 등록(구독자)
 * 
 * 예)
 * 1,2) EventArgs 클래스  EventHandler 델리게이트 ( void EventHandler(object sender, EventArgs e); )
 * 3)   event EventHandler Load;
 * 4)   Load += new System.EventHandler(메서드);
 * 
 * [클래스 분할 처리] MyForm2
 * 하나의 클래스를 여러개의 파일로 분할해서 정의할 수 있다. 
 * partial 키워드를 클래스 앞에 추가, 반드시 동일 namespace를 갖고 있어야 한다. 
 * --> 컴파일러가 하나로 합쳐준다. 
 * 분리기준
 * 1) 디자이너에 의해 자동으로 추가되는 부분들
 *    보통 생성자 영역(속성, 이벤트 등록, show)...
 *    
 * 2) 이벤트 처리 부분
 *    이벤트 핸들러 -> 개발자가 직접 코딩하는 부분!
 */

using System.Windows.Forms;
using System.Drawing;

namespace _1005
{
    //일반적으로 Form은 파생 클래스를 사용한다.
    class MyForm : Form
    {
        //[생성자] 속성 처리, 이벤트 등록 처리, Show()
        public MyForm(string text)
        {
            this.Text = text;
            //this.SetBounds(10,10, 300,100);
            this.Top = 10;
            this.Left = 10;
            this.Width = 300;
            this.Height = 100;
            this.MaximizeBox = false;
            this.BackColor = Color.Khaki;

            this.Load += MyForm_Load;  //new System.EventHandler(MyForm_Load);
            this.FormClosed += MyForm_FormClosed;

            this.Show();
        }

        #region 이벤트 핸들러(2번째 인자.. EventArgs : 기본 인자)
        private void MyForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            Console.WriteLine("윈도우가 Closed됩니다.");
        }

        private void MyForm_Load(object sender, EventArgs e)
        {            
            Console.WriteLine("윈도우가 Load됩니다.");
        }
        #endregion 
    }

    //마우스 이벤트, FormClosing 처리
    class MyForm1 : Form
    {
        public MyForm1()
        {
            this.Text = "두번째 Form";

            //마우스 메시지
            this.MouseEnter += MyForm1_MouseEnter;
            this.MouseMove += MyForm1_MouseMove;
            this.MouseLeave += MyForm1_MouseLeave;

            this.FormClosing += MyForm1_FormClosing;

            this.Show();
        }

        private void MyForm1_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult r= MessageBox.Show("프로그램을 종료?", "알림", MessageBoxButtons.YesNo);
            if( r == DialogResult.No)
                e.Cancel = true; 
        }

        private void MyForm1_MouseLeave(object sender, EventArgs e)
        {
            Console.WriteLine("마우스가 윈도우 밖에");
        }

        private void MyForm1_MouseMove(object sender, MouseEventArgs e)
        {
            Console.WriteLine("마우스 이동 : {0}, {1}", e.X, e.Y);
            this.Text = string.Format("{0},{1}", e.X, e.Y);
        }

        private void MyForm1_MouseEnter(object sender, EventArgs e)
        {
            Console.WriteLine("마우스가 윈도우 안으로");
        }
    }

    class Class1
    {
        //여러개의 폼을 생성, 그중 하나가 MainForm
        static string[] srtText = { "빨", "주", "노", "초", "파", "남", "보" };
        static void Exam1()
        {
            Form[] forms = new Form[7];
            for(int i=0; i< forms.Length; i++)
            {
                forms[i] = new Form();
                forms[i].Text = srtText[i];
                forms[i].SetBounds((i + 1) * 10, (i + 1) * 10, 300, 100);
                forms[i].Show(); //ShowWindow
                Console.WriteLine("{0} 번째 윈도우 생성!", i);
            }
            Application.Run( forms[0]); //MainForm 등록!
            
        }
       
        public static void Main(string[] args)
        {
            //Exam1();
            //Application.Run(new MyForm("내가 만든폼"));
            //Application.Run(new MyForm1());
            Application.Run(new MyForm2());
        }
    }
}
