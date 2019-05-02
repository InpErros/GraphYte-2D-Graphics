#include "Line.h"

Line::~Line()
{

}

void Line::SetCordinates(const QPoint &START, const QPoint &END)
{
    startingPoint = START;
    endingPoint   = END;
}

void Line::Draw()
{
    GetPainter().save();

    GetPainter().drawLine(startingPoint, endingPoint);

    GetPainter().restore();
}

void Line::Move(const int& X, const int& Y)
{
    GetPainter().translate(X, Y);
    GetPainter().drawLine(startingPoint, endingPoint);
}
