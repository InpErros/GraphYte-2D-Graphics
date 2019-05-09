#include "Ellipse.h"

Ellipse::~Ellipse()
{
}

void Ellipse::SetDimensions(const int &WIDTH, const int &LENGTH)
{
    majorAxis = WIDTH;
    minorAxis = LENGTH;
    circle    = false;
}

void Ellipse::SetDimensions(const int &RADIUS)
{
    majorAxis = RADIUS;
    minorAxis = 0;
    circle    = true;
    SetShape(ShapeType::Circle);
}

void Ellipse::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);

    painter.save();

    if(circle != true)
        painter.drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, minorAxis);
    else
        painter.drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, majorAxis);
    painter.restore();
}

void Ellipse::Move(const int &X, const int &Y)
{
    SetCordiantes(QPoint(X, Y));
}

float Ellipse::Area() const
{
    if(circle != true)
        return (majorAxis * minorAxis * M_PI);
    else
        return (majorAxis * majorAxis * M_PI);
}

float Ellipse::Perimeter() const
{
    if(circle != true)
        return (2 * M_PI * qSqrt((pow(majorAxis, 2) + pow(minorAxis, 2)) / 2));
    else
        return (2 * M_PI * majorAxis);
}

void Ellipse::Print(ostream& os)
{
    os << "ShapeId: " << GetId() << endl;
//    if()
//    {
//        os << "ShapeId: " << ellipse.GetId() << endl;
//        os << "ShapeType: Ellipse";
//        os << "ShapeDimensions: ";
//    }
//    else
//    {
//        os << "ShapeId: " << ellipse.GetId() << endl;
//        os << "ShapeType: Circle";
//    os << "ShapeDimensions: ";
//    }

    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;
    os << "BrushColor: " << BrushColorToStr(GetBrush()) << endl;
    os << "BrushStyle: " << BrushStyleToStr(GetBrush()) << endl;

}
