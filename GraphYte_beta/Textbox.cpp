#include "Textbox.h"

/************************************************************************
* Method Textbox: Class Textbox
*----------------------------------------------------------------------
* 	 This method creates the Textbox object
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
Textbox::Textbox(QPaintDevice* device, int id)
            :Shape(device, id, ShapeType::Text)
{
    length = 0;
    width  = 0;
}

/************************************************************************
* Method ~Textbox: Class Textbox
*----------------------------------------------------------------------
* 	 This method deletes the Textbox object
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
Textbox::~Textbox()
{
}

/************************************************************************
* Method SetDimensions: Class Textbox
*----------------------------------------------------------------------
* 	 This method set the dimensions for the Textbox
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       WIDTH   (int) - the width of the Rectangle
*       LENGTH  (int) - the length of the Rectangle
*
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Textbox::SetDimensions(const int &LENGTH, const int &WIDTH)
{
    length = LENGTH;
    width  = WIDTH;
}

/************************************************************************
* Method SetAllignment: Class Textbox
*----------------------------------------------------------------------
* 	 This method set the allignment for the Textbox
* 	 ==> returns nothing
*-----------------------------------------------------------------------
* PRE-CONDITIONS
* 	The following need to be passed in
*       ALLIGNMENT   (QString) - the allignment of the textbox
* POST-CONDITIONS
* 	==> returns nothing
*************************************************************************/
void Textbox::SetAllignment(const QString& ALLIGNMENT)
{
    if     (ALLIGNMENT == "AlignCenter"){alignment = Qt::AlignCenter;}
    else if(ALLIGNMENT == "AlignRight") {alignment = Qt::AlignRight;}
    else if(ALLIGNMENT == "AlignLeft")  {alignment = Qt::AlignLeft;}
}

/************************************************************************
* Method Draw: Class Textbox
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
void Textbox::Draw(QPaintDevice* device)
{
    QPainter painter(device);   //Create a new painter to draw the shape to
    QPen     newPen;            //The pen for the new painter
    QRect    rect;              //The rectangle box

    //PROCESSING - Get the values of the old painter
    newPen   = GetPen();

    //PROCESSING - Set the values for the new painter
    painter.setPen  (newPen);

    //PROCESSING - Set the values of the rectangle
    rect.setRect(cordinates.x(), cordinates.y(), width, length);

    //PROCESSING - save current state of the painter
    painter.save();

    painter.drawText(rect,signed(alignment), text);

    //PROCESSING - return the state of the current painter
    painter.restore();
}

/************************************************************************
* Method Move: Class Textbox
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
void Textbox::Move(const int &X, const int &Y)
{
    SetCordiantes(QPoint(X, Y));
}
