#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter> /** Qpainter and QPaintDevice **/
#include <QtMath>   /** M_PI, qSqrt, pow **/
#include <fstream>  /** fin and fout              **/
#include "vector.h" /** Vector                    **/
using namespace MyVector;

//All the information that a shape could have for the program
struct newShapeInfo
{
    int           shapeId;      //The id of the shape
    QPen          shapePen;     //The pen for the shape
    QBrush        brush;        //The brush for the shape
    QFont         font;         //The font for the text
    Vector<int>   dimensions;   //The dimensions of the shape
    QString       text;         //The text that the text box will have
    QString       allignment;   //The allighment of the text
    QPen          textPen;      //The pen that the text will use
    QString       name;         //The name of the shape
};

//An enumerated type to match the Id that a shape can have
enum class ShapeType {NoShape, Line, Polyline, Polygon, Rectangle, Square,
                      Ellipse, Circle, Text};

/************************************************************************
* Shape Class
* 	This class represents a Shape object. It manages 6 attributes:
* 		qpainter, id, shape, pen, brush, and name
*************************************************************************/
class Shape //Base Class
{
public:
    /******************************
     **      OVERLOADERS         **
     ******************************/

    //Overloading the insertion operator for outputting
    friend ostream& operator<<(ostream& os, const Shape&);

    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/

    /****************************************************************
     * Shape(QPaintDevice* device, int shapeId, ShapeType shapeType);
     *   Constructor; this method initializes the Shape object
     *   Parameters: device   (QPaintDevice) - the device for the canvas
     *               shapeId  (int)          - the id of the shape
     *               shapeType(ShapeType)    - the type of shape
     *   Return: none
     ***************************************************************/
    Shape(QPaintDevice* device, int shapeId, ShapeType shapeType);

    //Disable copy operations
    Shape(const Shape& ) = delete;

    //Disable assignment operations
    Shape& operator=(const Shape& ) = delete;

    /****************************************************************
     * ~Shape ();
     *   Deconstructor; does not perform any specific function
     *   Parameters: none
     *   Return: none
     ***************************************************************/
    virtual ~Shape();

    /*******************
     **** MUTATORS  ****
     *******************/

    /****************************************************************
     * void SetShape(const ShapeType& SHAPE);
     *   Mutator; Initializes the ShapeType
     *   Parameters: SHAPE (ShapeType) - the shape type of the shape
     *   Return: none
     ***************************************************************/
    void SetShape(const ShapeType& SHAPE){shape = SHAPE;}

    /****************************************************************
     * void SetPen(const Qt::GlobalColor&, const int& WIDTH,
     *             const Qt::PenStyle&, const Qt::PenCapStyle&,
     *             const Qt::PenJoinStyle&);
     *   Mutator; Initializes the Pen of the shape
     *   Parameters: COLOR     (Qt::GlobalColor)  - the color of the pen
     *               WIDTH     (int)              - the width of the pen
     *               STYLE     (Qt::PenStyle)     - the style of the pen
     *               CAP_STYLE (Qt::PenCapStyle)  - the style of the pen cap
     *               JOIN_STYLE(Qt::PenJoinStyle) - the style of the pen join
     *   Return: none
     ***************************************************************/
    void SetPen(const Qt::GlobalColor& COLOR, const int& WIDTH,
                const Qt::PenStyle& STYLE, const Qt::PenCapStyle& CAP_STYLE,
                const Qt::PenJoinStyle& JOIN_STYLE);

    /****************************************************************
     *  void SetPen(const Qt::GlobalColor& COLOR);
     *   Mutator; Initializes the Pen of the shape
     *   Parameters: COLOR (Qt::GlobalColor)  - the color of the pen
     *   Return: none
     ***************************************************************/
    void SetPen(const Qt::GlobalColor& COLOR);

    /****************************************************************
     *  void SetPen(const QPen& PEN);
     *   Mutator; Initializes the Pen of the shape
     *   Parameters: PEN (QPen) - the pen
     *   Return: none
     ***************************************************************/
    void SetPen(const QPen& PEN);

    /****************************************************************
     * void SetBrush(const Qt::GlobalColor&, const Qt::BrushStyle&);
     *   Mutator; Initializes the Brush of the shape
     *   Parameters: COLOR     (Qt::GlobalColor)  - the color of the brush
     *               STYLE     (Qt::PenStyle)     - the style of the brush
     *   Return: none
     ***************************************************************/
    void SetBrush(const Qt::GlobalColor& COLOR, const Qt::BrushStyle& STYLE);

    /****************************************************************
     * void SetBrush(const QBrush& BRUSH);
     *   Mutator; Initializes the Brush of the shape
     *   Parameters: BRUSH (QBrush)  - the brush for the shape
     *   Return: none
     ***************************************************************/
    void SetBrush(const QBrush& BRUSH);

    /****************************************************************
     * void SetName(const QString& NAME);
     *   Mutator; Initializes the name of the shape
     *   Parameters: NAME (QString)  - the name for the shape
     *   Return: none
     ***************************************************************/
    void SetName(const QString& NAME) {name = NAME;}

    //This will move the shape according to the X and Y Cordinates passed in
    virtual void Move(const int& X, const int& Y) = 0;

    //This will draw the shape to the canvas that is passed in
    virtual void Draw(QPaintDevice* device) = 0;

    //This will calcualte and return the perimeter of the shape
    virtual float  Perimeter() const = 0;

    //This will calcualte and return the area of the shape
    virtual float  Area() const = 0;

    // This will output all of the shape properties
    virtual void Print(ostream& os) const = 0;

    /*******************
     **** ACCESSORS ****
     *******************/

    /****************************************************************
     * ShapeType GetShape() const;
     *   Accessor; returns the type of shape
     *   Parameters:
     *   Return: shape
     ***************************************************************/
    ShapeType GetShape() const{return shape;}

    /****************************************************************
     * QPen GetPen() const;
     *   Accessor; returns the pen of the shape
     *   Parameters:
     *   Return: pen
     ***************************************************************/
    QPen GetPen() const{return pen;}

    /****************************************************************
     * QBrush GetBrush() const;
     *   Accessor; returns the brush of the shape
     *   Parameters:
     *   Return: brush
     ***************************************************************/
    QBrush GetBrush() const{return brush;}

    /****************************************************************
     * QString GetName() const;
     *   Accessor; returns the name of the shape
     *   Parameters:
     *   Return: name
     ***************************************************************/
    QString GetName() const{return name;}

    /****************************************************************
     * int GetId() const;
     *   Accessor; returns the id of the shape
     *   Parameters:
     *   Return: id
     ***************************************************************/
    int GetId() const {return id;}

protected:
    /****************************************************************
     *  QPainter& GetPainter()
     *   Mutator; returns the painter by reference
     *   Parameters:
     *   Return: qpainter
     ***************************************************************/
    QPainter& GetPainter(){return qpainter;}

private:
    QPainter  qpainter;  //The painter of the shape
    int       id;        //The id of the shape
    ShapeType shape;     //The type of shape
    QPen      pen;       //The pen of the shape
    QBrush    brush;     //The brush of the shape
    QString   name;      //The name of the shape
};

// Helper functions
string ColortoStr(const QPen& PEN);
string BrushColorToStr(const QBrush& BRUSH);
string PenStyleToStr(const QPen& PEN);
string JoinStyleToStr(const QPen& PEN);
string CapStyleToStr(const QPen& PEN);
string BrushStyleToStr(const QBrush& BRUSH);

#endif // SHAPE_H
