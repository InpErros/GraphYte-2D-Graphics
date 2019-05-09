#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <QtMath>
#include <QDebug>

class Ellipse : public Shape
{
public:
    Ellipse(QPaintDevice* device = nullptr, int id = -1)
        :Shape(device, id, ShapeType::Ellipse)
    {
    }

    virtual ~Ellipse();

    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}
    void SetDimensions(const int &WIDTH, const int &LENGTH);
    void SetDimensions(const int &RADIUS);

    void Draw(QPaintDevice* device);

    void Move(const int& X, const int& Y);

    float Perimeter() const;

    float Area() const;

    QPoint GetCords() const{return cordinates;}

    int GetMajorAxis() const{return majorAxis;}

    int GetMinorAxis() const{return minorAxis;}

    bool isCircle() const{return circle;}

    void Print(ostream& os);


private:
    QPoint cordinates;
    int majorAxis;
    int minorAxis;
    bool circle;
};

#endif // ELLIPSE_H
