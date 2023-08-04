using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace _1102_DOM
{
    /*
     {"message":
        {"@type":"response","@service":"naverservice.nmt.proxy","@version":"1.0.0",
       "result":
        {"srcLangType":"ko","tarLangType":"en","translatedText":"Hello!","engineType":"PRETRANS","pivot":null
        }
        }
    }
    */ 
    static class Papago
    {
        //한글 -> 영어
        public static string Trans(string sour, string targ, string str)
        {
            string url = "https://openapi.naver.com/v1/papago/n2mt";
            HttpWebRequest request = (HttpWebRequest)WebRequest.Create(url);
            request.Headers.Add("X-Naver-Client-Id", "T1HIuU9W5bVo7oPudUt2");
            request.Headers.Add("X-Naver-Client-Secret", "X4m90mPVDv");
            request.Method = "POST";
            string query = str;
            byte[] byteDataParams = Encoding.UTF8.GetBytes("source=" + sour+"&target="+targ+"&text=" + query);
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = byteDataParams.Length;
            Stream st = request.GetRequestStream();
            st.Write(byteDataParams, 0, byteDataParams.Length);
            st.Close();

            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            Stream stream = response.GetResponseStream();
            StreamReader reader = new StreamReader(stream, Encoding.UTF8);
            string text = reader.ReadToEnd();   //요청의 결과값.
            stream.Close();
            response.Close();
            reader.Close();

            return text;
        }

        public static string JsonParsing(string json)
        {
            JObject jsonData = JObject.Parse(json);

            string temp = jsonData["message"]["result"]["translatedText"].ToString();            

            return temp;
        }
    }
}
