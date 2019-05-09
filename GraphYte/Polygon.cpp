#include "Polygon.h"

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
Polygon::~Polygon()
{
}

/************************************************************************
* Method Draw: Class Polygon
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
void Polygon::Draw(QPaintDevice* device)
{
    QPainter painter(device);   //Create a new painter to draw the shape to
    QPen     newPen;            //The pen for the new painter
    QBrush   newBrush;          //The brush for the new painter
    QPointF  polygonFloatPoints[polygonPoints.size()]; //Create an array for
                                                       //the floating QPoints

    //PROCESSING - Get the values of the old painter
    newPen   = GetPen();
    newBrush = GetBrush();

    //PROCESSING = Set the values for the new painter
    painter.setPen  (newPen);
    painter.setBrush(newBrush);

    //Store all the polygonpoints into an array of floating point
    for (int index = 0; index < polygonPoints.size(); index++)
        polygonFloatPoints[index] = polygonPoints[index];

    //PROCESSING - save current state of the painter
    painter.save();

    painter.drawPolygon(polygonFloatPoints, polygonPoints.size());

    //PROCESSING - return the state of the current painter
    painter.restore();
}

/************************************************************************
* Method Move: Class Polygon
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
void Polygon::Move(const int& X, const int& Y)
{
    static int index = 0;    //PROC - the index in the array
    static bool full = false;//PROC - the condition if the array is full
    QPointF newPoint;        //PROC - the new points for

    //Set the new points
    newPoint.setX(X);
    newPoint.setY(Y);

    //If the has reached the max amount of stored points, then full = true;
    if(index + 1 == polygonPoints.size()) {full = true;}

    //If the array is not full, set the new points
    if(full == false)
    {
        polygonPoints[index].setX(X);
        polygonPoints[index].setY(Y);
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
        else { index++;}
    }
}

/************************************************************************
* Method Area: Class Polygon
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
float Polygon::Area() const
{
    float area = 0.0;   //PROC - the area of the shape

    for(int index = 0; index < polygonPoints.size(); index++)
    {
        //If the index is now at the end of the array
        if(index == polygonPoints.size()-1)
        {
            area += polygonPoints[index].x() * polygonPoints[0].y();

            area -= polygonPoints[index].y() * polygonPoints[0].x();

        }
        else
        {
            area += polygonPoints[index].x() * polygonPoints[index+1].y();

            area -= polygonPoints[index].y() * polygonPoints[index+1].x();

        }
    }

    return area / 2;
}

/************************************************************************
* Method Perimeter: Class Polygon
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
float Polygon::Perimeter() const
{
    float perimeter = 0.0; //PROC - the perimeter of the shape

    for(int index = 0; index < polygonPoints.size()-1; index++)
    {
        perimeter +=
        (qSqrt((polygonPoints[index+1].x() - polygonPoints[index].x()) *
               (polygonPoints[index+1].x() - polygonPoints[index].x()) +
               (polygonPoints[index+1].y() - polygonPoints[index].y()) *
               (polygonPoints[index+1].y() - polygonPoints[index].y()))
        );
    }

    return perimeter;
}

/************************************************************************
* Method Print: Class Polygon
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
void Polygon::Print(ostream& os) const
{

    os << "ShapeId: " << GetId() << endl;
    os << "ShapeType: Polygon" << endl;
    os << "ShapeDimensions: ";
    for(int i = 0; i < polygonPoints.size(); i++)
    {
        os << polygonPoints[i].x() << ", " << polygonPoints[i].y();
        if(i != polygonPoints.size() -1) {os << ", ";}
    }
    os << endl;
    os << "PenColor: " << ColortoStr(GetPen()) << endl;
    os << "PenWidth: " << GetPen().width() << endl;
    os << "PenStyle: " << PenStyleToStr(GetPen()) << endl;
    os << "PenCapStyle: " << CapStyleToStr(GetPen()) << endl;
    os << "PenJoinStyle: " << JoinStyleToStr(GetPen()) << endl;
    os << "BrushColor: " << BrushColorToStr(GetBrush()) << endl;
    os << "BrushStyle: " << BrushStyleToStr(GetBrush()) << endl;

}
