#include "Shape.h"

Shape::~Shape()
{

}

void Shape::SetPen(Qt::GlobalColor shapeColor)
{
    qpainter.setPen(shapeColor);
}

void Shape::SetPen(Qt::GlobalColor shapeColor, int width, Qt::PenStyle penStyle,
                   Qt::PenCapStyle penCapStyle, Qt::PenJoinStyle penJointStyle)
{
    pen.setColor(shapeColor);
    pen.setWidth(width);
    pen.setStyle(penStyle);
    pen.setCapStyle(penCapStyle);
    pen.setJoinStyle(penJointStyle);

    qpainter.setPen(pen);
}

void Shape::SetBrush(Qt::GlobalColor shapeColor, Qt::BrushStyle shapeBrushStyle)
{
    brush.setColor(shapeColor);
    brush.setStyle(shapeBrushStyle);

    qpainter.setBrush(brush);
}


