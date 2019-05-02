#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <fstream>
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Textbox.h"
#include "createshape.h"

//enum ShapesID
//{
//    LINE = 1,
//    POLYLINE = 2,
//    POLYGON = 3,
//    RECTANGLE = 4,
//    SQUARE = 5,
//    ELLIPSE = 6,
//    CIRCLE = 7,
//    TEXT = 8
//};

const string INPUT_FILE = "shapes.txt";

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void AddNewShape(const newShapeInfo&);

    Vector<Shape*>& GetShapes() {return shapes;}
    void CreateNewShape(const int &shapeId);
signals:

public slots:
    void setShape(Shape *shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    Vector<Shape*> shapes;

private:
    Shape *currentShape;
    QPen pen;
    QBrush brush;
};

//Helper Functions
Qt::GlobalColor StrToColor(QString);
Qt::PenStyle StrToPenStyle(const QString&);
Qt::PenCapStyle StrToCapStyle(const QString&);
Qt::PenJoinStyle StrToJoinStyle(const QString&);
Qt::BrushStyle StrToBrushStyle(const QString&);
QFont::Style StrToFontStyle(const QString&);
QFont::Weight StrToFontWeight(const QString&);


#endif // RENDERAREA_H
