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

/************************************************************************
* Method IdShapeListing: Class Shape
*----------------------------------------------------------------------
* 	 This method prints the id of every shape in list
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		shapes (Vector<Shape*>)  - the list of shapes
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Shape::IdShapeListing(const Vector<Shape*> shapes) const
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

/************************************************************************
* Method AreaShapeListing: Class Shape
*----------------------------------------------------------------------
* 	 This method prints area for every shape in the list
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		shapes (Vector<Shape*>)  - the list of shapes
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void AreaShapeListing();

/************************************************************************
* Method PerimeterShapeListing: Class Shape
*----------------------------------------------------------------------
* 	 This method prints perimeter for every shape in the list
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
* 		shapes (Vector<Shape*>)  - the list of shapes
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
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
