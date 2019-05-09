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
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea() override;

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void CreateDefault();

    void UpdateCanvas();

    Vector<Shape*> shapes;
signals:

public slots:
    void setShape(Shape *shape);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

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
