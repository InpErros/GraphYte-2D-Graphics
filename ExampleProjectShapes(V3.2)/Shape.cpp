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

void Shape::SetPen(const Qt::GlobalColor &COLOR)
{
    pen.setColor(COLOR);
    qpainter.setPen(pen);
}

void Shape::SetPen(const QPen &PEN)
{
    pen = PEN;
    qpainter.setPen(pen);
}

void Shape::SetBrush(const Qt::GlobalColor& COLOR, const Qt::BrushStyle& STYLE)
{
    brush.setColor(COLOR);
    brush.setStyle(STYLE);

    qpainter.setBrush(brush);
}

void Shape::SetBrush(const QBrush &BRUSH)
{
    brush = BRUSH;
    qpainter.setBrush(brush);
}

void Shape::IdShapeListing(const Vector<Shape*> shapes)
{
    Vector<Shape*> temp = shapes;
    Shape* tempSpot;
    int j;
    ofstream fout;

    for(int i = 1; i < temp.size(); i++)
    {
        tempSpot = temp[i];
        j = i -1;
        while(j >= 0 && temp[i] > tempSpot)
        {
            temp[j + 1] = temp[j];
            j = j -1;
        }
        temp[j + 1] = tempSpot;
    }

    //fout.open("IdShapeListing.txt");
//    fout << temp;

      //fout.close();
}

void AreaShapeListing();

void PerimeterShapeListing();

ostream& operator<<(ostream& os, const Shape& shape)
{
    ShapeType type = shape.GetShape();
    QPen color = shape.GetPen();

    os << "ShapeId: " << shape.id << endl;
    os << "ShapeType: ";

    switch(type)
    {
    case ShapeType::NoShape: break;
    case ShapeType::Line: os << "Line";
        break;
    case ShapeType::Polyline: os << "Polyline";
        break;
    case ShapeType::Polygon: os << "Polygon";
        break;
    case ShapeType::Rectangle: os << "Rectangle";
        break;
    case ShapeType::Square: os << "Square";
        break;
    case ShapeType::Ellipse: os << "Ellipse";
        break;
    case ShapeType::Circle: os << "Circle";
        break;
    case ShapeType::Text: os << "Text";
        break;
    }
    os << endl;
    //os << "ShapeDimensions: ";
    //os << "PenColor: " << shape.GetPen() << endl;
    //os << "PenWidth: " << shape.GetPen().width() << endl;
    //os << "PenCapStyle: " << shape.GetPen().capStyle() << endl;
    //os << "PenJoinStyle: " << shape.GetPen().joinStyle() << endl;
    os << endl << endl;

    return os;
}
