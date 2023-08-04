using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using _1108_ChatClient.ServiceReference1;

namespace _1108_ChatClient
{
    public partial class Form1 : Form, IChatCallback
    {
        public int Number
        {
            get { return int.Parse(textBox1.Text);  }
            set { textBox1.Text = value.ToString(); }
        }

        private IChat chat;

        public Form1()
        {
            InitializeComponent();

            //기존 Load 코드
            InstanceContext site = new InstanceContext(this);
            chat = new ChatClient(site);

        }
       
        #region Form 이벤트 핸들러
        //연결
        private void button1_Click(object sender, EventArgs e)
        {            
            Connect(Number);
        }

        //해제
        private void button2_Click(object sender, EventArgs e)
        {
            DisConnect(Number);
        }
        //전송
        private void button3_Click(object sender, EventArgs e)
        {
            string msg = textBox2.Text;
            SendData(Number, msg);
            textBox2.Text = "";
        }
        #endregion

        #region 사용자 정의 함수
        private void Connect(int number)
        {
            try
            {
                //서버 접속
                if (chat.Join(number) == false)
                    MessageBox.Show("접속 실패");                
            }
            catch (Exception ex)
            {
                MessageBox.Show("접속 오류 :{0}", ex.Message);
            }
        }

        private void DisConnect(int number)
        {
            try
            {
                chat.Leave(number);
                listBox1.Items.Add("로그아웃되었습니다.");
            }
            catch (Exception ex)
            {
                MessageBox.Show("나가기 오류 :{0}", ex.Message);
            }
        }

        private void SendData(int number, string msg)
        {
            chat.Say(number, msg);
        }
        #endregion

        #region IChatCallback 구현 상속
        public void Receive(int idx, string message)
        {
            string msg = string.Format("[{0}] {1}", idx, message);
            listBox1.Items.Add(msg);
        }

        public void UserEnter(int idx)
        {
            string msg = string.Format("{0}님이 로그인하셨습니다.", idx);
            listBox1.Items.Add(msg);
        }
        #endregion
    }
}
