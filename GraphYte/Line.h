#ifndef LINE_H
#define LINE_H

#include "Shape.h"/** Shape **/

/************************************************************************
* Line Class
* 	This class represents a Line object. It manages 2 attributes:
* 		startingPoint and endingPoint
*************************************************************************/
class Line : public Shape //Child class
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Line(QPaintDevice* device = nullptr, int id = -1);
     *   Constructor; this method initializes the Line object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               id       (int)          - the id of the shape
     *   Return: none
     ***************************************************************/
    Line(QPaintDevice* device = nullptr, int id = -1)
            :Shape(device, id, ShapeType::Line)
    {
    }

    /****************************************************************
     * ~Line ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Line();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void SetCordiantes(const QPoint& START, const QPoint& END);
     *   Mutator; Initializes the cordinates for the Line
     *   Parameters: START (QPoint) - the cordinates for the starting cordinates
     *               END   (QPoint) - the cordinates for the ending cordinates
     *   Return: none
     ***************************************************************/
    void SetCordinates(const QPoint& START, const QPoint& END);

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
     *   Accessor; Calcualtes and returns the perimeter of the line
     *   Parameters:
     *   Return: perimeter
     ***************************************************************/
    float Perimeter() const{return 0.0;}

    /****************************************************************
     * float Area() const;
     *   Accessor; Calcualtes and returns the area of the shape
     *   Parameters:
     *   Return: area
     ***************************************************************/
    float Area() const{return 0.0;}

    /****************************************************************
     * QPoint GetStartPoint() const;
     *   Accessor; returns the cordinates of the starting point
     *   Parameters:
     *   Return: startingPoint
     ***************************************************************/
    QPoint GetStartPoint() const{return startingPoint;}

    /****************************************************************
     * QPoint GetEndPoint() const;
     *   Accessor; returns the cordinates of the ending point
     *   Parameters:
     *   Return: endingPoint
     ***************************************************************/
    QPoint GetEndPoint() const{return endingPoint;}

private:
    QPoint startingPoint; //The starting cordinates of the line
    QPoint endingPoint;   //The ending cordinates of the line
};

#endif // LINE_H
