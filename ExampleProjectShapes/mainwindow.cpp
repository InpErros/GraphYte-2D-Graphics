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
    renderArea->AddNewShape(NEW_SHAPE);
}

void MainWindow::on_actionNew_Shape_triggered()
{
    createShape->showMaximized();
}
