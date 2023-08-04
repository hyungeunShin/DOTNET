//Shape.h

#pragma once

enum ShapeType  { NONE, SHAPE_RECT, SHAPE_ELLIPS, SHAPE_TRY};

typedef struct tagSHAPE
{
	POINT		pt;
	COLORREF	color;
	ShapeType	type;	//1:�簢��  2:Ÿ��  3:�ﰢ��
}SHAPE, *PSHAPE;

