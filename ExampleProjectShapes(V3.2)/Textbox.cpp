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

void Textbox::Draw(QPaintDevice* device)
{
    QPainter painter(device);
    QPen newPen = GetPen();
    QBrush newBrush = GetBrush();

    painter.setPen(newPen);
    painter.setBrush(newBrush);

    QRect rect(cordinates.x(), cordinates.y(), width, length);

    painter.save();

    painter.drawText(rect,signed(alignment), text);

    painter.restore();
}

void Textbox::Move(const int &X, const int &Y)
{
    SetCordiantes(QPoint(X, Y));
}
