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

const string INPUT_FILE = "shapes.txt";

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    //Constructor
    explicit RenderArea(QWidget *parent = nullptr);

    //Desstructor
    ~RenderArea();

    //Overrides for the screen size
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    //Load in the shapes from the input file
    void CreateDefault();

    //Trigger an update to the canvas
    void UpdateCanvas();

    //The vector of all the shapes that have been created
    Vector<Shape*> shapes;
signals:

public slots:

protected:
    //The canvas where the shapes are drawn
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    QPen pen;       //The pen of the canvas
    QBrush brush;   //The brush of the canvas
};

//Helper Functions
Qt::GlobalColor     StrToColor(QString);
Qt::PenStyle        StrToPenStyle(const QString&);
Qt::PenCapStyle     StrToCapStyle(const QString&);
Qt::PenJoinStyle    StrToJoinStyle(const QString&);
Qt::BrushStyle      StrToBrushStyle(const QString&);
QFont::Style        StrToFontStyle(const QString&);
QFont::Weight       StrToFontWeight(const QString&);

#endif // RENDERAREA_H
