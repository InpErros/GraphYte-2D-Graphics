#include "Ellipse.h"

Ellipse::Ellipse()
{
	a = 0.0;
	b = 0.0;
	circle = false;
}

Ellipse::Ellipse(const uint& X,  const uint& Y,
				 const uint& A, const uint& B)
	:Shape(X, Y)
{
	a = A;
	b = B;
	circle = false;
}

Ellipse::Ellipse(const uint& X,  const uint& Y,
				 const uint& A)
	:Shape(X, Y)
{
	a = A;
	b = 0.0;
	circle = true;
}

Ellipse::~Ellipse()
{

}

void Ellipse::SetValues(const uint& X,  const uint& Y,
				        const uint& A, const uint& B)
{
	Shape::SetValues(X, Y);
	a = A;
	b = B;
}

void Ellipse::SetValues(const uint& X,  const uint& Y,
				        const uint& A)
{
	Shape::SetValues(X, Y);
	a = A;
	b = 0.0;
	circle = true;
}

unsigned float Ellipse::Area() const
{
	unsigned float area = 0;

	if(circle == false)
		area = (PI * a * b);
	else
		area = (PI * a * a);

	return area;
}

unsigned float Ellipse::Perimeter() const
{
	unsigned float perimeter = 0;

	if(circle == false)
		perimeter = (2 * PI * sqrt((pow(a, 2) + pow(b, 2)) / 2));
	else
		perimeter = (2*PI*a);

	return perimeter;
}
