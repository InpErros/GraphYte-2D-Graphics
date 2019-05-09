#include "Line.h"

/************************************************************************
* Method ~Line: Class Line
*----------------------------------------------------------------------
* 	 This method deletes the Line object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Line::~Line()
{

}

/************************************************************************
* Method SetCordinates: Class Line
*----------------------------------------------------------------------
* 	 This method set the dimensions for the Line
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       START (QPoint) - the starting point of the Line
*       END   (QPoint) - the ending point of the Line
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Line::SetCordinates(const QPoint &START, const QPoint &END)
{
    startingPoint = START;
    endingPoint   = END;
}

/************************************************************************
* Method Draw: Class Line
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
void Line::Draw(QPaintDevice* device)
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

    painter.drawLine(startingPoint, endingPoint);

    //PROCESSING - return the state of the current painter
    painter.restore();
}

/************************************************************************
* Method Move: Class Line
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
void Line::Move(const int& X, const int& Y)
{
    static bool start = true;   //PROC - the condition if it is the first time
                                //       moving the shape

    //If it is the first time calling this function, set the new X and Y
    //cordinates to the starting point
    if(start == true)
    {
        startingPoint = QPoint(X, Y);
        start = false;
    }
    //Set the cordinates to the ending point
    else
    {
        endingPoint = QPoint(X, Y);
        start = true;
    }
}

/************************************************************************
* Method Print: Class Line
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
void Line::Print(ostream& os) const
{
    os << "ShapeId: " << GetId() << endl;
    os << "ShapeType: Line" << endl;
    os << "ShapeDimensions: " << startingPoint.x() << ", "
                              << startingPoint.y() << ", "
                              << endingPoint.x()   << ", "
                              << endingPoint.y()   << endl;
    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;

}
