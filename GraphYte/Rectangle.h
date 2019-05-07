#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"/** Shape **/

/************************************************************************
* Rectangle Class
* 	This class represents a Rectangle object. It manages 4 attributes:
* 		cordinates, length, width, and square
*************************************************************************/
class Rectangle : public Shape //Child Class
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Rectangle(QPaintDevice* device = nullptr, int id = -1);
     *   Constructor; this method initializes the Rectangle object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               id       (int)          - the id of the shape
     *   Return: none
     ***************************************************************/
    Rectangle(QPaintDevice* device = nullptr, int id = -1);

    /****************************************************************
     * ~Rectangle ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Rectangle();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void SetCordiantes(const QPoint& CORDINATES);
     *   Mutator; Initializes the cordinates for the Rectangle
     *   Parameters: CORDINATES (QPoint) - the cordinates for the shape
     *   Return: none
     ***************************************************************/
    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}

    /****************************************************************
     * void SetDimensions(const int &WIDTH, const int &LENGTH);
     *   Mutator; Initializes the dimensions for the Rectangle
     *   Parameters: WIDTH  (int) - the width of the Rectangle
     *               LENGTH (int) - the length of the Rectangle
     *   Return: none
     ***************************************************************/
    void SetDimensions(const int &LENGTH, const int &WIDTH);

    /****************************************************************
     * void SetDimensions(const int &LENGTH);
     *   Mutator; Initializes the dimensions for the Square
     *   Parameters: LENGTH  (int) - the length of the Square
     *   Return: none
     ***************************************************************/
    void SetDimensions(const int &LENGTH);

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
     *int GetWidth() const;
     *   Accessor; returns the width of the shape
     *   Parameters:
     *   Return: width
     ***************************************************************/
    int GetWidth() const{return width;}

    /****************************************************************
     *int GetLength() const;
     *   Accessor; returns the length of the shape
     *   Parameters:
     *   Return: length
     ***************************************************************/
    int GetLength() const{return length;}

    /****************************************************************
     * bool isSquare() const;
     *   Accessor; returns the if the shape is a square
     *   Parameters:
     *   Return: square
     ***************************************************************/
    bool isSquare() const{return square;}

    /***************************************************************
     * void Print(ostream& os) const;
     *   Accessor; outputs all of the shape properties
     *   Parameters: os (ostream&) - the output stream
     *   Return: nothing
     ***************************************************************/
    void Print(ostream& os) const;

private:
    QPoint cordinates; //The cordinates of the shape
    int    length;     //The length of the shape
    int    width;      //The width of the shape
    bool   square;     //The condition if the shape is a square
};

#endif // RECTANGLE_H
