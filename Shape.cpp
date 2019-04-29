#include "Shape.h"

Shape::~Shape()
{

}

void Shape::SetPen(const Qt::GlobalColor& COLOR, const int& WIDTH,
                   const Qt::PenStyle& STYLE, const Qt::PenCapStyle& CAP_STYLE,
                   const Qt::PenJoinStyle& JOIN_STYLE)
{
    pen.setColor(COLOR);
    pen.setWidth(WIDTH);
    pen.setStyle(STYLE);
    pen.setCapStyle(CAP_STYLE);
    pen.setJoinStyle(JOIN_STYLE);

    qpainter.setPen(pen);
}

void Shape::SetBrush(const Qt::GlobalColor& COLOR, const Qt::BrushStyle& STYLE)
{
    brush.setColor(COLOR);
    brush.setStyle(STYLE);

    qpainter.setBrush(brush);
}


