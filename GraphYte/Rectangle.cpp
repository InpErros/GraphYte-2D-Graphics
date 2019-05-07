#include "Rectangle.h"

/************************************************************************
* Method Rectangle: Class Rectangle
*----------------------------------------------------------------------
* 	 This method creates the Rectangle object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       device    (QPaintDevice) - the canvas that the shape will be drawn to
*       id        (int)          - the id of the shape
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Rectangle::Rectangle(QPaintDevice* device, int id)
            :Shape(device, id, ShapeType::Rectangle)
{
    length = 0;
    width  = 0;
    square = false;
}

/************************************************************************
* Method ~Rectangle: Class Rectangle
*----------------------------------------------------------------------
* 	 This method deletes the Rectangle object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Rectangle::~Rectangle()
{
}

/************************************************************************
* Method SetDimensions: Class Rectangle
*----------------------------------------------------------------------
* 	 This method set the dimensions for the Rectangle
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       WIDTH   (int) - the width of the Rectangle
*       LENGTH  (int) - the length of the Rectangle
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Rectangle::SetDimensions(const int &LENGTH, const int &WIDTH)
{
    length = LENGTH;
    width  = WIDTH;
}

/************************************************************************
* Method SetDimensions: Class Rectangle
*----------------------------------------------------------------------
* 	 This method set the dimensions for the Square
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       LENGTH   (int) - the length of the square
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Rectangle::SetDimensions(const int &LENGTH)
{
    length = LENGTH;
    square = true;

    //Change the shape type to that of a Square
    SetShape(ShapeType::Square);
}

/************************************************************************
* Method Draw: Class Ellipse
*----------------------------------------------------------------------
* 	 This method draw the shape to the canvas
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       device   (QPaintDevice) - the canvas to be drawn to
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Rectangle::Draw(QPaintDevice* device)
{
    QPainter painter(device);   //Create a new painter to draw the shape to
    QPen     newPen;            //The pen for the new painter
    QBrush   newBrush;          //The brush for the new painter

    //PROCESSING - Get the values of the old painter
    newPen   = GetPen();
    newBrush = GetBrush();

    //PROCESSING = Set the values for the new painter
    painter.setPen  (newPen);
    painter.setBrush(newBrush);

    //PROCESSING - save current state of the painter
    painter.save();

    //Based on if the shape if a rectangle or square, draw it accordingly
    if(square != true)
        painter.drawRect(cordinates.x(), cordinates.y(), width, length);
    else
        painter.drawRect(cordinates.x(), cordinates.y(), length, length);

    //PROCESSING - return the state of the current painter
    painter.restore();
}

/************************************************************************
* Method Move: Class Rectangle
*----------------------------------------------------------------------
* 	 This method moves the shape
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       X (int) - the new x cordinate
*       Y (int) - the new y cordinate
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Rectangle::Move(const int &X, const int &Y)
{
    SetCordiantes(QPoint(X, Y));
}

/************************************************************************
* Method Area: Class Rectangle
*----------------------------------------------------------------------
* 	 This method calcualtes the area of the shape
* 	 ==> returns area
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns area
*************************************************************************/
float Rectangle::Area() const
{
    if(square != true) {return (length * width);}
    else               {return (length * length);}
}

/************************************************************************
* Method Perimeter: Class Rectangle
*----------------------------------------------------------------------
* 	 This method calcualtes the perimeter of the shape
* 	 ==> returns perimeter
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns perimeter
*************************************************************************/
float Rectangle::Perimeter() const
{
    if(square != true){return ((2 * length) + (2 * width));}
    else{return (4 * length);}
}

/************************************************************************
* Method Print: Class Rectangle
*----------------------------------------------------------------------
* 	 This outputs all of the shapes properties
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       os (ostream&) - the output stream
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Rectangle::Print(ostream& os) const
{

    os << "ShapeId: " << GetId() << endl;
    if(isSquare() == false) //check to see if the shape is a rectangle or square
    {
        os << "ShapeType: Rectangle" << endl;
        os << "ShapeDimensions: " << GetCords().x() << ", "
                                  << GetCords().y() << ", "
                                  << GetLength()    << ", "
                                  << GetWidth()     << endl;
    }
    else
    {
        os << "ShapeType: Square" << endl;
        os << "ShapeDimensions: " << GetCords().x() << ", "
                                  << GetCords().y() << ", "
                                  << GetLength()    << endl;
    }

    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;
    os << "BrushColor: " << BrushColorToStr(GetBrush()) << endl;
    os << "BrushStyle: " << BrushStyleToStr(GetBrush()) << endl;
}
