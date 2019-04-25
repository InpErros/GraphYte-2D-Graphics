#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include "vector.h"

enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square,
                      Ellipse, Circle, Text};

class Shape
{
public:
    Shape(QPaintDevice* device, int shapeId, ShapeType shapeType)
        :qpainter(device), id(shapeId), shape(shapeType)
    {
    }

    //virtual Shape* clone() const = 0;   // The Virtual (Copy) Constructor

    virtual ~Shape();

    ShapeType GetShape() const{return shape;}

    QPen GetPen() const{return pen;}

    QBrush GetBrush() const{return brush;}

    void SetShape(const ShapeType& SHAPE){shape = SHAPE;}

    void SetPen(Qt::GlobalColor, int width, Qt::PenStyle, Qt::PenCapStyle,
                Qt::PenJoinStyle);

    void SetPen(Qt::GlobalColor);

    void SetBrush(Qt::GlobalColor, Qt::BrushStyle);

    virtual void Move(const int& X, const int& Y) = 0;

    virtual void Draw(const int& X, const int& Y) = 0;

    virtual float  Perimeter() const = 0;

    virtual float  Area() const = 0;

protected:
    QPainter& GetPainter(){return qpainter;}

private:
    QPainter  qpainter;
    int       id;
    ShapeType shape;
    QPen      pen;
    QBrush    brush;
};

#endif // SHAPE_H
