#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    renderArea         = new RenderArea;
    createShape        = new CreateShape;

    // show login (lock mainwindow)
    login = new Login();
    login->show();

    this->layout()->addWidget(renderArea);

    connect(createShape, SIGNAL(shapeGenerated(newShapeInfo)),
            this, SLOT(GenerateShape(newShapeInfo)));

    renderArea->move(10, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderArea;
    delete createShape;
    delete login;
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

    int index;

    switch(NEW_SHAPE.shapeId)
    {
    case LINE:      newLine = new Line(this, LINE);
                    newLine->SetCordinates
                            (QPoint(NEW_SHAPE.dimensions.operator[](0),
                                    NEW_SHAPE.dimensions.operator[](1)),
                             QPoint(NEW_SHAPE.dimensions.operator[](2),
                                    NEW_SHAPE.dimensions.operator[](3)));
                    newLine->SetPen(NEW_SHAPE.shapePen);
                    newLine->SetName(NEW_SHAPE.name);
                    renderArea->shapes.push_back(newLine);
                    break;

    case POLYLINE:  newPloyline = new Polyline(this, POLYLINE);
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

    case POLYGON:   newPolygon = new Polygon(this, POLYGON);
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

    case RECTANGLE: newRectangle = new Rectangle(this, RECTANGLE);
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

    case SQUARE:    newSquare = new Rectangle(this, SQUARE);
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

    case ELLIPSE:   newEllipse = new Ellipse(this, ELLIPSE);
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
    case CIRCLE:    newCircle = new Ellipse(this, CIRCLE);
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
    case TEXT:      newTextbox = new Textbox(this, TEXT);
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
    //Move a shape here
    //Move shoudl not redraw the shape within the shape function but change the
    //X and Y cordinates for the shape. Then call update to change the shape.
    //I will probably have to remove the shape after moving it
}

void MainWindow::on_actionContact_Us_triggered()
{
    contactInfo = new ContactInfo;
    contactInfo->show();
}

void MainWindow::on_actionSupport_triggered()
{
    QDesktopServices::openUrl(QUrl("https://discord.gg/k9Dxpu2"));
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
