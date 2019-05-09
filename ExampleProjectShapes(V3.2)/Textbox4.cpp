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



void Textbox::Print(ostream& os)
{

    os << "ShapeId: " << GetId() << endl;
    os << "ShapeType: Text" << endl;;
    os << "ShapeDimensions: " << cordinates.x() << ", "
                              << cordinates.y() << ", "
                              << length         << ", "
                              << width          << endl;
    os << "TextString: " << text.toStdString() << endl;
    os << "TextColor: " << BrushColorToStr(GetBrush()) << endl;
    os << "TextAlignment: " << alignment << endl;
    os << "TextPointSize: " << font.pointSize() << endl;
    os << "TextFontFamily: " << font.family().toStdString() << endl;
    os << "TextFontStyle: " << FontStyleToStr(font) << endl;
    os << "TextFontWeight: " << FontWeightToStr(font) << endl;
}

string FontStyleToStr(QFont font)
{
    string fontStyle;

    if(font.style()      == QFont::StyleNormal)  {fontStyle = "StyleNormal";}
    else if(font.style() == QFont::StyleItalic)  {fontStyle = "StyleItalic";}
    else if(font.style() == QFont::StyleOblique) {fontStyle = "StyleOblique";}

    return fontStyle;
}

string FontWeightToStr(QFont font)
{
    string fontWeight;

    if(font.weight()       == QFont::Thin)  {fontWeight = "Thin";}
    else if(font.weight()  == QFont::Light)  {fontWeight = "Light";}
    else if(font.weight()  == QFont::Normal) {fontWeight = "Normal";}
    else if (font.weight() == QFont::Bold)   {fontWeight = "Bold";}

    return fontWeight;
}
