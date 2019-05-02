#ifndef POLYGON_H
#define POLYGON_H

#include <QtMath>
#include "Shape.h"

class Polygon : public Shape
{
public:
    Polygon(QPaintDevice* device = nullptr, int id = -1)
        :Shape(device, id, ShapeType::POLYGON)
    {
    }

    virtual ~Polygon();

    void AddPoint(const QPoint& NEW_POINT);

    void Draw();

    void Move(const int& X, const int& Y);

    float Perimeter() const;

    float Area() const;

    Vector<QPoint> GetLinePoints() const{return polygonPoints;}

private:
    Vector<QPoint> polygonPoints;
};

#endif // POLYGON_H
