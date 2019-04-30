#include "Ellipse.h"

Ellipse::~Ellipse()
{
}

void Ellipse::SetDimensions(const int &WIDTH, const int &LENGTH)
{
    majorAxis = WIDTH;
    minorAxis = LENGTH;
    circle    = false;
}

void Ellipse::SetDimensions(const int &RADIUS)
{
    majorAxis = RADIUS;
    minorAxis = 0;
    circle    = true;
    SetShape(ShapeType::Circle);
}

void Ellipse::Draw(const int &X, const int &Y)
{
    GetPainter().translate(X, Y);
    if(circle != true)
        GetPainter().drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, minorAxis);
    else
        GetPainter().drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, majorAxis);
}

void Ellipse::Move(const int &X, const int &Y)
{
    GetPainter().translate(X, Y);
    if(circle != true)
        GetPainter().drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, minorAxis);
    else
        GetPainter().drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, majorAxis);
}

float Ellipse::Area() const
{
    if(circle != true)
        return (majorAxis * minorAxis * M_PI);
    else
        return (majorAxis * majorAxis * M_PI);
}

float Ellipse::Perimeter() const
{
    if(circle != true)
        return (2 * M_PI * qSqrt((pow(majorAxis, 2) + pow(minorAxis, 2)) / 2));
    else
        return (2 * M_PI * majorAxis);
}
