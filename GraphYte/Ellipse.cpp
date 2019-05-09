#include "Ellipse.h"

/************************************************************************
* Method Ellipse: Class Ellipse
*----------------------------------------------------------------------
* 	 This method creates the Ellipse object
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
Ellipse::Ellipse(QPaintDevice* device, int id)
            :Shape(device, id, ShapeType::Ellipse)
{
    majorAxis = 0;
    minorAxis = 0;
    circle    = false;
}

/************************************************************************
* Method ~Ellipse: Class Ellipse
*----------------------------------------------------------------------
* 	 This method deletes the Ellipse object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Ellipse::~Ellipse()
{
}

/************************************************************************
* Method SetDimensions: Class Ellipse
*----------------------------------------------------------------------
* 	 This method set the dimensions for the Ellipse
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       WIDTH   (int) - the width of the Ellipse
*       LENGTH  (int) - the length of the Ellipse
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Ellipse::SetDimensions(const int &WIDTH, const int &LENGTH)
{
    majorAxis = WIDTH;
    minorAxis = LENGTH;
}

/************************************************************************
* Method SetDimensions: Class Ellipse
*----------------------------------------------------------------------
* 	 This method set the dimensions for the Circle
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       RADIUS   (int) - the width of the circle
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Ellipse::SetDimensions(const int &RADIUS)
{
    majorAxis = RADIUS;
    circle    = true;

    //Change the shape type to that of a Circle
    SetShape(ShapeType::Circle);
}

/************************************************************************
* Method SetDimensions: Class Ellipse
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
void Ellipse::Draw(QPaintDevice* device)
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

    //Based on if the shape if a circle or ellipse, draw it accordingly
    if(circle != true)
        painter.drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, minorAxis);
    else
        painter.drawEllipse(cordinates.x(), cordinates.y(),
                                 majorAxis, majorAxis);

    //PROCESSING - return the state of the current painter
    painter.restore();
}

/************************************************************************
* Method Move: Class Ellipse
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
void Ellipse::Move(const int &X, const int &Y)
{
    SetCordiantes(QPoint(X, Y));
}

/************************************************************************
* Method Area: Class Ellipse
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
float Ellipse::Area() const
{
    if(circle != true) {return (majorAxis * minorAxis * M_PI);}
    else               {return (majorAxis * majorAxis * M_PI);}
}

/************************************************************************
* Method Perimeter: Class Ellipse
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
float Ellipse::Perimeter() const
{
    if(circle != true)
        return (2 * M_PI * qSqrt((pow(majorAxis, 2) + pow(minorAxis, 2)) / 2));
    else {return (2 * M_PI * majorAxis);}
}

/************************************************************************
* Method Print: Class Ellipse
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
void Ellipse::Print(ostream& os) const
{
    os << "ShapeId: " << GetId() << endl;
    if(isCircle() == false)
    {
        os << "ShapeType: Ellipse" << endl;;
        os << "ShapeDimensions: " << GetCords().x() << ", "
                                  << GetCords().y() << ", "
                                  << GetMajorAxis() << ", "
                                  << GetMinorAxis() << endl;
    }
    else
    {
        os << "ShapeType: Circle" << endl;
        os << "ShapeDimensions: " << GetCords().x() << ", "
                                  << GetCords().y() << ", "
                                  << GetRadius()    << endl;
    }

    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;
    os << "BrushColor: " << BrushColorToStr(GetBrush()) << endl;
    os << "BrushStyle: " << BrushStyleToStr(GetBrush()) << endl;

}
