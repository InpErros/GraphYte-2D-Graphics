#ifndef LINE_H
#define LINE_H

#include "Shape.h"

class Line : public Shape
{
public:
    Line(QPaintDevice* device = nullptr, int id = -1)
            :Shape(device, id, ShapeType::LINE)
    {
    }

    virtual ~Line();

    void SetCordinates(const QPoint& START, const QPoint& END);

    void Draw();

    void Move(const int& X, const int& Y);

    float Perimeter() const{return 0.0;}

    float Area() const{return 0.0;}

    QPoint GetStartPoint() const{return startingPoint;}
    QPoint GetEndPoint() const{return endingPoint;}


private:
    QPoint startingPoint;
    QPoint endingPoint;
};

#endif // LINE_H
