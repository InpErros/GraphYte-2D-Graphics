#include "RenderArea.h"

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    currentShape = nullptr;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(1000, 500);
}

void RenderArea::setShape(Shape* shape)
{
    this->currentShape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    Line      line(this, 1);
    Polyline  polyline(this, 2);
    Polygon   polygon(this, 3);
    Rectangle rectangle(this, 4);
    Rectangle square(this, 5);
    Ellipse   ellipse(this, 6);
    Ellipse   circle(this, 7);

    //Line
    line.SetCordinates(QPoint(20, 90), QPoint(100, 20));

    line.SetPen(Qt::blue, 2, Qt::DashDotLine, Qt::FlatCap, Qt::MiterJoin);

    line.Draw(line.GetStartPoint().x(), line.GetStartPoint().y());

    //Polyline
    polyline.AddPoint(QPoint(460, 90));
    polyline.AddPoint(QPoint(470, 20));
    polyline.AddPoint(QPoint(530, 40));
    polyline.AddPoint(QPoint(540, 80));

    polyline.SetPen(Qt::green, 6, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

    polyline.Draw(polyline.GetLinePoints()[0].x(),
                  polyline.GetLinePoints()[0].y());

    //Polygon
    polygon.AddPoint(QPoint(900, 90));
    polygon.AddPoint(QPoint(910, 20));
    polygon.AddPoint(QPoint(970, 40));
    polygon.AddPoint(QPoint(980, 80));

    polygon.SetPen(Qt::cyan, 6, Qt::DashDotDotLine, Qt::FlatCap, Qt::MiterJoin);

    polygon.SetBrush(Qt::yellow, Qt::SolidPattern);

    polygon.Draw(polygon.GetLinePoints()[0].x(),polygon.GetLinePoints()[0].y());

    //Rectangle
    rectangle.SetCordiantes(QPoint(20, 200));

    rectangle.SetDimensions(170, 100);

    rectangle.SetPen(Qt::blue, 0, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);

    rectangle.SetBrush(Qt::red, Qt::VerPattern);

    rectangle.Draw(rectangle.GetCords().x(), rectangle.GetCords().y());

    //Square
    square.SetCordiantes(QPoint(250, 150));

    square.SetDimensions(200);

    square.SetPen(Qt::red, 0, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);

    square.SetBrush(Qt::blue, Qt::HorPattern);

    square.Draw(square.GetCords().x(), square.GetCords().y());

    //Ellipse
    ellipse.SetCordiantes(QPoint(520, 200));

    ellipse.SetDimensions(170, 100);

    ellipse.SetPen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

    ellipse.SetBrush(Qt::white, Qt::NoBrush);

    ellipse.Draw(ellipse.GetCords().x(), ellipse.GetCords().y());

    //Circle
    circle.SetCordiantes(QPoint(750, 150));

    circle.SetDimensions(200);

    circle.SetPen(Qt::black, 12, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);

    circle.SetBrush(Qt::magenta, Qt::SolidPattern);

    circle.Draw(circle.GetCords().x(), circle.GetCords().y());
}
