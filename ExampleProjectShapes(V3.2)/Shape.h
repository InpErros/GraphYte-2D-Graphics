#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <fstream>
#include "vector.h"

using namespace MyVector;

struct newShapeInfo
{
    int           shapeId;
    QPen          shapePen;
    QBrush        brush;
    QFont         font;
    Vector<int>   dimensions;
    QString       text;
    QString       allignment;
    QPen          textPen;
    QString       name;
};

enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square,
                      Ellipse, Circle, Text};

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

    void SetPen(const Qt::GlobalColor& COLOR);

    void SetPen(const QPen& PEN);

    void SetBrush(const Qt::GlobalColor&, const Qt::BrushStyle&);

    void SetBrush(const QBrush& BRUSH);

    void SetName(const QString& NAME) {name = NAME;}

    virtual void Move(const int& X, const int& Y) = 0;

    virtual void Draw(QPaintDevice* device) = 0;

    virtual float  Perimeter() const = 0;

    virtual float  Area() const = 0;

    ShapeType GetShape() const{return shape;}

    QPen GetPen() const{return pen;}

    QBrush GetBrush() const{return brush;}

    QString GetName() const{return name;}


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
    QString   name;
};

#endif // SHAPE_H
