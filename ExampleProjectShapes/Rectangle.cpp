#include "Rectangle.h"

Rectangle::~Rectangle()
{
}

void Rectangle::SetDimensions(const int &LENGTH, const int &WIDTH)
{
    length = LENGTH;
    width  = WIDTH;
    square = false;
}

void Rectangle::SetDimensions(const int &LENGTH)
{
    length = LENGTH;
    width  = 0;
    square = true;
    SetShape(ShapeType::SQUARE);
}

void Rectangle::Draw()
{
    GetPainter().save();

    if(square != true)
        GetPainter().drawRect(cordinates.x(), cordinates.y(), width, length);
    else
        GetPainter().drawRect(cordinates.x(), cordinates.y(), length, length);

    GetPainter().restore();

}

void Rectangle::Move(const int &X, const int &Y)
{
    GetPainter().translate(X, Y);
    if(square != true)
        GetPainter().drawRect(cordinates.x(), cordinates.y(), width, length);
    else
        GetPainter().drawRect(cordinates.x(), cordinates.y(), length, length);
}

float Rectangle::Area() const
{
    if(square != true)
        return (length * width);
    else
        return (length * length);
}

float Rectangle::Perimeter() const
{
    if(square != true)
        return ((2 * length) + (2 * width));
    else
        return (4 * length);
}
