#include "Textbox.h"

Textbox::~Textbox()
{
}

void Textbox::SetDimensions(const int &LENGTH, const int &WIDTH)
{
    length = LENGTH;
    width  = WIDTH;
}

void Textbox::SetAllignment(const QString ALLIGNMENT)
{
    if(ALLIGNMENT == "AlignCenter")
    {
        this->alignment = Qt::AlignCenter;
    }
    else if(ALLIGNMENT == "AlignRight")
    {
        this->alignment = Qt::AlignRight;
    }
    else if(ALLIGNMENT == "AlignLeft")
    {
        this->alignment = Qt::AlignLeft;
    }
}

void Textbox::Draw(const int &X, const int &Y)
{
    QRect rect(cordinates.x(), cordinates.y(), width, length);

    GetPainter().translate(X, Y);
    GetPainter().drawText(rect, text);
}

void Textbox::Move(const int &X, const int &Y)
{
    QRect rect(cordinates.x(), cordinates.y(), width, length);

    GetPainter().translate(X, Y);
    GetPainter().drawText(rect, text);
}
