#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"/** Shape **/

/************************************************************************
* Ellipse Class
* 	This class represents a Ellipse object. It manages 4 attributes:
* 		cordinates, majorAxis, minorAxis, and circle
*************************************************************************/
class Ellipse : public Shape //Child Class
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Ellipse(QPaintDevice* device = nullptr, int id = -1);
     *   Constructor; this method initializes the Ellipse object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               id       (int)          - the id of the shape
     *   Return: none
     ***************************************************************/
    Ellipse(QPaintDevice* device = nullptr, int id = -1);

    /****************************************************************
     * ~Ellipse ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Ellipse();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void SetCordiantes(const QPoint& CORDINATES);
     *   Mutator; Initializes the cordinates for the Ellipse
     *   Parameters: CORDINATES (QPoint) - the cordinates for the shape
     *   Return: none
     ***************************************************************/
    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}

    /****************************************************************
     * void SetDimensions(const int &WIDTH, const int &LENGTH);
     *   Mutator; Initializes the dimensions for the Ellipse
     *   Parameters: WIDTH  (int) - the width of the Ellipse
     *               LENGTH (int) - the length of the Ellipse
     *   Return: none
     ***************************************************************/
    void SetDimensions(const int &WIDTH, const int &LENGTH);

    /****************************************************************
     * void SetDimensions(const int &RADIUS);
     *   Mutator; Initializes the dimensions for the Circle
     *   Parameters: RADIUS  (int) - the radius of the Circle
     *   Return: none
     ***************************************************************/
    void SetDimensions(const int &RADIUS);

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

    /*******************
     **** ACCESSORS ****
     *******************/

    /****************************************************************
     * float Perimeter() const;
     *   Accessor; Calcualtes and returns the perimeter of the shape
     *   Parameters:
     *   Return: perimeter
     ***************************************************************/
    float Perimeter() const;

    /****************************************************************
     * float Area() const;
     *   Accessor; Calcualtes and returns the area of the shape
     *   Parameters:
     *   Return: area
     ***************************************************************/
    float Area() const;

    /****************************************************************
     * QPoint GetCords() const;
     *   Accessor; returns the cordinates of the shape
     *   Parameters:
     *   Return: cordinates
     ***************************************************************/
    QPoint GetCords() const{return cordinates;}

    /****************************************************************
     * int GetMajorAxis() const;
     *   Accessor; returns the majorAxis of the shape
     *   Parameters:
     *   Return: majorAxis
     ***************************************************************/
    int GetMajorAxis() const{return majorAxis;}

    /****************************************************************
     * int GetMinorAxis() const;
     *   Accessor; returns the minorAxis of the shape
     *   Parameters:
     *   Return: minorAxis
     ***************************************************************/
    int GetMinorAxis() const{return minorAxis;}

    /****************************************************************
     * int GetRadius() const;
     *   Accessor; returns the radius of the shape
     *   Parameters:
     *   Return: majorAxis
     ***************************************************************/
    int GetRadius() const{return majorAxis;}

    /****************************************************************
     * bool isCircle() const;
     *   Accessor; returns the if the shape is a circle
     *   Parameters:
     *   Return: circle
     ***************************************************************/
    bool isCircle() const{return circle;}

    /***************************************************************
     * void Print(ostream& os) const;
     *   Accessor; outputs all of the shape properties
     *   Parameters: os (ostream&) - the output stream
     *   Return: nothing
     ***************************************************************/
    void Print(ostream& os) const;

private:
    QPoint cordinates; //The cordinates of the shape
    int    majorAxis;  //The major axis of radius of the shape
    int    minorAxis;  //The minor axis of the shape
    bool   circle;     //The condition if the shape is a circle
};

#endif // ELLIPSE_H
