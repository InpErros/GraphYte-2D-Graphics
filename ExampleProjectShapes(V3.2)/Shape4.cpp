#include "Shape.h"
#include "Textbox.h"

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

string ColortoStr(QPen pen)
{
    string color;

    if(pen.color()      == Qt::blue)    {color = "blue";}
    else if(pen.color() == Qt::red)     {color = "red";}
    else if(pen.color() == Qt::cyan)    {color = "cyan";}
    else if(pen.color() == Qt::yellow)  {color = "yellow";}
    else if(pen.color() == Qt::magenta) {color = "magenta";}
    else if(pen.color() == Qt::black)   {color = "black";}
    else if(pen.color() == Qt::green)   {color = "green";}
    else if(pen.color() == Qt::gray)    {color = "gray";}
    else {color = "white";}

    return color;
}

string BrushColorToStr(QBrush brush)
{
    string color;

    if(brush.color()      == Qt::blue)    {color = "blue";}
    else if(brush.color() == Qt::red)     {color = "red";}
    else if(brush.color() == Qt::cyan)    {color = "cyan";}
    else if(brush.color() == Qt::yellow)  {color = "yellow";}
    else if(brush.color() == Qt::magenta) {color = "magenta";}
    else if(brush.color() == Qt::black)   {color = "black";}
    else if(brush.color() == Qt::green)   {color = "green";}
    else if(brush.color() == Qt::gray)    {color = "gray";}
    else {color = "white";}

    return color;
}

string PenStyleToStr(QPen pen)
{
    string penStyle;

    if(pen.style()      == Qt::DashDotLine)    {penStyle = "DashDotLine";}
    else if(pen.style() == Qt::SolidLine)      {penStyle = "SolidLine";}
    else if(pen.style() == Qt::DashLine)       {penStyle = "DashLine";}
    else if(pen.style() == Qt::DotLine)        {penStyle = "DotLine";}
    else if(pen.style() == Qt::CustomDashLine) {penStyle = "CustomDashLine";}
    else if(pen.style() == Qt::DashDotDotLine) {penStyle = "DashDotDotLine";}
    else {penStyle = "NoPen";}

    return penStyle;
}

string JoinStyleToStr(QPen pen)
{
    string joinStyle;

    if(pen.joinStyle()      == Qt::MiterJoin) {joinStyle = "MiterJoin";}
    else if(pen.joinStyle() == Qt::RoundJoin) {joinStyle = "RoundJoin";}
    else if(pen.joinStyle() == Qt::BevelJoin) {joinStyle = "BevelJoin";}

    return joinStyle;
}

string CapStyleToStr(QPen pen)
{
    string capStyle;

    if(pen.capStyle()      == Qt::SquareCap) {capStyle = "SquareCap";}
    else if(pen.capStyle() == Qt::RoundCap)  {capStyle = "RoundCap";}
    else if(pen.capStyle() == Qt::FlatCap)   {capStyle = "FlatCap";}

    return capStyle;
}

string BrushStyleToStr(QBrush brush)
{
    string brushStyle;

    if(brush.style()      == Qt::SolidPattern) {brushStyle = "SolidPattern";}
    else if(brush.style() == Qt::VerPattern)   {brushStyle = "VerPattern";}
    else if(brush.style() == Qt::HorPattern)   {brushStyle = "HorPattern";}
    else {brushStyle = "NoBrush";}

    return brushStyle;
}


