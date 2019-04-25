#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    renderArea    = new RenderArea;
    shapeComboBox = new QComboBox;

    shapeComboBox->addItem(tr("No Shape"));
    shapeComboBox->addItem(tr("Line"));
    shapeComboBox->addItem(tr("Polyline"));
    shapeComboBox->addItem(tr("Polygon"));
    shapeComboBox->addItem(tr("Rectangle"));
    shapeComboBox->addItem(tr("Square"));
    shapeComboBox->addItem(tr("Ellipse"));
    shapeComboBox->addItem(tr("Circle"));
    shapeComboBox->addItem(tr("Text"));

    this->layout()->addWidget(renderArea);
    this->layout()->addWidget(shapeComboBox);

    renderArea   ->setGeometry(10,50,2000, 600);
    shapeComboBox->setGeometry(10, 800, 100, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderArea;
    delete shapeComboBox;
}

