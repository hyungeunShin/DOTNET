//Shape.h

#pragma once

enum ShapeType  { NONE, SHAPE_RECT, SHAPE_ELLIPS, SHAPE_TRY};

typedef struct tagSHAPE
{
	POINT		pt;
	COLORREF	color;
	ShapeType	type;	//1:사각형  2:타원  3:삼각형
}SHAPE, *PSHAPE;

