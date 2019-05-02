#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"

class Polyline : public Shape
{
public:
    Polyline(QPaintDevice* device = nullptr, int id = -1)
                :Shape(device, id, ShapeType::Polyline)
    {
    }

    virtual ~Polyline();

    void AddPoint(const QPoint& NEW_POINT);

    void Draw(QPaintDevice* device);

    void Move(const int& X, const int& Y);

    float Perimeter() const{return 0.0;}

    float Area() const{return 0.0;}

    Vector<QPoint> GetLinePoints() const{return linePoints;}

private:
    Vector<QPoint> linePoints;
};

#endif // POLYLINE_H
