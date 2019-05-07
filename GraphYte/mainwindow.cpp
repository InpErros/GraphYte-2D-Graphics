#include "mainwindow.h"
#include "ui_mainwindow.h"

//Constructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    login = new Login;
    login->show();

    renderArea         = new RenderArea;
    createShape        = new CreateShape;

    //Add the render area to the screen
    this->layout()->addWidget(renderArea);

    //connect the signal to create a new shape with the function
    connect(createShape, SIGNAL(shapeGenerated(newShapeInfo)),
            this, SLOT(GenerateShape(newShapeInfo)));

    //Move the render area
    renderArea->move(10, 50);

    //Disable everything until the admin logs in
    ui->menuCreate_A_New_Shape->setEnabled(false);
    ui->menuDelete_A_Shape->setEnabled(false);
    ui->menuMove_A_Shape->setEnabled(false);
}

//Deconstructor
MainWindow::~MainWindow()
{
    delete ui;
    delete renderArea;
    delete createShape;
}

//This will generate a new shape using the given information
void MainWindow::GenerateShape(const newShapeInfo& NEW_SHAPE)
{
    Line        *newLine;       //A pointer for a new line
    Polyline    *newPloyline;   //A pointer for a new polyline
    Polygon     *newPolygon;    //A pointer for a new polygon
    Rectangle   *newRectangle;  //A pointer for a new rectangle
    Rectangle   *newSquare;     //A pointer for a new square
    Ellipse     *newEllipse;    //A pointer for a new ellipse
    Ellipse     *newCircle;     //A pointer for a new circle
    Textbox     *newTextbox;    //A pointer for a new textbox

    ShapeType shapeType;        //The enum class for the shape type

    int index;                  //The index in the array

    shapeType = static_cast<ShapeType>(NEW_SHAPE.shapeId);

    //Create the shape based on the shape type and put it in the vector
    switch(shapeType)
    {
    case ShapeType::Line:newLine = new Line(this , static_cast<int>(shapeType));
                         newLine->SetCordinates
                                (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                        NEW_SHAPE.dimensions.operator[](1)),
                                 QPoint(NEW_SHAPE.dimensions.operator[](2),
                                        NEW_SHAPE.dimensions.operator[](3)));
                         newLine->SetPen(NEW_SHAPE.shapePen);
                         newLine->SetName(NEW_SHAPE.name);
                         renderArea->shapes.push_back(newLine);
                         break;

    case ShapeType::Polyline:newPloyline = new Polyline(this ,
                                                   static_cast<int>(shapeType));
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

    case ShapeType::Polygon:newPolygon = new Polygon(this ,
                                                   static_cast<int>(shapeType));
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

    case ShapeType::Rectangle: newRectangle = new Rectangle(this ,
                                                   static_cast<int>(shapeType));
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

    case ShapeType::Square:    newSquare = new Rectangle(this ,
                                                   static_cast<int>(shapeType));
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

    case ShapeType::Ellipse:   newEllipse = new Ellipse(this ,
                                                   static_cast<int>(shapeType));
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
    case ShapeType::Circle:    newCircle = new Ellipse(this ,
                                                   static_cast<int>(shapeType));
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
    case ShapeType::Text:      newTextbox = new Textbox(this,
                                                   static_cast<int>(shapeType));
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

    //Update the canvas to add the shape to the canvas
    renderArea->UpdateCanvas();
}

//Get the new cordinates for the shape
void MainWindow::GetNewCordinates()
{
    int index;                      //The index in the array
    int i;                          //Counter

    Vector<int> *shapeCordinates;   //The vector of shapes

    bool ok;                        //The condition to move on

    QStringList items;              //The list of items as strings

    ShapeType shapeType;            //The enum to match the type of shape

    shapeCordinates = new Vector<int>;
    ok              = true;

    for(index = 0; index < renderArea->shapes.size(); index++)
        items << renderArea->shapes[index]->GetName();

    QString item = QInputDialog::getItem(this, tr("Move a Shape"),
                                         tr("Name:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
    {
        index = items.indexOf(item);

        shapeType = static_cast<ShapeType>(index + 1);

        //Based on the shape, get the amount of cordinates and set them
        switch (shapeType)
        {
        case ShapeType::Line:   GetCordinateInput(ok, *shapeCordinates);
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

        case ShapeType::Polyline:for(i = 0; i < (MAX_POLY_SIDES/2); i+=2)
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

        case ShapeType::Rectangle:
        case ShapeType::Square:
        case ShapeType::Ellipse:
        case ShapeType::Circle:
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

//Get the new cordinates as input from the user
void MainWindow::GetCordinateInput(bool &ok, Vector<int>&shapeCords)
{
    int xCord;  //The new x cordinate
    int yCord;  //The new y cordinate

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

//Create the new shape window
void MainWindow::on_actionNew_Shape_triggered()
{
    createShape->showMaximized();
    createShape        = new CreateShape;
}

//Delete a shape from the canvas
void MainWindow::on_actionDelete_Shape_triggered()
{
    int         index;  //The index in the vector

    bool        ok;     //The condition to move on

    QStringList items;  //The list of items as strings

    if(renderArea->shapes.size() == 0)
        QMessageBox::warning(this, "EMPTY!!!", "The render area is empty");
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

//Move the shape
void MainWindow::on_actionMove_Shape_triggered()
{
    if(renderArea->shapes.size() == 0)
        QMessageBox::warning(this, "EMPTY!!!", "The render area is empty");
    else
        GetNewCordinates();
}

//Login for the admin
void MainWindow::on_actionLogin_triggered()
{
    bool ok;            //The condition to move on

    QString username;   //The username the user inputs
    QString password;   //The password the user inputs

    username = QInputDialog::getText(this, tr("Login"),
                                         tr("User name:"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !username.isEmpty())
    {
        password = QInputDialog::getText(this, tr("Login"),
                                             tr("Password:"), QLineEdit::Normal,
                                             "", &ok);
        if (ok && !username.isEmpty())
        {
            if(username == USERNAME && password == PASSWORD)
            {
                QMessageBox::information(this, "Welcome", "Welcome back Admin");

                //Enable everything for the admin
                ui->menuCreate_A_New_Shape->setEnabled(true);
                ui->menuDelete_A_Shape->setEnabled(true);
                ui->menuMove_A_Shape->setEnabled(true);
                ui->menuLogin->setEnabled(false);
            }
            else
            {
                QMessageBox::warning(this, "Incorrect",
                                     "incorrect username or password");
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Incorrect",
                             "incorrect username or password");
    }
}

void MainWindow::on_actionContact_Us_triggered()
{
    contactInfo = new ContactInfo;
    contactInfo->show();
}

void MainWindow::on_actionComments_triggered()
{
    comment = new Comment;
    comment->show();
}

void MainWindow::on_actionAbout_Us_triggered()
{
    aboutUs = new AboutUs;
    aboutUs->show();
}
