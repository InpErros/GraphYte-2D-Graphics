#include "Polyline.h"

/************************************************************************
* Method ~Polyline: Class Polyline
*----------------------------------------------------------------------
* 	 This method deletes the Polyline object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Polyline::~Polyline()
{
}

/************************************************************************
* Method Draw: Class Polyline
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
void Polyline::Draw(QPaintDevice* device)
{
    QPainter painter(device);   //Create a new painter to draw the shape to
    QPen     newPen;            //The pen for the new painter
    QBrush   newBrush;          //The brush for the new painter
    QPointF  lineFloatPoints[linePoints.size()]; //Create an array for
                                                 //the floating QPoints

    //PROCESSING - Get the values of the old painter
    newPen   = GetPen();
    newBrush = GetBrush();

    //PROCESSING = Set the values for the new painter
    painter.setPen  (newPen);
    painter.setBrush(newBrush);

    //Store all the linepoints into an array of floating point
    for (int index = 0; index < linePoints.size(); index++)
        lineFloatPoints[index] = linePoints[index];

    //PROCESSING - save current state of the painter
    painter.save();

    painter.drawPolyline(lineFloatPoints, linePoints.size());

    //PROCESSING - return the state of the current painter
    painter.restore();
}

/************************************************************************
* Method Move: Class Polyline
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
void Polyline::Move(const int& X, const int& Y)
{
    static int index = 0;    //PROC - the index in the array
    static bool full = false;//PROC - the condition if the array is full
    QPointF newPoint;        //PROC - the new points for

    //Set the new points
    newPoint.setX(X);
    newPoint.setY(Y);

    //If the has reached the max amount of stored points, then full = true;
    if(index + 1 == linePoints.size()){full = true;}

    //If the array is not full, set the new points
    if(full == false)
    {
        linePoints[index].setX(X);
        linePoints[index].setY(Y);
        index++;
    }
    else
    {
        //If the index is at the max amount of points, reset
        if(index + 1 == 6)
        {
            index = 0;
            full = false;
        }
        else {index++;}
    }
}

/************************************************************************
* Method Print: Class Polyline
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
void Polyline::Print(ostream& os) const
{

    os << "ShapeId: " << GetId() << endl;
    os << "ShapeType: Polyline" << endl;
    os << "ShapeDimensions: ";
    for(int i = 0; i < linePoints.size(); i++)
    {
        os << linePoints[i].x() << ", " << linePoints[i].y();
        if(i != linePoints.size() -1) {os << ", ";}

    }
    os << endl;
    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;

}
