#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"/** Shape   **/
#include <QString>/** QString **/

/************************************************************************
* Textbox Class
* 	This class represents a Textbox object. It manages 6 attributes:
* 		cordinates, width, length, text, font, and allignment
*************************************************************************/
class Textbox : public Shape //Child Class
{
public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Textbox(QPaintDevice* device = nullptr, int id = -1);
     *   Constructor; this method initializes the Textbox object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               id       (int)          - the id of the shape
     *   Return: none
     ***************************************************************/
    Textbox(QPaintDevice* device = nullptr, int id = -1);

    /****************************************************************
     * ~Textbox ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Textbox();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void SetCordiantes(const QPoint& CORDINATES);
     *   Mutator; Initializes the cordinates for the Textbox
     *   Parameters: CORDINATES (QPoint) - the cordinates for the shape
     *   Return: none
     ***************************************************************/
    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}

    /****************************************************************
     * void SetDimensions(const int &WIDTH, const int &LENGTH);
     *   Mutator; Initializes the dimensions for the Textbox
     *   Parameters: WIDTH  (int) - the width of the Textbox
     *               LENGTH (int) - the length of the Textbox
     *   Return: none
     ***************************************************************/
    void SetDimensions(const int &LENGTH, const int &WIDTH);

    /****************************************************************
     * void SetText(const QString &TEXT);
     *   Mutator; Initializes the text for the Textbox
     *   Parameters: TEXT  (QString) - the text of the Textbox
     *   Return: none
     ***************************************************************/
    void SetText(const QString &TEXT){text = TEXT;}

    /****************************************************************
     * void SetFont(const QString &FONT);
     *   Mutator; Initializes the font for the Textbox
     *   Parameters: FONT  (QString) - the text of the Textbox
     *   Return: none
     ***************************************************************/
    void SetFont(const QFont &FONT){GetPainter().setFont(FONT);}

    /****************************************************************
     * void SetAllignment(const QString& ALLIGNMENT);
     *   Mutator; Initializes the allignment for the Textbox
     *   Parameters: ALLIGNMENT  (QString) - the allignment of the Textbox
     *   Return: none
     ***************************************************************/
    void SetAllignment(const QString& ALLIGNMENT);

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
    float Perimeter() const{return (2 * width) + (2 * length);}

    /****************************************************************
     * float Area() const;
     *   Accessor; Calcualtes and returns the area of the shape
     *   Parameters:
     *   Return: area
     ***************************************************************/
    float Area() const{return width * length;}

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
     * QPoint GetCords() const;
     *   Accessor; returns the cordinates of the shape
     *   Parameters:
     *   Return: cordinates
     ***************************************************************/
    QPoint GetCords() const{return cordinates;}

    /****************************************************************
     * QString GetText() const;
     *   Accessor; returns the text of the shape
     *   Parameters:
     *   Return: text
     ***************************************************************/
    QString GetText() const {return text;}

    /****************************************************************
     * QFont GetFont() const;
     *   Accessor; returns the font of the text
     *   Parameters:
     *   Return: font
     ***************************************************************/
    QFont GetFont() const {return font;}

    /****************************************************************
     * Qt::Alignment GetAlignment () const;
     *   Accessor; returns the allignment of the text
     *   Parameters:
     *   Return: text
     ***************************************************************/
    Qt::Alignment GetAlignment () const {return alignment;}

private:
    QPoint cordinates;          //The cordinates of the shape
    int    length;              //The length of the shape
    int    width;               //The width of the shape
    QString       text;         //The text of the shape
    QFont         font;         //The font of the shape
    Qt::Alignment alignment;    //The allignment of the shape
};

#endif // TEXTBOX_H
