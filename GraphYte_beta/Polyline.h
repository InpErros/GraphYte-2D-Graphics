#ifndef POLYLINE_H
#define POLYLINE_H

#include "Shape.h"/** Shape **/

/************************************************************************
* Polyline Class
* 	This class represents a Polyline object. It manages 1 attributes:
* 		linePoints
*************************************************************************/
class Polyline : public Shape //Child Class
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Polyline(QPaintDevice* device = nullptr, int id = -1);
     *   Constructor; this method initializes the Line object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               id       (int)          - the id of the shape
     *   Return: none
     ***************************************************************/
    Polyline(QPaintDevice* device = nullptr, int id = -1)
                :Shape(device, id, ShapeType::Polyline)
    {
    }

    /****************************************************************
     * ~Polyline ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Polyline();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void AddPoint(const QPoint& NEW_POINT);
     *   Mutator; Adds a cordinate to the vector
     *   Parameters: NEW_POINT (QPoint) - the cordinates of the new point
     *   Return: none
     ***************************************************************/
    void AddPoint(const QPoint& NEW_POINT){linePoints.push_back(NEW_POINT);}

    /****************************************************************
     * void Draw(QPaintDevice* device);
     *   Mutator; Draws the shape to the canvas
     *   Parameters: device (QPaintDevice) - the canvas that the shape will
     *                                       be drawn to
     *   Return: none
     ***************************************************************/
    void Draw(QPaintDevice* device);

    /****************************************************************
     * void Move(const int& X, const int& Y);
     *   Mutator; Move the shape accoring to the X and Y cordinates
     *   Parameters: X (int) - the new X cordinate
     *               Y (int) - the new Y cordinate
     *   Return: none
     ***************************************************************/
    void Move(const int& X, const int& Y);

    /****************************************************************
     * float Perimeter() const;
     *   Accessor; Calcualtes and returns the perimeter of the polyline
     *   Parameters:
     *   Return: perimeter
     ***************************************************************/
    float Perimeter() const{return 0.0;}

    /****************************************************************
     * float Area() const;
     *   Accessor; Calcualtes and returns the area of the polyline
     *   Parameters:
     *   Return: area
     ***************************************************************/
    float Area() const{return 0.0;}

    /****************************************************************
     * Vector<QPoint> GetLinePoints() const;
     *   Accessor; returns the vector of points
     *   Parameters:
     *   Return: linePoints
     ***************************************************************/
    Vector<QPoint> GetLinePoints() const{return linePoints;}

private:
    Vector<QPoint> linePoints; //The list of all the points
};

#endif // POLYLINE_H
