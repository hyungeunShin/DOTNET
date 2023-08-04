using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
/*
 [WinForm, GUI]
 
 1) Form 클래스(Win32API Window)
 2) GDI+(Graphics Device Interface Plus)
    - Graphics 클래스,표면 ( Win32API DC)
  
 Windows 프로그래밍을 하기 위한 내용
 1) WinForm : System.Windows.Forms 
              => System.Windows.Forms.dll 를 참조 추가!
 2) GDI+    : System.Drawing -> 이미지, 색, 브러쉬, 펜, 글꼴 등 기본 그래픽 처리
              System.Drawing.Drawing2D -> 고급 레스터 및 백터 그래픽 
              System.Drawing.Imaging   -> 이미지 처리의 고급 기능
              System.Drawing.Printing  -> 인쇄 및 미리보기 기능
              System.Drawing.Text      -> 고급 글꼴 제어 기능
              System.Drawing.Desing    -> 사용자 지정 컨트롤의 디자인 지원
              => System.Drawing.dll 를 참조 추가!
 */ 


namespace _1005
{
    class Program
    {
        //첫 번째 프로그램
        /*
         * 1) dll을 참조 추가
         * 2) using 
         * 3) 코딩
         *    - Application 클래스(프로그램 흐름)
         *      Run() static 메서드 : 메시지루프 실행
         *    - Form 클래스(Window)
         */
        static void Exam1()
        {
            //Run에 메인Form 추가
            Application.Run(new Form());
        }

        //두 번째 프로그램 : Form객체의 정보(데이터, 속성-property)를 수정
        static void Exam2()
        {
            Form obj = new Form();
            obj.Text = "Form 클래스를 이용한 윈폼";  //제목표시줄에 출력
            obj.SetBounds(10, 10, 300, 150);        //출력좌표 및 크기
            obj.MaximizeBox = false;
            obj.MinimizeBox = false;
            obj.StartPosition = FormStartPosition.CenterScreen;

            Application.Run(obj);
        }

        static void Main(string[] args)
        {
            Exam2();
        }
    }
}
