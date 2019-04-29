#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Shape.h"
#include <QString>

class Textbox : public Shape
{
public:
    Textbox(QPaintDevice* device = nullptr, int id = -1)
        :Shape(device, id, ShapeType::Text)
    {
    }
    ~Textbox();

    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}

    void SetDimensions(const int &LENGTH, const int &WIDTH);

    void SetText(const QString &TEXT){text = TEXT;}

    void SetFont(const QFont &FONT){font = FONT;}

    void SetAllignment(const QString ALLIGNMENT);

    void Draw(const int& X, const int& Y);

    void Move(const int& X, const int& Y);

    float Perimeter() const{return (2 * width) + (2 * length);}

    float Area() const{return width * length;}

    int GetWidth() const {return width;}

    int GetLength() const {return length;}

    QPoint GetCords() const{return cordinates;}

    QString GetText() const {return text;}

    Qt::Alignment GetAlignment () {return alignment;}

private:
    int width;
    int length;
    QPoint cordinates;
    QString text;
    QFont font;
    Qt::Alignment alignment;
};

#endif // TEXTBOX_H
