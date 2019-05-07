#include "Shape.h"

/************************************************************************
* Method Shape: Class Shape
*----------------------------------------------------------------------
* 	 This method creates the Shape object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       device    (QPaintDevice) - the canvas that the shape will be drawn to
*       shapeId   (int)          - the id of the shape
*       shapeType (ShapeType)    - the type of shape
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Shape::Shape(QPaintDevice* device, int shapeId, ShapeType shapeType)
        :qpainter(device), id(shapeId), shape(shapeType)
{
    pen   = Qt::SolidLine;
    brush = Qt::SolidPattern;
    name  .clear();
}

/************************************************************************
* Method ~Shape: Class Shape
*----------------------------------------------------------------------
* 	 This method deletes the Shape object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Shape::~Shape()
{

}

/************************************************************************
* Method SetPen: Class Shape
*----------------------------------------------------------------------
* 	 This method sets the values of the pen for the shape
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		COLOR     (Qt::GlobalColor)  - the color of the pen
*       WIDTH     (int)              - the width of the pen
*       STYLE     (Qt::PenStyle)     - the style of the pen
*       CAP_STYLE (Qt::PenCapStyle)  - the style of the pen cap
*       JOIN_STYLE(Qt::PenJoinStyle) - the style of the pen join
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Shape::SetPen(const Qt::GlobalColor& COLOR, const int& WIDTH,
                   const Qt::PenStyle& STYLE, const Qt::PenCapStyle& CAP_STYLE,
                   const Qt::PenJoinStyle& JOIN_STYLE)
{
    //PROCESSING - Set the values into the pen
    pen.setColor    (COLOR);
    pen.setWidth    (WIDTH);
    pen.setStyle    (STYLE);
    pen.setCapStyle (CAP_STYLE);
    pen.setJoinStyle(JOIN_STYLE);

    qpainter.setPen(pen);
}

/************************************************************************
* Method SetPen: Class Shape
*----------------------------------------------------------------------
* 	 This method sets the values of the pen for the shape
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		COLOR     (Qt::GlobalColor)  - the color of the pen
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Shape::SetPen(const Qt::GlobalColor &COLOR)
{
    //PROCESSING - Set the values into the pen
    pen.setColor(COLOR);

    qpainter.setPen(pen);
}

/************************************************************************
* Method SetPen: Class Shape
*----------------------------------------------------------------------
* 	 This method sets the values of the pen for the shape
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		PEN     (QPen)  - the pen
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Shape::SetPen(const QPen &PEN)
{
    //PROCESSING - Set the values into the pen
    pen = PEN;

    qpainter.setPen(pen);
}

/************************************************************************
* Method SetBrush: Class Shape
*----------------------------------------------------------------------
* 	 This method sets the values of the brush for the shape
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		COLOR     (Qt::GlobalColor)  - the color of the brush
*       STYLE     (Qt::BrushStyle)   - the style of the brush
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Shape::SetBrush(const Qt::GlobalColor& COLOR, const Qt::BrushStyle& STYLE)
{
    //PROCESSING - Set the values into the brush
    brush.setColor(COLOR);
    brush.setStyle(STYLE);

    qpainter.setBrush(brush);
}

/************************************************************************
* Method SetBrush: Class Shape
*----------------------------------------------------------------------
* 	 This method sets the values of the brush for the shape
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		BRUSH     (QBrush)  - the brush
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Shape::SetBrush(const QBrush &BRUSH)
{
    //PROCESSING - Set the values into the brush
    brush = BRUSH;

    qpainter.setBrush(brush);
}

// Helper functions
string ColortoStr(const QPen& PEN)
{
    string color;

    if(PEN.color()      == Qt::blue)    {color = "blue";}
    else if(PEN.color() == Qt::red)     {color = "red";}
    else if(PEN.color() == Qt::cyan)    {color = "cyan";}
    else if(PEN.color() == Qt::yellow)  {color = "yellow";}
    else if(PEN.color() == Qt::magenta) {color = "magenta";}
    else if(PEN.color() == Qt::black)   {color = "black";}
    else if(PEN.color() == Qt::green)   {color = "green";}
    else if(PEN.color() == Qt::gray)    {color = "gray";}
    else {color = "white";}

    return color;
}

string BrushColorToStr(const QBrush& BRUSH)
{
    string color;

    if(BRUSH.color()      == Qt::blue)    {color = "blue";}
    else if(BRUSH.color() == Qt::red)     {color = "red";}
    else if(BRUSH.color() == Qt::cyan)    {color = "cyan";}
    else if(BRUSH.color() == Qt::yellow)  {color = "yellow";}
    else if(BRUSH.color() == Qt::magenta) {color = "magenta";}
    else if(BRUSH.color() == Qt::black)   {color = "black";}
    else if(BRUSH.color() == Qt::green)   {color = "green";}
    else if(BRUSH.color() == Qt::gray)    {color = "gray";}
    else {color = "white";}

    return color;
}

string PenStyleToStr(const QPen& PEN)
{
    string penStyle;

    if(PEN.style()      == Qt::DashDotLine)    {penStyle = "DashDotLine";}
    else if(PEN.style() == Qt::SolidLine)      {penStyle = "SolidLine";}
    else if(PEN.style() == Qt::DashLine)       {penStyle = "DashLine";}
    else if(PEN.style() == Qt::DotLine)        {penStyle = "DotLine";}
    else if(PEN.style() == Qt::CustomDashLine) {penStyle = "CustomDashLine";}
    else if(PEN.style() == Qt::DashDotDotLine) {penStyle = "DashDotDotLine";}
    else {penStyle = "NoPen";}

    return penStyle;
}

string JoinStyleToStr(const QPen& PEN)
{
    string joinStyle;

    if(PEN.joinStyle()      == Qt::MiterJoin) {joinStyle = "MiterJoin";}
    else if(PEN.joinStyle() == Qt::RoundJoin) {joinStyle = "RoundJoin";}
    else if(PEN.joinStyle() == Qt::BevelJoin) {joinStyle = "BevelJoin";}

    return joinStyle;
}

string CapStyleToStr(const QPen& PEN)
{
    string capStyle;

    if(PEN.capStyle()      == Qt::SquareCap) {capStyle = "SquareCap";}
    else if(PEN.capStyle() == Qt::RoundCap)  {capStyle = "RoundCap";}
    else if(PEN.capStyle() == Qt::FlatCap)   {capStyle = "FlatCap";}

    return capStyle;
}

string BrushStyleToStr(const QBrush& BRUSH)
{
    string brushStyle;

    if(BRUSH.style()      == Qt::SolidPattern) {brushStyle = "SolidPattern";}
    else if(BRUSH.style() == Qt::VerPattern)   {brushStyle = "VerPattern";}
    else if(BRUSH.style() == Qt::HorPattern)   {brushStyle = "HorPattern";}
    else {brushStyle = "NoBrush";}

    return brushStyle;
}
