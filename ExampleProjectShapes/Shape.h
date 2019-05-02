#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include "vector.h"

using namespace MyVector;

enum ShapeType {NoShape, LINE, POLYLINE, POLYGON, RECTANGLE, SQUARE,
                      ELLIPSE, CIRCLE, TEXT};

class Shape
{
public:
	friend ostream& operator<<(ostream& os, const Shape&);

    Shape(QPaintDevice* device, int shapeId, ShapeType shapeType)
        :qpainter(device), id(shapeId), shape(shapeType)
    {
        pen = Qt::SolidLine;
        brush = Qt::NoBrush;
    }

    Shape(const Shape& ) = delete;

    Shape& operator=(const Shape& ) = delete;

    virtual ~Shape();

    void SetShape(const ShapeType& SHAPE){shape = SHAPE;}

    void SetPen(const Qt::GlobalColor&, const int& WIDTH, const Qt::PenStyle&,
                const Qt::PenCapStyle&, const Qt::PenJoinStyle&);

    void SetPen(const Qt::GlobalColor& COLOR){qpainter.setPen(COLOR);}

    void SetPen(const QPen& PEN){qpainter.setPen(PEN);}

    void SetBrush(const Qt::GlobalColor&, const Qt::BrushStyle&);

    void SetBrush(const QBrush& BRUSH){qpainter.setBrush(BRUSH);}

    virtual void Move(const int& X, const int& Y) = 0;

    virtual void Draw() = 0;

    virtual float  Perimeter() const = 0;

    virtual float  Area() const = 0;

    ShapeType GetShape() const{return shape;}

    QPen GetPen() const{return pen;}

    QBrush GetBrush() const{return brush;}
	
	void IdShapeListing(Vector<Shape*> shapes);

    void AreaShapeListing();

    void PerimeterShapeListing();


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
