#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    renderArea         = new RenderArea;
    createShape        = new CreateShape;

    this->layout()->addWidget(renderArea);

    connect(createShape, SIGNAL(shapeGenerated(newShapeInfo)),
            this, SLOT(GenerateShape(newShapeInfo)));

    renderArea->move(10, 50);
}

MainWindow::~MainWindow()
{
    PrintShapeListing(renderArea->shapes);

    delete ui;
    delete renderArea;
    delete createShape;

}

void MainWindow::shapeChanged()
{

}

void MainWindow::penChanged()
{

}

void MainWindow::brushChanged()
{

}

void MainWindow::GenerateShape(const newShapeInfo& NEW_SHAPE)
{
    Line        *newLine;
    Polyline    *newPloyline;
    Polygon     *newPolygon;
    Rectangle   *newRectangle;
    Rectangle   *newSquare;
    Ellipse     *newEllipse;
    Ellipse     *newCircle;
    Textbox     *newTextbox;

    ShapeType shapeType;

    int index;

    shapeType = static_cast<ShapeType>(NEW_SHAPE.shapeId);

    switch(shapeType)
    {
    case ShapeType::Line:      newLine = new Line(this , static_cast<int>(shapeType));
                    newLine->SetCordinates
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)),
                             QPoint(NEW_SHAPE.dimensions.operator[](2),
                                    NEW_SHAPE.dimensions.operator[](3)));
                    newLine->SetPen(NEW_SHAPE.shapePen);
                    newLine->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newLine);
                    break;

    case ShapeType::Polyline:  newPloyline = new Polyline(this , static_cast<int>(shapeType));
                    for(index = 0; index < NEW_SHAPE.dimensions.size(); index+=2)
                    {
                        newPloyline->AddPoint
                       (QPoint(NEW_SHAPE.dimensions.operator[](index),
                               NEW_SHAPE.dimensions.operator[](index + 1)));
                    }
                    newPloyline->SetPen(NEW_SHAPE.shapePen);
                    newPloyline->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newPloyline);
                    break;

    case ShapeType::Polygon:   newPolygon = new Polygon(this , static_cast<int>(shapeType));
                    for(index = 0; index < NEW_SHAPE.dimensions.size(); index+=2)
                    {
                        newPolygon->AddPoint
                       (QPoint(NEW_SHAPE.dimensions.operator[](index),
                               NEW_SHAPE.dimensions.operator[](index + 1)));
                    }
                    newPolygon->SetPen(NEW_SHAPE.shapePen);
                    newPolygon->SetBrush(NEW_SHAPE.brush);
                    newPolygon->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newPolygon);
                    break;

    case ShapeType::Rectangle: newRectangle = new Rectangle(this , static_cast<int>(shapeType));
                    newRectangle->SetCordiantes
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)));
                    newRectangle->SetDimensions
                             (NEW_SHAPE.dimensions.operator[](2),
                              NEW_SHAPE.dimensions.operator[](3));
                    newRectangle->SetPen(NEW_SHAPE.shapePen);
                    newRectangle->SetBrush(NEW_SHAPE.brush);
                    newRectangle->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newRectangle);
                    break;

    case ShapeType::Square:    newSquare = new Rectangle(this , static_cast<int>(shapeType));
                    newSquare->SetCordiantes
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)));
                    newSquare->SetDimensions
                             (NEW_SHAPE.dimensions.operator[](2));
                    newSquare->SetPen(NEW_SHAPE.shapePen);
                    newSquare->SetBrush(NEW_SHAPE.brush);
                    newSquare->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newSquare);
                    break;

    case ShapeType::Ellipse:   newEllipse = new Ellipse(this , static_cast<int>(shapeType));
                    newEllipse->SetCordiantes
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)));
                    newEllipse->SetDimensions
                             (NEW_SHAPE.dimensions.operator[](2),
                              NEW_SHAPE.dimensions.operator[](3));
                    newEllipse->SetPen(NEW_SHAPE.shapePen);
                    newEllipse->SetBrush(NEW_SHAPE.brush);
                    newEllipse->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newEllipse);
                    break;
    case ShapeType::Circle:    newCircle = new Ellipse(this , static_cast<int>(shapeType));
                    newCircle->SetCordiantes
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)));
                    newCircle->SetDimensions
                             (NEW_SHAPE.dimensions.operator[](2));
                    newCircle->SetPen(NEW_SHAPE.shapePen);
                    newCircle->SetBrush(NEW_SHAPE.brush);
                    newCircle->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newCircle);
                    break;
    case ShapeType::Text:      newTextbox = new Textbox(this, static_cast<int>(shapeType));
                    newTextbox->SetCordiantes
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)));
                    newTextbox->SetDimensions
                             (NEW_SHAPE.dimensions.operator[](2),
                              NEW_SHAPE.dimensions.operator[](3));
                    newTextbox->SetPen(NEW_SHAPE.textPen);
                    newTextbox->SetText(NEW_SHAPE.text);
                    newTextbox->SetAllignment(NEW_SHAPE.allignment);
                    newTextbox->SetFont(NEW_SHAPE.font);
                    newTextbox->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newTextbox);
                    break;
    default:        break;
    }

    renderArea->UpdateCanvas();
}

void MainWindow::GetNewCordinates()
{
    int index;
    int i;
    Vector<int> *shapeCordinates;
    bool ok;
    QStringList items;
    ShapeType shapeType;

    shapeCordinates = new Vector<int>;
    ok = true;

    for(index = 0; index < renderArea->shapes.size(); index++)
        items << renderArea->shapes[index]->GetName();

    QString item = QInputDialog::getItem(this, tr("Move a Shape"),
                                         tr("Name:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
    {
        index = items.indexOf(item);

        shapeType = static_cast<ShapeType>(index + 1);

        switch (shapeType)
        {
        case ShapeType::Line:       GetCordinateInput(ok, *shapeCordinates);
                                    if(ok)
                                    {
                                        GetCordinateInput(ok, *shapeCordinates);
                                        if(ok)
                                        {
                                            renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](0),
                                                shapeCordinates->operator[](1));
                                            renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](2),
                                                shapeCordinates->operator[](3));
                                        }
                                    }
                                    break;
        case ShapeType::Polyline:   for(i = 0; i < (MAX_POLY_SIDES/2); i+=2)
                                    {
                                        if(ok)
                                        {
                                            GetCordinateInput(ok,
                                                              *shapeCordinates);
                                            if(ok)
                                            {
                                                GetCordinateInput(ok,
                                                              *shapeCordinates);
                                            }
                                        }
                                    }

                                    if(ok)
                                    {
                                        for(i = 0; i < MAX_POLY_SIDES; i+=2)
                                        {
                                            renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](i),
                                                shapeCordinates->operator[](i+1)
                                                );
                                        }
                                    }
                                    break;
        case ShapeType::Polygon:    for(i = 0; i < (MAX_POLY_SIDES/2); i+=2)
                                    {
                                        if(ok)
                                        {
                                            GetCordinateInput(ok,
                                                              *shapeCordinates);
                                            if(ok)
                                            {
                                                GetCordinateInput(ok,
                                                              *shapeCordinates);
                                            }
                                        }
                                    }

                                    if(ok)
                                    {
                                        for(i = 0; i < MAX_POLY_SIDES; i+=2)
                                        {
                                            renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](i),
                                                shapeCordinates->operator[](i+1)
                                                );
                                        }
                                    }
                                    break;
        case ShapeType::Rectangle:  GetCordinateInput(ok, *shapeCordinates);
                                    if(ok)
                                    {
                                        renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](0),
                                                shapeCordinates->operator[](1));
                                    }
                                    break;
        case ShapeType::Square:     GetCordinateInput(ok, *shapeCordinates);
                                    if(ok)
                                    {
                                        renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](0),
                                                shapeCordinates->operator[](1));
                                    }
                                    break;
        case ShapeType::Ellipse:    GetCordinateInput(ok, *shapeCordinates);
                                    if(ok)
                                    {
                                        renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](0),
                                                shapeCordinates->operator[](1));
                                    }
                                    break;
        case ShapeType::Circle:     GetCordinateInput(ok, *shapeCordinates);
                                    if(ok)
                                    {
                                        renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](0),
                                                shapeCordinates->operator[](1));
                                    }
                                    break;
        case ShapeType::Text:       GetCordinateInput(ok, *shapeCordinates);
                                    if(ok)
                                    {
                                        renderArea->shapes[index]->Move
                                               (shapeCordinates->operator[](0),
                                                shapeCordinates->operator[](1));
                                    }
                                    break;
        default:                    break;
        }
    }

    delete shapeCordinates;
}

void MainWindow::GetCordinateInput(bool &ok, Vector<int>&shapeCords)
{
    int xCord;
    int yCord;
    xCord = QInputDialog::getInt(this, tr("Get X Cordinate"),
                                 tr("X:"), 0, 0, MAX_DIMENSION, 1, &ok);
    if(ok)
    {
        yCord = QInputDialog::getInt(this, tr("Get Y Cordinate"),
                                 tr("Y:"), 0, 0, MAX_DIMENSION, 1, &ok);
        if(ok)
        {
            shapeCords.push_back(xCord);
            shapeCords.push_back(yCord);
        }
    }
}

void MainWindow::on_actionNew_Shape_triggered()
{
    createShape->showMaximized();
    createShape        = new CreateShape;
}

void MainWindow::on_actionDelete_Shape_triggered()
{
    int index;
    bool ok;
    QStringList items;

    if(renderArea->shapes.size() == 0)
    {
        QMessageBox::warning(this, "EMPTY!!!", "The render area is empty");
    }
    else
    {
        for(index = 0; index < renderArea->shapes.size(); index++)
            items << renderArea->shapes[index]->GetName();

        QString item = QInputDialog::getItem(this, tr("Delete a Shape"),
                                             tr("Name:"), items, 0, false, &ok);
        if (ok && !item.isEmpty())
        {
            index = items.indexOf(item);
            renderArea->shapes.erase(renderArea->shapes.begin() + index);
        }
    }
}

void MainWindow::on_actionMove_Shape_triggered()
{
    if(renderArea->shapes.size() == 0)
    {
        QMessageBox::warning(this, "EMPTY!!!", "The render area is empty");
    }
    else
    {
        GetNewCordinates();
    }
}

void PrintShapeListing(const Vector<Shape*>& shapes)
{
    Vector<Shape*> temp = shapes;
    ofstream fout("ShapeListing.txt");

    for(int index = 0; index < temp.size(); index++)
    {
        ShapeType newShape = temp[index]->GetShape();
        switch(newShape)
        {
        case ShapeType::Line:      static_cast<Line*>(temp[index])->Print(fout);
                                   break;
        case ShapeType::Polyline:  static_cast<Polyline*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Polygon:   static_cast<Polygon*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Rectangle: static_cast<Rectangle*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Square:    static_cast<Rectangle*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Ellipse:   static_cast<Ellipse*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Circle:    static_cast<Ellipse*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::Text:      static_cast<Textbox*>
                                     (temp[index])->Print(fout);
                                   break;
        case ShapeType::NoShape: break;
        }
        fout << endl;

    }
    fout.close();
}


void PrintAreaShapeListing(const Vector<Shape*>& shapes)
{
    Vector<Shape*> temp = shapes;
//    Shape* tempSpot;
//    int j;
    ofstream fout;

//    for(int i = 1; i < temp.size(); i++)
//    {
//        tempSpot = temp[i];
//        j = i -1;
//        while(j >= 0 && temp[i]->Area() < tempSpot->Area())
//        {
//            temp[j + 1] = temp[j];
//            j = j -1;
//        }
//        temp[j + 1] = tempSpot;
//    }

//      sort(temp.begin(), temp.end());

    fout.open("AreaShapeListing.txt");
    for(int index = 0; index < temp.size(); index++)
    { // out shape type, id, and area
        if(temp[index]->Area() > 1) //checks if the shape has an area, if so outputs it
        {
            ShapeType type = temp[index]->GetShape();

            fout << temp[index]->Area() << endl;
            fout << temp[index]->GetId() << endl;
            switch(type)
            {
            case ShapeType::NoShape: break;
            case ShapeType::Line: fout << "Line";
                break;
            case ShapeType::Polyline: fout << "Polyline";
                break;
            case ShapeType::Polygon: fout << "Polygon";
                break;
            case ShapeType::Rectangle: fout << "Rectangle";
                break;
            case ShapeType::Square: fout << "Square";
                break;
            case ShapeType::Ellipse: fout << "Ellipse";
                break;
            case ShapeType::Circle: fout << "Circle";
                break;
            case ShapeType::Text: fout << "Text";
                break;
            }
            fout << endl << endl;
        } // end if
    } // end for
    fout.close();
}// end method

void PrintPerimeterShapeListing(const Vector<Shape*>& shapes)
{
    Vector<Shape*> temp = shapes;
    Shape* tempSpot;
    int j;
    ofstream fout;

    for(int i = 1; i < temp.size(); i++)
    {
        tempSpot = temp[i];
        j = i -1;
        while(j >= 0 && temp[i]->Perimeter() < tempSpot->Perimeter())
        {
            temp[j + 1] = temp[j];
            j = j -1;
        }
        temp[j + 1] = tempSpot;
    }

    fout.open("PerimeterShapeListing.txt");
    for(int index = 0; index < temp.size(); index++)
    { // out shape type, id, and area
        if(temp[index]->Perimeter() > 1) //checks if the shape has a perimeter, if so outputs it
        {
            ShapeType type = temp[index]->GetShape();

            fout << temp[index]->Perimeter() << endl;
            fout << temp[index]->GetId() << endl;
            switch(type)
            {
            case ShapeType::NoShape: break;
            case ShapeType::Line: fout << "Line";
                break;
            case ShapeType::Polyline: fout << "Polyline";
                break;
            case ShapeType::Polygon: fout << "Polygon";
                break;
            case ShapeType::Rectangle: fout << "Rectangle";
                break;
            case ShapeType::Square: fout << "Square";
                break;
            case ShapeType::Ellipse: fout << "Ellipse";
                break;
            case ShapeType::Circle: fout << "Circle";
                break;
            case ShapeType::Text: fout << "Text";
                break;
            }
            fout << endl << endl;
        } // end if
    } // end for
    fout.close();
} // end method
