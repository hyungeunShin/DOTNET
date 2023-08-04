using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace _1103_PictureService
{
    /// <summary>
    /// WebService1의 요약 설명입니다.
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // ASP.NET AJAX를 사용하여 스크립트에서 이 웹 서비스를 호출하려면 다음 줄의 주석 처리를 제거합니다. 
    // [System.Web.Script.Services.ScriptService]
    public class PictureService : System.Web.Services.WebService
    {

        // 해당 이미지 파일을 바이트배열형태로 반환 메서드
        [WebMethod] 
        public byte[] GetPicture(string strFileName)
        {
            byte[] bytePic = { 0 }; // 바이트 배열을 하나 만든다.
            try
            {
                // 해당 이미지 파일을 스트림 형식으로 오픈한다.
                FileStream picFileStream = new FileStream(@"C:\AAA\Image\" + strFileName, 
                                FileMode.Open,FileAccess.Read, FileShare.Read);

                //BinaryReader : 보조객체
                BinaryReader picReader = new BinaryReader(picFileStream);

                // 이미지 파일을 바이트 배열에 넣는다.
                bytePic = picReader.ReadBytes(Convert.ToInt32(picFileStream.Length));
                
                // 파일스트림을 닫는다.
                picFileStream.Close();
                
                // 이미지 파일이 들어있는 바이트 배열을 리턴한다.
                return bytePic;
            }
            catch
            {
                // 초기값을 그냥 리턴한다.
                return bytePic;
            }
        }

        // 이미지 파일 목록을 리턴해주는 메서드
        [WebMethod]
        public string[] GetPictureList()
        {
            // 이미지 파일이 들어있는 디렉토리에서 파일 이름들을 문자열 배열에 넣는다.
            string[] strPicList = Directory.GetFiles(@"C:\AAA\Image\");

            // 파일 경로를 뺀 파일 이름만 다시 추출한다.
            for (int i = 0; i < strPicList.Length; i++)
            {
                FileInfo fi = new FileInfo(strPicList[i]);
                strPicList[i] = fi.Name;
            }
            // 이 이미지 파일 이름들을 리턴한다.
            return strPicList;
        }

        // 클라이언트들이 업로드하는 이미지 파일들을 저장하는 메서드
        [WebMethod]
        public bool UploadPicture(string strFileName, byte[] bytePic)
        {
            try
            {
                // 주어진 이미지 파일의 이름으로 파일을 하나 만든다.
                FileStream writeFileStream = new FileStream(@"C:\AAA\Image\" + strFileName, 
                        FileMode.Create, FileAccess.Write);

                // 이 파일에 바이너리를 넣기 위해 BinaryWriter 객체 생성
                BinaryWriter picWriter = new BinaryWriter(writeFileStream);

                // 바이트 배열로 받은 이미지를 파일에 쓴다.
                picWriter.Write(bytePic);

                // 파일스트림을 닫는다.
                writeFileStream.Close();

                // 업로드 성공
                return true;
            }
            catch (Exception )
            {
                // 업로드 실패
                return false;
            }
        }
    }
}
