#include "mainwindow.h"
#include "ui_mainwindow.h"

const int IdRole = Qt::UserRole;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    renderArea         = new RenderArea;
    shapeComboBox      = new QComboBox;
    shapeLabel         = new QLabel(tr("Shape"));
    penWidthLabel      = new QLabel(tr("Pen Width"));
    penStyleLabel      = new QLabel(tr("Pen Style"));
    penCapLabel        = new QLabel(tr("Pen Cap"));
    penJoinLabel       = new QLabel(tr("Pen Join"));
    brushStyleLabel    = new QLabel(tr("Brush Style"));
    penWidthSpinBox    = new QSpinBox;
    penStyleComboBox   = new QComboBox;
    penCapComboBox     = new QComboBox;
    penJoinComboBox    = new QComboBox;
    brushStyleComboBox = new QComboBox;

    shapeComboBox->addItem(tr("No Shape"));
    shapeComboBox->addItem(tr("Line"));
    shapeComboBox->addItem(tr("Polyline"));
    shapeComboBox->addItem(tr("Polygon"));
    shapeComboBox->addItem(tr("Rectangle"));
    shapeComboBox->addItem(tr("Square"));
    shapeComboBox->addItem(tr("Ellipse"));
    shapeComboBox->addItem(tr("Circle"));
    shapeComboBox->addItem(tr("Text"));

    penStyleComboBox->addItem(tr("Solid"), static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("Dash"), static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("Dot"), static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("Dash Dot"), static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("Dash Dot Dot"),
                              static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoPen));


    penCapComboBox->addItem(tr("Flat"), Qt::FlatCap);
    penCapComboBox->addItem(tr("Square"), Qt::SquareCap);
    penCapComboBox->addItem(tr("Round"), Qt::RoundCap);

    penJoinComboBox->addItem(tr("Miter"), Qt::MiterJoin);
    penJoinComboBox->addItem(tr("Bevel"), Qt::BevelJoin);
    penJoinComboBox->addItem(tr("Round"), Qt::RoundJoin);

    brushStyleComboBox->addItem(tr("Solid"),static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Horizontal"),
                                static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("Vertical"),
                                static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("None"), static_cast<int>(Qt::NoBrush));

    penWidthSpinBox->setRange(0, 20);

    penWidthLabel->setBuddy(penWidthSpinBox);
    penStyleLabel->setBuddy(penStyleComboBox);
    penCapLabel->setBuddy(penCapComboBox);
    penJoinLabel->setBuddy(penJoinComboBox);
    brushStyleLabel->setBuddy(brushStyleComboBox);

    this->layout()->addWidget(renderArea);
    this->layout()->addWidget(shapeLabel);
    this->layout()->addWidget(shapeComboBox);
    this->layout()->addWidget(penWidthLabel);
    this->layout()->addWidget(penWidthSpinBox);
    this->layout()->addWidget(penStyleLabel);
    this->layout()->addWidget(penStyleComboBox);
    this->layout()->addWidget(penCapLabel);
    this->layout()->addWidget(penCapComboBox);
    this->layout()->addWidget(penJoinLabel);
    this->layout()->addWidget(penJoinComboBox);
    this->layout()->addWidget(brushStyleLabel);
    this->layout()->addWidget(brushStyleComboBox);

    renderArea          ->setGeometry(5,25,2300, 600);
    shapeLabel          ->setGeometry(10, 800, 150, 50);
    shapeComboBox       ->setGeometry(90, 800, 150, 50);
    penWidthLabel       ->setGeometry(10, 850, 150, 50);
    penWidthSpinBox     ->setGeometry(90, 850, 150, 50);
    penStyleLabel       ->setGeometry(10, 900, 150, 50);
    penStyleComboBox    ->setGeometry(90, 900, 150, 50);
    penCapLabel         ->setGeometry(10, 950, 150, 50);
    penCapComboBox      ->setGeometry(90, 950, 150, 50);
    penJoinLabel        ->setGeometry(10, 1000, 150, 50);
    penJoinComboBox     ->setGeometry(90, 1000, 150, 50);
    brushStyleLabel     ->setGeometry(10, 1100, 150, 50);
    brushStyleComboBox  ->setGeometry(90, 1100, 150, 50);

    connect(shapeComboBox, SIGNAL(activated(int)),
            this, SLOT(shapeChanged()));
    connect(penWidthSpinBox, SIGNAL(valueChanged(int)),
            this, SLOT(penChanged()));
    connect(penStyleComboBox, SIGNAL(activated(int)),
            this, SLOT(penChanged()));

    connect(penCapComboBox, SIGNAL(activated(int)),
            this, SLOT(penChanged()));

    connect(penJoinComboBox, SIGNAL(activated(int)),
            this, SLOT(penChanged()));
    connect(brushStyleComboBox, SIGNAL(activated(int)),
            this, SLOT(brushChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete renderArea;
    delete shapeLabel;
    delete penWidthLabel;
    delete penStyleLabel;
    delete penCapLabel;
    delete penJoinLabel;
    delete brushStyleLabel;
    delete shapeComboBox;
    delete penWidthSpinBox;
    delete penStyleComboBox;
    delete penCapComboBox;
    delete penJoinComboBox;
    delete brushStyleComboBox;

}

void MainWindow::shapeChanged()
{
    if(shapeComboBox->currentIndex() != 0)
        renderArea->CreateShape(shapeComboBox->currentIndex());
}

void MainWindow::penChanged()
{
    int width = penWidthSpinBox->value();

    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData
                                      (penStyleComboBox->currentIndex(),
                                       IdRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboBox->itemData
                                          (penCapComboBox->currentIndex(),
                                           IdRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData
                                             (penJoinComboBox->currentIndex(),
                                              IdRole).toInt());
    renderArea->setPen(QPen(Qt::blue, width, style, cap, join));
}

void MainWindow::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData
                                          (brushStyleComboBox->currentIndex(),
                                           IdRole).toInt());
    renderArea->setBrush(QBrush(Qt::green, style));
}
