using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _1006_실습
{
    static class Form1UI
    {
        //사용자로부터 저장 정보를 입력
        public static bool InputShape(Shape CurShape)
        {
            //부모->자식
            //방법1) 생성자 전달 , 메서드를 이용해서 반환 처리
            //AddForm form = new AddForm(CurShape);  

            //if( form.ShowDialog() == DialogResult.OK)
            //{
            //    CurShape = form.GetShape();
            //}

            //방법2) 프로퍼티를 활용하는 방법
            AddForm form = new AddForm();
            form.ShapeName = CurShape.Name;
            form.ShapeType = CurShape.ShapeType;
            form.ShapeColor = CurShape.BackColor;
            form.ShapePoint = CurShape.ShapePoint;

            if (form.ShowDialog() == DialogResult.OK)
            {
                CurShape.Name = form.ShapeName;
                CurShape.ShapeType = form.ShapeType;
                CurShape.BackColor = form.ShapeColor;
                CurShape.ShapePoint = form.ShapePoint;
                return true;
            }
            return false;
        }

        //콤보박스를 초기화 
        public static void ComboBoxInit(ComboBox combobox, List<Shape> shapes)
        {
            combobox.Items.Clear();

            foreach (Shape s in shapes)
            {
                combobox.Items.Add(s.Name);
            }
        }
    }
}
