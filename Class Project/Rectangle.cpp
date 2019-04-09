#include "Rectangle.h"

Rectangle::Rectangle()
{
	length = 0;
	width  = 0;
	square = false;
}

Rectangle::Rectangle(const uint& X, const uint& Y,
				     const uint& L, const uint& W)
	:Shape(X, Y)
{
	length = L;
	width  = W;
	square = false;
}

Rectangle::Rectangle(const uint& X, const uint& Y,
				  	 const uint& L)
	:Shape(X, Y)
{
	length = L;
	width  = 0;
	square = true;
}

Rectangle::~Rectangle()
{
}

void Rectangle::SetInitialValues(const uint& X, const uint& Y,
				     	 	 	 const uint& L, const uint& W)
{
	Shape::SetValues(X, Y);

	length = L;
	width  = W;
}

void Rectangle::SetInitialValues(const uint& X, const uint& Y,
				  	 	 	 	 const uint& L)
{
	Shape::SetValues(X, Y);

	length = L;
	width  = 0;
	square = true;
}

uint Rectangle::Area() const
{
	uint area = 0;

	if(square == false)
		area = (length * width);
	else
		area = (length * length);

	return area;
}

uint Rectangle::Perimeter() const
{
	uint perimeter = 0;

	if(square == false)
		perimeter = ((2*length) + (2*width));
	else
		perimeter = (length*4);

	return perimeter;
}
