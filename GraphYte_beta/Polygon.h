#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.h"/** Shape **/

/************************************************************************
* Polygon Class
* 	This class represents a Polygon object. It manages 1 attributes:
* 		polygonPoints
*************************************************************************/
class Polygon : public Shape //Child class
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Polygon(QPaintDevice* device = nullptr, int id = -1);
     *   Constructor; this method initializes the Polygon object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               id       (int)          - the id of the shape
     *   Return: none
     ***************************************************************/
    Polygon(QPaintDevice* device = nullptr, int id = -1)
        :Shape(device, id, ShapeType::Polygon)
    {
    }

    /****************************************************************
     * ~Polygon ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Polygon();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void AddPoint(const QPoint& NEW_POINT);
     *   Mutator; Adds a cordinate to the vector
     *   Parameters: NEW_POINT (QPoint) - the cordinates of the new point
     *   Return: none
     ***************************************************************/
    void AddPoint(const QPoint& NEW_POINT){polygonPoints.push_back(NEW_POINT);}

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
     *   Accessor; Calcualtes and returns the perimeter of the polygon
     *   Parameters:
     *   Return: perimeter
     ***************************************************************/
    float Perimeter() const;

    /****************************************************************
     * float Area() const;
     *   Accessor; Calcualtes and returns the area of the polygon
     *   Parameters:
     *   Return: area
     ***************************************************************/
    float Area() const;

    /****************************************************************
     * Vector<QPoint> GetLinePoints() const;
     *   Accessor; returns the vector of points
     *   Parameters:
     *   Return: polygonPoints
     ***************************************************************/
    Vector<QPoint> GetLinePoints() const{return polygonPoints;}

private:
    Vector<QPoint> polygonPoints; //The list of all the points
};

#endif // POLYGON_H
