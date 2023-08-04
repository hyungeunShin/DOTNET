using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace _1108_ChatService
{
    //델리게이트 선언
    delegate void Chat(int idx, string msg, string type);

    class ChatService : IChat
    {        
        // 개인용 델리게이트
        private Chat MyChat;

        //개인에게 보낼 정보를 담고 있는 델리게이트
        private IChatCallback callback = null;

        #region IChat 구현 상속
        public bool Join(int idx)
        {
            MyChat = new Chat(UserHandler);            
            callback = OperationContext.Current.GetCallbackChannel<IChatCallback>();
                       
            BroadcastMessage(idx, "", "UserEnter");

            return true;
        }   

        public void Say(int idx, string msg)
        {
            BroadcastMessage(idx, msg, "Receive");
        }

        public void Leave(int idx)
        {
            Chat d = null;
            MyChat -= d;
        }
        #endregion

        #region ChatService 기능 메서드
        private void BroadcastMessage(int idx, string msg, string msgType)
        {
            MyChat.BeginInvoke(idx, msg, msgType, new AsyncCallback(EndAsync), null);
        }

        private void UserHandler(int idx, string msg, string msgType)
        {
            try
            {
                //클라이언트에게 보내기
                switch (msgType)
                {
                    case "Receive":
                        callback.Receive(idx, msg);
                        break;
                    case "UserEnter":
                        callback.UserEnter(idx);
                        break;
                }
            }
            catch//에러가 발생했을 경우
            {
                Console.WriteLine("{0} 에러", idx);
            }
        }

        private void EndAsync(IAsyncResult ar)
        {
            Chat d = null;
            try
            {
                System.Runtime.Remoting.Messaging.AsyncResult asres =
                    (System.Runtime.Remoting.Messaging.AsyncResult)ar;
                d = ((Chat)asres.AsyncDelegate);
                d.EndInvoke(ar);
            }
            catch
            {
            }
        }

        #endregion

        #region IChatCallback 메서드의 기능
        #endregion
    }
}
