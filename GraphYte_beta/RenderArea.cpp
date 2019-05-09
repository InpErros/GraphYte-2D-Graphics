#include "RenderArea.h"

//Constructor
RenderArea::RenderArea(QWidget *parent) : QWidget(parent)
{
    //Load in the deafult shapes from the input file
    CreateDefault();

    setBackgroundRole(QPalette::Base);

    setAutoFillBackground(true);

    setFixedSize(sizeHint());
}

RenderArea::~RenderArea()
{
    //Delete all the shapes that have been generated
    for(auto it: shapes)
        delete it;
}

//Set the minimum size of the screen
QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

//Set the prefered screen size
QSize RenderArea::sizeHint() const
{
    return QSize(2300, 600);
}

//Load in all the shapes from the input file
void RenderArea::CreateDefault()
{
    Line        *newLine;           //The new line
    Polyline    *newPloyline;       //The new polyline
    Polygon     *newPolygon;        //The new polygon
    Rectangle   *newRectangle;      //The new rectangle
    Rectangle   *newSquare;         //The new square
    Ellipse     *newEllipse;        //The new ellipse
    Ellipse     *newCircle;         //The new circle
    Textbox     *newTextbox;        //The new textbox
    QFont       *textFont;          //The font of the text
    QPen        *shapePen;          //The pen for the shape
    QBrush      *shapeBrush;        //The brush for the shape
    Vector<int> *shapeDimensions;   //The dimensions of the shape

    int         shapeId;            //The id of the shape
    int         dimension;          //The dimension of the shape
    int         penWidth;           //The width of the pen
    int         textSize;           //The size of the text
    int         index;              //The index in the array

    string      penColor;           //The pen color
    string      penStyle;           //The pen style
    string      penCapStyle;        //The pen cap style
    string      penJoinStyle;       //The pen join style
    string      brushColor;         //The brush color
    string      brushStyle;         //The brush style
    string      textString;         //The text
    string      textColor;          //The text color
    string      textAllignment;     //The text allignmnet
    string      textFrontFam;       //The text font family
    string      textFrontStyle;     //The text font style
    string      textFontWeight;     //The text font weight

    ShapeType   shapeType;          //The enumerated type of the shape

    ifstream fin(INPUT_FILE.c_str());//The input file variable

    //Initialize the pointers
    textFont        = new QFont;
    shapePen        = new QPen;
    shapeBrush      = new QBrush;
    shapeDimensions = new Vector<int>;

    //While not at the end of the file, keep loading in shapes
    while(!fin.eof())
    {
        fin.ignore(1000, ' ');
        fin >> shapeId;

        fin.ignore(1000, '\n');
        fin.ignore(1000, '\n');
        fin.ignore(1000, ' ');

        shapeType = static_cast<ShapeType>(shapeId);

        //Store the dimensions of the shape
        switch(shapeType)
        {
        case ShapeType::Polyline:
        case ShapeType::Polygon:    for(index = 0; index < 8; index++)
                                    {
                                        fin >> dimension;

                                        shapeDimensions->push_back(dimension);

                                        if(index < 7){fin.ignore(1000, ' ');}
                                    }
                                    break;

        case ShapeType::Line:
        case ShapeType::Rectangle:
        case ShapeType::Text:
        case ShapeType::Ellipse:    for(index = 0; index < 4; index++)
                                    {
                                        fin >> dimension;

                                        shapeDimensions->push_back(dimension);

                                        if(index < 3){fin.ignore(1000, ' ');}
                                    }
                                    break;
        case ShapeType::Square:
        case ShapeType::Circle:     for(index = 0; index < 3; index++)
                                    {
                                        fin >> dimension;

                                        shapeDimensions->push_back(dimension);

                                        if(index < 2){fin.ignore(1000, ' ');}
                                    }
                        break;

        default:        break;
        }
        fin.ignore(1000, '\n');

        fin.ignore(1000, ' ');

        if(shapeType != ShapeType::Text)
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

            //Get Brush Info
            if(shapeType != ShapeType::Line && shapeType != ShapeType::Polyline)
            {
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
        switch(shapeType)
        {
        case ShapeType::Line: newLine = new Line(this ,
                                                 static_cast<int>(shapeType));
                              newLine->SetCordinates
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)),
                                 QPoint(shapeDimensions->operator[](2),
                                        shapeDimensions->operator[](3)));

                             newLine->SetPen(*shapePen);

                             newLine->SetName("Default Line");

                             shapes.push_back(newLine);

                             break;

        case ShapeType::Polyline:  newPloyline = new Polyline(this ,
                                                   static_cast<int>(shapeType));

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

                        newPloyline->SetName("Default Polyline");

                        shapes.push_back(newPloyline);

                        break;

        case ShapeType::Polygon:   newPolygon = new Polygon(this ,
                                                   static_cast<int>(shapeType));

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

                        newPolygon->SetName("Default Polygon");

                        shapes.push_back(newPolygon);

                        break;

        case ShapeType::Rectangle: newRectangle = new Rectangle(this ,
                                                   static_cast<int>(shapeType));

                        newRectangle->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));

                        newRectangle->SetDimensions
                                 (shapeDimensions->operator[](2),
                                  shapeDimensions->operator[](3));

                        newRectangle->SetPen(*shapePen);

                        newRectangle->SetBrush(*shapeBrush);

                        newRectangle->SetName("Default Rectangle");

                        shapes.push_back(newRectangle);

                        break;

        case ShapeType::Square:    newSquare = new Rectangle(this ,
                                                   static_cast<int>(shapeType));

                        newSquare->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));

                        newSquare->SetDimensions
                                 (shapeDimensions->operator[](2));

                        newSquare->SetPen(*shapePen);

                        newSquare->SetBrush(*shapeBrush);

                        newSquare->SetName("Default Square");

                        shapes.push_back(newSquare);

                        break;

        case ShapeType::Ellipse:   newEllipse = new Ellipse(this ,
                                                   static_cast<int>(shapeType));

                        newEllipse->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));

                        newEllipse->SetDimensions
                                 (shapeDimensions->operator[](2),
                                  shapeDimensions->operator[](3));

                        newEllipse->SetPen(*shapePen);

                        newEllipse->SetBrush(*shapeBrush);

                        newEllipse->SetName("Default Ellipse");

                        shapes.push_back(newEllipse);

                        break;
        case ShapeType::Circle:    newCircle = new Ellipse(this ,
                                                   static_cast<int>(shapeType));

                        newCircle->SetCordiantes
                                (QPoint(shapeDimensions->operator[](0),
                                        shapeDimensions->operator[](1)));

                        newCircle->SetDimensions
                                 (shapeDimensions->operator[](2));

                        newCircle->SetPen(*shapePen);

                        newCircle->SetBrush(*shapeBrush);

                        newCircle->SetName("Default Circle");

                        shapes.push_back(newCircle);

                        break;

        case ShapeType::Text:      newTextbox = new Textbox(this,
                                                   static_cast<int>(shapeType));

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

                        newTextbox->SetName("Default Textbox");

                        shapes.push_back(newTextbox);

                        break;

        default:        break;
        }

        fin.ignore(1000, '\n');

        textFont        = new QFont;
        shapePen        = new QPen;
        shapeBrush      = new QBrush;
        shapeDimensions = new Vector<int>;
    }//End while

    fin.close();
    delete textFont;
    delete shapePen;
    delete shapeBrush;
    delete shapeDimensions;
}

//Call an update to the canvas
void RenderArea::UpdateCanvas()
{
    update();
    ShapeFunc<Shape*>::PrintShapeListing(shapes);
    ShapeFunc<Shape*>::PrintAreaShapeListing(shapes);
    ShapeFunc<Shape*>::PrintPerimeterShapeListing(shapes);
}

//Draw the shapes in the vector to the canvas
void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QPaintDevice* device = this;

    Vector<Shape*>::iterator i = shapes.begin();

    while(i < shapes.end())
    {
        (*i)->Draw(device);
        ++i;
    }
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
