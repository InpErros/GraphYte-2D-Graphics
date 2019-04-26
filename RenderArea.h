#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    void CreateShape(const int& shapeId) const;

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

#endif // RENDERAREA_H
