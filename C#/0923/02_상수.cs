using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _0923_1
{
    class Product
    {
        //맴버 필드
        public const int ConstPrice = 1000;  //static이 암묵적으로 붙는다--> 클래스맴버
                                             //모든 인스턴스들이 공유하는 맴버
        public readonly int ReadPrice;       //인스턴스 맴버 

        //생성자
        public Product()
        {
            ReadPrice = 10;
        }

        public Product(int price)
        {
            ReadPrice = price;
        }

        //인스턴스 맴버 메서드(클래스 내의 모든 맴버에 접근 가능!)
        public void Print()
        {
            Console.WriteLine("ConstPrice = {0}, ReadPrice = {1}", ConstPrice, ReadPrice);
        }
    }

    class Class1
    {
        public static void Main(string[] args)
        {
            //static의 성질 , 클래스명으로 접근가능!
            Console.WriteLine("ConstPrice = {0}", Product.ConstPrice);  //1000

            //인스턴스 생성 == 객체 생성
            Product p1 = new Product();
            Product p2 = new Product(100);
            Console.WriteLine("ReadPrice = {0}, {1}", p1.ReadPrice, p2.ReadPrice);//10,100


            p1.Print();
            p2.Print();

            Console.ReadKey();
        }
    }
}
