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
    virtual ~Textbox();

    void SetCordiantes(const QPoint& CORDINATES){cordinates = CORDINATES;}

    void SetDimensions(const int &LENGTH, const int &WIDTH);

    void SetText(const QString &TEXT){text = TEXT;}

    void SetFont(const QFont &FONT){GetPainter().setFont(FONT);}

    void SetAllignment(const QString ALLIGNMENT);

    void Draw(QPaintDevice* device);

    void Move(const int& X, const int& Y);

    float Perimeter() const{return (2 * width) + (2 * length);}

    float Area() const{return width * length;}

    int GetWidth() const {return width;}

    int GetLength() const {return length;}

    QPoint GetCords() const{return cordinates;}

    QString GetText() const {return text;}

    QFont GetFont() const {return font;}

    Qt::Alignment GetAlignment () {return alignment;}

    void Print(ostream& os);


private:
    int width;
    int length;
    QPoint cordinates;
    QString text;
    QFont font;
    Qt::Alignment alignment;
};

string FontStyleToStr(QFont font);
string FontWeightToStr(QFont font);

#endif // TEXTBOX_H
