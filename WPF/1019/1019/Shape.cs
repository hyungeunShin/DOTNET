using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;

namespace _1019
{
    public class Shape
    {
        public Point ShapePoint { get; set; }
        public int ShapeSize { get; set; }
        public Color ShapeColor { get; set; }

        public Shape() { }
        public Shape(Point pt, int size, Color color)
        {
            ShapePoint = pt;
            ShapeSize = size;
            ShapeColor = color;
        }
    }
}
