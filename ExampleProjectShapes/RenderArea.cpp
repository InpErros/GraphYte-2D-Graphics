#include "RenderArea.h"

RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    currentShape = nullptr;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(sizeHint());
}

RenderArea::~RenderArea()
{
    for(auto it: shapes)
        delete it;
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(2300, 600);
}

void RenderArea::AddNewShape(const newShapeInfo &NEW_SHAPE)
{
    switch (NEW_SHAPE.shapeId)
    {
    case LINE:
                    break;

    case POLYLINE:
                    break;

    case POLYGON:
                    break;
    case RECTANGLE:
                    break;
    case SQUARE:
                    break;
    case ELLIPSE:
                    break;
    case CIRCLE:
                    break;
    case TEXT:
                    break;
    default:        break;
    }
}

void RenderArea::setShape(Shape* shape)
{
    this->currentShape = shape;
    update();
}

void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
    update();
}

void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
    update();
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    int shapeId;
    int dimension;

    Line        *newLine;
    Polyline    *newPloyline;
    Polygon     *newPolygon;
    Rectangle   *newRectangle;
    Rectangle   *newSquare;
    Ellipse     *newEllipse;
    Ellipse     *newCircle;
    Textbox     *newTextbox;
    QFont       *textFont;
    QPen        *shapePen;
    QBrush      *shapeBrush;

    string penColor;
    int penWidth;
    string penStyle;
    string penCapStyle;
    string penJoinStyle;
    string brushColor;
    string brushStyle;
    string textString;
    string textColor;
    string textAllignment;
    int    textSize;
    string textFrontFam;
    string textFrontStyle;
    string textFontWeight;
    Vector<int>* shapeDimensions;

    textFont   = new QFont;
    shapePen   = new QPen;
    shapeBrush = new QBrush;
    shapeDimensions = new Vector<int>;


    ifstream fin(INPUT_FILE.c_str());

    while(!fin.eof())
    {
        fin.ignore(1000, ' ');
        fin >> shapeId;

        fin.ignore(1000, '\n');
        fin.ignore(1000, '\n');
        fin.ignore(1000, ' ');

        //Store the dimensions of the shape
        switch(shapeId)
        {
        case POLYLINE:
        case POLYGON:   for(int index = 0; index < 8; index++)
                        {
                            fin >> dimension;
                            shapeDimensions->push_back(dimension);

                            if(index < 7)
                                fin.ignore(1000, ' ');
                        }
                        break;
        case LINE:
        case RECTANGLE:
        case TEXT:
        case ELLIPSE:   for(int index = 0; index < 4; index++)
                        {
                            fin >> dimension;
                            shapeDimensions->push_back(dimension);

                            if(index < 3)
                                fin.ignore(1000, ' ');
                        }
                        break;
        case SQUARE:
        case CIRCLE:    for(int index = 0; index < 3; index++)
                        {
                            fin >> dimension;
                            shapeDimensions->push_back(dimension);

                            if(index < 2)
                                fin.ignore(1000, ' ');
                        }
                        break;
        default:        break;
        }
        fin.ignore(1000, '\n');

        fin.ignore(1000, ' ');

        if(shapeId != TEXT)
        {
            //Get the Pen info
            getline(fin, penColor);
            fin.ignore(1000, ' ');
            fin >> penWidth;
            fin.ignore(1000, '\n');
            fin.ignore(1000, ' ');
            getline(fin, penStyle);
            fin.ignore(1000, ' ');
            getline(fin, penCapStyle);
            fin.ignore(1000, ' ');
            getline(fin, penJoinStyle);

            //Set the Pen info
            shapePen->setColor(StrToColor(QString::fromStdString(penColor)));
            shapePen->setWidth(penWidth);
            shapePen->setStyle(StrToPenStyle(QString::fromStdString(penStyle)));
            shapePen->setCapStyle(StrToCapStyle
                                 (QString::fromStdString(penCapStyle)));
            shapePen->setJoinStyle(StrToJoinStyle
                                  (QString::fromStdString(penJoinStyle)));
            if(shapeId != LINE && shapeId != POLYLINE)
            {
                //Get Brush Info
                fin.ignore(1000, ' ');
                getline(fin, brushColor);
                fin.ignore(1000, ' ');
                getline(fin, brushStyle);

                //Set the Brush Info
                shapeBrush->setColor(StrToColor
                                    (QString::fromStdString(brushColor)));
                shapeBrush->setStyle(StrToBrushStyle
                                    (QString::fromStdString(brushStyle)));
            }
        }
        //If the shape is a text
        else
        {
            //Get the text info
            getline(fin, textString);
            fin.ignore(1000, ' ');
            getline(fin, textColor);
            fin.ignore(1000, ' ');
            getline(fin, textAllignment);
            fin.ignore(1000, ' ');
            fin >> textSize;
            fin.ignore(1000, '\n');
            fin.ignore(1000, ' ');
            getline(fin, textFrontFam);
            fin.ignore(1000, ' ');
            getline(fin, textFrontStyle);
            fin.ignore(1000, ' ');
            getline(fin, textFontWeight);

            //Set the text info
            textFont->setPointSize(textSize);
            textFont->setFamily(QString::fromStdString(textFrontFam));
            textFont->setWeight(StrToFontWeight
                               (QString::fromStdString(textFontWeight)));
        }

        //Create the shape based on the shape Id
        switch(shapeId)
        {
        case LINE:      newLine = new Line(this , LINE);
                        newLine->SetCordinates
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)),
                                 QPoint(shapeDimensions->operator[](2),
                                        shapeDimensions->operator[](3)));
                        newLine->SetPen(*shapePen);
                        shapes.push_back(newLine);
                        newLine->Draw();
                        break;

        case POLYLINE:  newPloyline = new Polyline(this , POLYLINE);
                        newPloyline->AddPoint
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newPloyline->AddPoint
                                 (QPoint(shapeDimensions->operator[](2),
                                         shapeDimensions->operator[](3)));
                        newPloyline->AddPoint
                                  (QPoint(shapeDimensions->operator[](4),
                                          shapeDimensions->operator[](5)));
                        newPloyline->AddPoint
                                   (QPoint(shapeDimensions->operator[](6),
                                           shapeDimensions->operator[](7)));
                        newPloyline->SetPen(*shapePen);
                        shapes.push_back(newPloyline);
                        newPloyline->Draw();
                        break;

        case POLYGON:   newPolygon = new Polygon(this , POLYGON);
                        newPolygon->AddPoint
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newPolygon->AddPoint
                                 (QPoint(shapeDimensions->operator[](2),
                                         shapeDimensions->operator[](3)));
                        newPolygon->AddPoint
                                  (QPoint(shapeDimensions->operator[](4),
                                          shapeDimensions->operator[](5)));
                        newPolygon->AddPoint
                                   (QPoint(shapeDimensions->operator[](6),
                                           shapeDimensions->operator[](7)));
                        newPolygon->SetPen(*shapePen);
                        newPolygon->SetBrush(*shapeBrush);
                        shapes.push_back(newPolygon);
                        newPolygon->Draw();
                        break;
        case RECTANGLE: newRectangle = new Rectangle(this , RECTANGLE);
                        newRectangle->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newRectangle->SetDimensions
                                 (shapeDimensions->operator[](2),
                                  shapeDimensions->operator[](3));
                        newRectangle->SetPen(*shapePen);
                        newRectangle->SetBrush(*shapeBrush);
                        shapes.push_back(newRectangle);
                        newRectangle->Draw();
                        break;
        case SQUARE:    newSquare = new Rectangle(this , SQUARE);
                        newSquare->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newSquare->SetDimensions
                                 (shapeDimensions->operator[](2));
                        newSquare->SetPen(*shapePen);
                        newSquare->SetBrush(*shapeBrush);
                        shapes.push_back(newSquare);
                        newSquare->Draw();
                        break;
        case ELLIPSE:   newEllipse = new Ellipse(this , ELLIPSE);
                        newEllipse->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newEllipse->SetDimensions
                                 (shapeDimensions->operator[](2),
                                  shapeDimensions->operator[](3));
                        newEllipse->SetPen(*shapePen);
                        newEllipse->SetBrush(*shapeBrush);
                        shapes.push_back(newEllipse);
                        newEllipse->Draw();
                        break;
        case CIRCLE:    newCircle = new Ellipse(this , CIRCLE);
                        newCircle->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newCircle->SetDimensions
                                 (shapeDimensions->operator[](2));
                        newCircle->SetPen(*shapePen);
                        newCircle->SetBrush(*shapeBrush);
                        shapes.push_back(newCircle);
                        newCircle->Draw();
                        break;
        case TEXT:      newTextbox = new Textbox(this, TEXT);
                        newTextbox->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));
                        newTextbox->SetDimensions
                                 (shapeDimensions->operator[](2),
                                  shapeDimensions->operator[](3));
                        newTextbox->SetPen(StrToColor
                                           (QString::fromStdString(textColor)));
                        newTextbox->SetText(QString::fromStdString(textString));
                        newTextbox->SetAllignment(QString::fromStdString
                                                  (textAllignment));
                        newTextbox->SetFont(*textFont);
                        shapes.push_back(newTextbox);
                        newTextbox->Draw();
                        break;
        default:        break;
        }

        fin.ignore(1000, '\n');

        textFont   = new QFont;
        shapePen   = new QPen;
        shapeBrush = new QBrush;
        shapeDimensions = new Vector<int>;
    }//End while

    fin.close();
    delete textFont;
    delete shapePen;
    delete shapeBrush;
    delete shapeDimensions;
}

//Helper functions
Qt::GlobalColor StrToColor(QString info)
{
    info = info.toLower();

    Qt::GlobalColor color = Qt::white;

         if(info == "blue")   {color = Qt::blue;}
    else if(info == "red")    {color = Qt::red;}
    else if(info == "cyan")   {color = Qt::cyan;}
    else if(info == "yellow") {color = Qt::yellow;}
    else if(info == "magenta"){color = Qt::magenta;}
    else if(info == "black")  {color = Qt::black;}
    else if(info == "green")  {color = Qt::green;}
    else if(info == "gray")   {color = Qt::gray;}

    return color;
}

Qt::PenStyle StrToPenStyle(const QString& INFO)
{
    Qt::PenStyle penStyle = Qt::NoPen;

         if(INFO == "DashDotLine")   {penStyle = Qt::DashDotLine;}
    else if(INFO == "SolidLine")     {penStyle = Qt::SolidLine;}
    else if(INFO == "DashLine")      {penStyle = Qt::DashLine;}
    else if(INFO == "DotLine")       {penStyle = Qt::DotLine;}
    else if(INFO == "CustomDashLine"){penStyle = Qt::CustomDashLine;}
    else if(INFO == "DashDotDotLine"){penStyle = Qt::DashDotDotLine;}

    return penStyle;
}

Qt::PenCapStyle StrToCapStyle(const QString& INFO)
{
    Qt::PenCapStyle style = Qt::FlatCap;

         if(INFO == "SquareCap"){style = Qt::SquareCap;}
    else if(INFO == "RoundCap") {style = Qt::RoundCap;}
    else if(INFO == "FlatCap")  {style = Qt::FlatCap;}

    return style;
}

Qt::PenJoinStyle StrToJoinStyle(const QString& INFO)
{
    Qt::PenJoinStyle style = Qt::MiterJoin;

         if(INFO == "MiterJoin"){style = Qt::MiterJoin;}
    else if(INFO == "RoundJoin"){style = Qt::RoundJoin;}
    else if(INFO == "BevelJoin"){style = Qt::BevelJoin;}

    return style;
}

Qt::BrushStyle StrToBrushStyle(const QString& INFO)
{
    Qt::BrushStyle style = Qt::NoBrush;

        if(INFO == "SolidPattern"){style = Qt::SolidPattern;}
   else if(INFO == "VerPattern")  {style = Qt::VerPattern;}
   else if(INFO == "HorPattern")  {style = Qt::HorPattern;}

   return style;
}

QFont::Style StrToFontStyle(const QString& INFO)
{
    QFont::Style style = QFont::StyleNormal;

         if(INFO == "StyleNormal") {style = QFont::StyleNormal;}
    else if(INFO == "StyleItalic") {style = QFont::StyleItalic;}
    else if(INFO == "StyleOblique"){style = QFont::StyleOblique;}

    return style;
}

QFont::Weight StrToFontWeight(const QString& INFO)
{
    QFont::Weight weight = QFont::Normal;

         if(INFO == "Thin")  {weight = QFont::Thin;}
    else if(INFO == "Light") {weight = QFont::Light;}
    else if(INFO == "Normal"){weight = QFont::Normal;}
    else if(INFO == "Bold")  {weight = QFont::Bold;}

    return weight;
}
