﻿//------------------------------------------------------------------------------
// <auto-generated>
//     이 코드는 도구를 사용하여 생성되었습니다.
//     런타임 버전:4.0.30319.42000
//
//     파일 내용을 변경하면 잘못된 동작이 발생할 수 있으며, 코드를 다시 생성하면
//     이러한 변경 내용이 손실됩니다.
// </auto-generated>
//------------------------------------------------------------------------------

namespace _1108_ChatClient.ServiceReference1 {
    
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    [System.ServiceModel.ServiceContractAttribute(ConfigurationName="ServiceReference1.IChat", CallbackContract=typeof(_1108_ChatClient.ServiceReference1.IChatCallback), SessionMode=System.ServiceModel.SessionMode.Required)]
    public interface IChat {
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IChat/Join", ReplyAction="http://tempuri.org/IChat/JoinResponse")]
        bool Join(int idx);
        
        [System.ServiceModel.OperationContractAttribute(Action="http://tempuri.org/IChat/Join", ReplyAction="http://tempuri.org/IChat/JoinResponse")]
        System.Threading.Tasks.Task<bool> JoinAsync(int idx);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, IsInitiating=false, Action="http://tempuri.org/IChat/Say")]
        void Say(int idx, string msg);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, IsInitiating=false, Action="http://tempuri.org/IChat/Say")]
        System.Threading.Tasks.Task SayAsync(int idx, string msg);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, IsTerminating=true, IsInitiating=false, Action="http://tempuri.org/IChat/Leave")]
        void Leave(int idx);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, IsTerminating=true, IsInitiating=false, Action="http://tempuri.org/IChat/Leave")]
        System.Threading.Tasks.Task LeaveAsync(int idx);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IChatCallback {
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/IChat/Receive")]
        void Receive(int idx, string message);
        
        [System.ServiceModel.OperationContractAttribute(IsOneWay=true, Action="http://tempuri.org/IChat/UserEnter")]
        void UserEnter(int idx);
    }
    
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public interface IChatChannel : _1108_ChatClient.ServiceReference1.IChat, System.ServiceModel.IClientChannel {
    }
    
    [System.Diagnostics.DebuggerStepThroughAttribute()]
    [System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")]
    public partial class ChatClient : System.ServiceModel.DuplexClientBase<_1108_ChatClient.ServiceReference1.IChat>, _1108_ChatClient.ServiceReference1.IChat {
        
        public ChatClient(System.ServiceModel.InstanceContext callbackInstance) : 
                base(callbackInstance) {
        }
        
        public ChatClient(System.ServiceModel.InstanceContext callbackInstance, string endpointConfigurationName) : 
                base(callbackInstance, endpointConfigurationName) {
        }
        
        public ChatClient(System.ServiceModel.InstanceContext callbackInstance, string endpointConfigurationName, string remoteAddress) : 
                base(callbackInstance, endpointConfigurationName, remoteAddress) {
        }
        
        public ChatClient(System.ServiceModel.InstanceContext callbackInstance, string endpointConfigurationName, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(callbackInstance, endpointConfigurationName, remoteAddress) {
        }
        
        public ChatClient(System.ServiceModel.InstanceContext callbackInstance, System.ServiceModel.Channels.Binding binding, System.ServiceModel.EndpointAddress remoteAddress) : 
                base(callbackInstance, binding, remoteAddress) {
        }
        
        public bool Join(int idx) {
            return base.Channel.Join(idx);
        }
        
        public System.Threading.Tasks.Task<bool> JoinAsync(int idx) {
            return base.Channel.JoinAsync(idx);
        }
        
        public void Say(int idx, string msg) {
            base.Channel.Say(idx, msg);
        }
        
        public System.Threading.Tasks.Task SayAsync(int idx, string msg) {
            return base.Channel.SayAsync(idx, msg);
        }
        
        public void Leave(int idx) {
            base.Channel.Leave(idx);
        }
        
        public System.Threading.Tasks.Task LeaveAsync(int idx) {
            return base.Channel.LeaveAsync(idx);
        }
    }
}
