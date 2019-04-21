#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(QPaintDevice* device = nullptr, int id = -1)
        :Shape(device, id, ShapeType::Rectangle)
    {
    }

    ~Rectangle();

    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}
    void SetDimensions(const int &LENGTH, const int &WIDTH);
    void SetDimensions(const int &LENGTH);

    void Draw(const int& X, const int& Y);

    void Move(const int& X, const int& Y);

    float Perimeter() const;

    float Area() const;

    QPoint GetCords() const{return cordinates;}

    int GetWidth() const{return width;}

    int GetLength() const{return length;}

    bool isSquare() const{return square;}

private:
    QPoint cordinates;
    int    length;
    int    width;
    bool   square;
};

#endif // RECTANGLE_H
