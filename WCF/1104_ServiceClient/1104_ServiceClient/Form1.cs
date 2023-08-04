using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.ServiceModel;
using System.ServiceModel.Description;
using _1104_ServiceClient.ServiceReference1;

namespace _1104_ServiceClient
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Uri uri = new Uri("http://localhost/wcf/sample/helloworldserver");

            //ServiceEndpoint ep = new ServiceEndpoint(
            //    ContractDescription.GetContract(typeof(IHelloWorld)),
            //    new BasicHttpBinding(),
            //    new EndpointAddress(uri));

            //ChannelFactory<IHelloWorld> factory = new ChannelFactory<IHelloWorld>(ep);
            //IHelloWorld proxy = factory.CreateChannel();
            //string result = proxy.SayHello();
            //(proxy as IDisposable).Dispose();

            //textBox1.Text = result;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //Proxy객체
            HelloWorldClient client = new HelloWorldClient();
            textBox2.Text = client.SayHello();
        }
    }
}
