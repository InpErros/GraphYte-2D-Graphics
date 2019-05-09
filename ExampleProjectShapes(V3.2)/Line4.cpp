#include "Line.h"

Line::~Line()
{

}

void Line::SetCordinates(const QPoint &START, const QPoint &END)
{
    startingPoint = START;
    endingPoint   = END;
}

void Line::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);

    painter.save();

    painter.drawLine(startingPoint, endingPoint);

    painter.restore();
}

void Line::Move(const int& X, const int& Y)
{
    static bool start = true;

    if(start == true)
    {
        startingPoint = QPoint(X, Y);
        start = false;
    }
    else
    {
        endingPoint = QPoint(X, Y);
        start = true;
    }
}

void Line::Print(ostream& os)
{

    os << "ShapeId: " << GetId() << endl;
    os << "ShapeType: Line" << endl;
    os << "ShapeDimensions: " << startingPoint.x() << ", "
                              << startingPoint.y() << ", "
                              << endingPoint.x()   << ", "
                              << endingPoint.y()   << endl;
    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;

}
