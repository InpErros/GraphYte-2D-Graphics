#include "Line.h"

Line::Line()
{
	x2 = 0.0;
	y2 = 0.0;
}

Line::Line(const uint& X, const uint& Y, const uint& X2, const uint& Y2)
	:Shape(X, Y)
{
	x2 = X2;
	y2 = Y2;
}

Line::~Line()
{

}

