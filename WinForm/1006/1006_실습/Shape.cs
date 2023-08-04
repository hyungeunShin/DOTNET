using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace _1006_실습
{
    public enum ShapeType { NONE, RECT, ELLIPSE, TRAIANGLE}
    /// <summary>
    /// 데이터 클래스
    /// </summary>
    public class Shape
    {
        public string Name              { get; set; }
        public ShapeType ShapeType      { get; set; }
        public Color     BackColor      { get; set; }
        public Point     ShapePoint     { get; set; }
        public string   Message         { get; set; }

        public Shape() { }
        public Shape(string name, ShapeType s, Color c, Point  p)
        {
            Name = name;
            ShapeType = s;
            BackColor = c;
            ShapePoint = p;
            Message = "";
        }

        //자신의 정보를 문자열로 반환
        public override string ToString()
        {
            return string.Format("[이름] {0}, [타입] {1}, [색상] {2}, [좌표] {3}",
                Name, ShapeType, BackColor, ShapePoint);
        }
    }
}
