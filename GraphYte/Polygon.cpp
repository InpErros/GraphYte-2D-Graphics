#include "Polygon.h"

Polygon::~Polygon()
{
}

void Polygon::AddPoint(const QPoint &NEW_POINT)
{
    polygonPoints.push_back(NEW_POINT);
}

void Polygon::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);;

    QPointF polygonFloatPoints[polygonPoints.size()];

    for (int index = 0; index < polygonPoints.size(); index++)
        polygonFloatPoints[index] = polygonPoints[index];

    painter.save();

    painter.drawPolygon(polygonFloatPoints, polygonPoints.size());

    painter.restore();
}

void Polygon::Move(const int& X, const int& Y)
{
    QPointF polygonFloatPoints[polygonPoints.size()];

    for (int index = 0; index < polygonPoints.size(); index++)
        polygonFloatPoints[index] = polygonPoints[index];

    GetPainter().translate(X, Y);
    GetPainter().drawPolygon(polygonFloatPoints, polygonPoints.size());
}

float Polygon::Area() const
{
    float area = 0.0;

    for(int index = 0; index < polygonPoints.size(); index++)
    {
        if(index == polygonPoints.size()-1)
        {
            area += polygonPoints[index].x() * polygonPoints[0].y();

            area -= polygonPoints[index].y() * polygonPoints[0].x();

        }
        else
        {
            area += polygonPoints[index].x() * polygonPoints[index+1].y();

            area -= polygonPoints[index].y() * polygonPoints[index+1].x();

        }

    }

    return area / 2;
}

float Polygon::Perimeter() const
{
    float perimeter = 0.0;

    for(int index = 0; index < polygonPoints.size()-1; index++)
    {
        perimeter +=
        (qSqrt((polygonPoints[index+1].x() - polygonPoints[index].x()) *
               (polygonPoints[index+1].x() - polygonPoints[index].x()) +
               (polygonPoints[index+1].y() - polygonPoints[index].y()) *
               (polygonPoints[index+1].y() - polygonPoints[index].y()))
        );
    }

    return perimeter;
}
