#include "Polyline.h"

Polyline::~Polyline()
{
}

void Polyline::AddPoint(const QPoint& NEW_POINT)
{
    linePoints.push_back(NEW_POINT);
}

void Polyline::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);

    QPointF lineFloatPoints[linePoints.size()];

    for (int index = 0; index < linePoints.size(); index++)
        lineFloatPoints[index] = linePoints[index];

    painter.save();

    painter.drawPolyline(lineFloatPoints, linePoints.size());

    painter.restore();
}

void Polyline::Move(const int& X, const int& Y)
{
    static int index = 0;
    QPointF newPoint(X, Y);
    static bool full = false;

    if(index + 1 == linePoints.size())
    {
        full = true;
    }

    if(full == false)
    {
        linePoints[index].setX(X);
        linePoints[index].setY(Y);
        index++;
    }
    else
    {
        if(index + 1 == 6)
        {
            index = 0;
            full = false;
        }
        else {
            index++;
        }
    }
}
