#include "createshape.h"
#include "ui_CreateShape.h"

CreateShape::CreateShape(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateShape)
{
    ui->setupUi(this);

    InitializeUIValues();

    SetFirstPgValues();

    connect(shapeCBox, SIGNAL(activated(int)), this, SLOT(ShapeComboBox(int)));
    connect(page2, SIGNAL(clicked()), this, SLOT(GoToSecPage()));
    connect(finished, SIGNAL(clicked()), this, SLOT(CompleteShape()));

    //Block input from other windows exccept this main one
    setWindowModality(Qt::ApplicationModal);
}

CreateShape::~CreateShape()
{
    delete ui;
    delete pickShape;
    delete shapeInfo;
    delete pickShapeLayout;
    delete shapeValuesLayout;
    delete mainLayout;
    delete shapeLabel;
    delete penWidthLabel;
    delete penStyleLabel;
    delete penCapLabel;
    delete penJoinLabel;
    delete penColorLabel;
    delete brushColorLabel;
    delete brushStyleLabel;
    delete textStringLabel;
    delete textColorLabel;
    delete textAlignmentLabel;
    delete textPointSizeLabel;
    delete textFontFamilyLabel;
    delete textFontStyleLabel;
    delete textFontWeightLabel;
    delete page2;
    delete finished;
    delete shapeCBox;
    delete penStyleCBox;
    delete penCapCBox;
    delete penJoinCBox;
    delete penColorCBox;
    delete brushColorCBox;
    delete brushStyleCBox;
    delete textColorCBox;
    delete textAllignmentCBox;
    delete textFontFamilyCBox;
    delete textFontStyleCBox;
    delete textFontWeightCBox;
    delete penWidthBox;
    delete textPointBox;
    delete textString;

    for(auto it: *dimensionsLabels)
        delete it;

    for(auto nextIt: *dimensionsSpinBox)
        delete nextIt;

    delete dimensionsLabels;
    delete dimensionsSpinBox;
}

void CreateShape::InitializeUIValues()
{
    pickShape           = new QGroupBox;
    shapeInfo           = new QGroupBox;

    mainLayout          = new QVBoxLayout;
    pickShapeLayout     = new QFormLayout;
    shapeValuesLayout   = new QFormLayout;

    shapeLabel          = new QLabel;
    penWidthLabel       = new QLabel;
    penStyleLabel       = new QLabel;
    penJoinLabel        = new QLabel;
    penCapLabel         = new QLabel;
    penColorLabel       = new QLabel;
    brushColorLabel     = new QLabel;
    brushStyleLabel     = new QLabel;
    textStringLabel     = new QLabel;
    textColorLabel      = new QLabel;
    textAlignmentLabel  = new QLabel;
    textPointSizeLabel  = new QLabel;
    textFontFamilyLabel = new QLabel;
    textFontStyleLabel  = new QLabel;
    textFontWeightLabel = new QLabel;

    page2               = new QPushButton;
    finished            = new QPushButton;

    shapeCBox           = new QComboBox;
    penStyleCBox        = new QComboBox;
    penCapCBox          = new QComboBox;
    penJoinCBox         = new QComboBox;
    penColorCBox        = new QComboBox;
    brushColorCBox      = new QComboBox;
    brushStyleCBox      = new QComboBox;
    textColorCBox       = new QComboBox;
    textAllignmentCBox  = new QComboBox;
    textFontFamilyCBox  = new QComboBox;
    textFontStyleCBox   = new QComboBox;
    textFontWeightCBox  = new QComboBox;

    penWidthBox         = new QSpinBox;
    textPointBox        = new QSpinBox;

    textString          = new QLineEdit;

    dimensionsLabels    = new Vector<QLabel*>;
    dimensionsSpinBox   = new Vector<QSpinBox*>;

    mainLayout->addWidget(pickShape);
    mainLayout->addWidget(shapeInfo);

    shapeInfo ->setEnabled(false);

    setLayout(mainLayout);
}

void CreateShape::SetFirstPgValues()
{
    shapeLabel          ->setText("Shape:");
    penColorLabel       ->setText("Pen Color:");
    penWidthLabel       ->setText("Pen Width:");
    penStyleLabel       ->setText("Pen Style:");
    penCapLabel         ->setText("Pen Cap Style:");
    penJoinLabel        ->setText("Pen Join Style:");
    brushColorLabel     ->setText("Brush Color:");
    brushStyleLabel     ->setText("Brush Style:");
    textStringLabel     ->setText("Text Message:");
    textColorLabel      ->setText("Text Color:");
    textAlignmentLabel  ->setText("Text Allignment:");
    textPointSizeLabel  ->setText("Text Point Size:");
    textFontFamilyLabel ->setText("Text Font Family:");
    textFontStyleLabel  ->setText("Text Font Style:");
    textFontWeightLabel ->setText("Text Font Weight:");

    shapeCBox   ->addItem("No Shape", NO_SHAPE);
    shapeCBox   ->addItem("Line", LINE_VALUE);
    shapeCBox   ->addItem("Polyline", POLYLINE_VALUE);
    shapeCBox   ->addItem("Polygon", POLYGON_VALUE);
    shapeCBox   ->addItem("Rectangle", RECTANGLE_VALUE);
    shapeCBox   ->addItem("Square", SQUARE_VALUE);
    shapeCBox   ->addItem("Ellipse", ELLIPSE_VALUE);
    shapeCBox   ->addItem("Circle", CIRCLE_VALUE);
    shapeCBox   ->addItem("Text", TEXT_VALUE);

    penColorCBox->addItem("No Color",           static_cast<int>(Qt::transparent));
    penColorCBox->addItem("White",              static_cast<int>(Qt::white));
    penColorCBox->addItem("Black",              static_cast<int>(Qt::black));
    penColorCBox->addItem("Red",                static_cast<int>(Qt::red));
    penColorCBox->addItem("Green",              static_cast<int>(Qt::green));
    penColorCBox->addItem("Blue",               static_cast<int>(Qt::blue));
    penColorCBox->addItem("Cyan",               static_cast<int>(Qt::cyan));
    penColorCBox->addItem("Magenta",            static_cast<int>(Qt::magenta));
    penColorCBox->addItem("Yellow",             static_cast<int>(Qt::yellow));
    penColorCBox->addItem("Gray",               static_cast<int>(Qt::gray));

    penStyleCBox->addItem("No Pen",             static_cast<int>(Qt::NoPen));
    penStyleCBox->addItem("Solid Line",         static_cast<int>(Qt::SolidLine));
    penStyleCBox->addItem("Dash Line",          static_cast<int>(Qt::DashLine));
    penStyleCBox->addItem("Dot Line",           static_cast<int>(Qt::DotLine));
    penStyleCBox->addItem("Dash Dot Line",      static_cast<int>
                                                (Qt::DashDotLine));
    penStyleCBox->addItem("Dash Dot Dot Line",  static_cast<int>
                                                (Qt::DashDotDotLine));
    penCapCBox  ->addItem("Flat",               Qt::FlatCap);
    penCapCBox  ->addItem("Square",             Qt::SquareCap);
    penCapCBox  ->addItem("Round",              Qt::RoundCap);

    penJoinCBox->addItem("Miter",               Qt::MiterJoin);
    penJoinCBox->addItem("Bevel",               Qt::BevelJoin);
    penJoinCBox->addItem("Round",               Qt::RoundJoin);

    brushColorCBox->addItem("No Color",         static_cast<int>(Qt::transparent));
    brushColorCBox->addItem("White",            static_cast<int>(Qt::white));
    brushColorCBox->addItem("Black",            static_cast<int>(Qt::black));
    brushColorCBox->addItem("Red",              static_cast<int>(Qt::red));
    brushColorCBox->addItem("Green",            static_cast<int>(Qt::green));
    brushColorCBox->addItem("Blue",             static_cast<int>(Qt::blue));
    brushColorCBox->addItem("Cyan",             static_cast<int>(Qt::cyan));
    brushColorCBox->addItem("Magenta",          static_cast<int>(Qt::magenta));
    brushColorCBox->addItem("Yellow",           static_cast<int>(Qt::yellow));
    brushColorCBox->addItem("Gray",             static_cast<int>(Qt::gray));

    brushStyleCBox->addItem("None",             static_cast<int>(Qt::NoBrush));
    brushStyleCBox->addItem("Solid",            static_cast<int>
                                                (Qt::SolidPattern));
    brushStyleCBox->addItem("Horizontal",       static_cast<int>(Qt::HorPattern));
    brushStyleCBox->addItem("Vertical",         static_cast<int>(Qt::VerPattern));

    textColorCBox ->addItem("No Color",         static_cast<int>(Qt::transparent));
    textColorCBox ->addItem("White",            static_cast<int>(Qt::white));
    textColorCBox ->addItem("Black",            static_cast<int>(Qt::black));
    textColorCBox ->addItem("Red",              static_cast<int>(Qt::red));
    textColorCBox ->addItem("Green",            static_cast<int>(Qt::green));
    textColorCBox ->addItem("Blue",             static_cast<int>(Qt::blue));
    textColorCBox ->addItem("Cyan",             static_cast<int>(Qt::cyan));
    textColorCBox ->addItem("Magenta",          static_cast<int>(Qt::magenta));
    textColorCBox ->addItem("Yellow",           static_cast<int>(Qt::yellow));
    textColorCBox ->addItem("Gray",             static_cast<int>(Qt::gray));

    textAllignmentCBox->addItem("Allign Left",  static_cast<int>(Qt::AlignLeft));
    textAllignmentCBox->addItem("Allign Top",   static_cast<int>(Qt::AlignTop));
    textAllignmentCBox->addItem("Allign Bottom",static_cast<int>(Qt::AlignBottom));
    textAllignmentCBox->addItem("Allign Center",static_cast<int>(Qt::AlignCenter));

    textFontFamilyCBox->addItem("Comic Sans MS");
    textFontFamilyCBox->addItem("Courier");
    textFontFamilyCBox->addItem("Helvetica");
    textFontFamilyCBox->addItem("Times");

    textFontStyleCBox->addItem("Normal Style",
                               static_cast<int>(QFont::StyleNormal));
    textFontStyleCBox->addItem("Italic Style",
                               static_cast<int>(QFont::StyleItalic));
    textFontStyleCBox->addItem("Oblique Style",
                               static_cast<int>(QFont::StyleOblique));

    textFontWeightCBox->addItem("Thin",  static_cast<int>(QFont::Thin));
    textFontWeightCBox->addItem("Light", static_cast<int>(QFont::Light));
    textFontWeightCBox->addItem("Normal",static_cast<int>(QFont::Normal));
    textFontWeightCBox->addItem("Bold", static_cast<int> (QFont::Bold));

    page2->setText("CONTINUE");

    penWidthBox ->setRange(0, 20);
    textPointBox->setRange(0, 50);

    //Disable all features until a shape is chosen
    penColorCBox        ->setEnabled(false);
    penStyleCBox        ->setEnabled(false);
    penCapCBox          ->setEnabled(false);
    penJoinCBox         ->setEnabled(false);
    brushColorCBox      ->setEnabled(false);
    brushStyleCBox      ->setEnabled(false);
    textColorCBox       ->setEnabled(false);
    textAllignmentCBox  ->setEnabled(false);
    textFontFamilyCBox  ->setEnabled(false);
    textFontStyleCBox   ->setEnabled(false);
    textFontWeightCBox  ->setEnabled(false);
    penWidthBox         ->setEnabled(false);
    textPointBox        ->setEnabled(false);
    textString          ->setEnabled(false);

    pickShapeLayout->addRow(shapeLabel,          shapeCBox);
    pickShapeLayout->addRow(penColorLabel,       penColorCBox);
    pickShapeLayout->addRow(penWidthLabel,       penWidthBox);
    pickShapeLayout->addRow(penStyleLabel,       penStyleCBox);
    pickShapeLayout->addRow(penCapLabel,         penCapCBox);
    pickShapeLayout->addRow(penJoinLabel,        penJoinCBox);
    pickShapeLayout->addRow(brushColorLabel,     brushColorCBox);
    pickShapeLayout->addRow(brushStyleLabel,     brushStyleCBox);
    pickShapeLayout->addRow(textStringLabel,     textString);
    pickShapeLayout->addRow(textColorLabel,      textColorCBox);
    pickShapeLayout->addRow(textAlignmentLabel,  textAllignmentCBox);
    pickShapeLayout->addRow(textPointSizeLabel,  textPointBox);
    pickShapeLayout->addRow(textFontFamilyLabel, textFontFamilyCBox);
    pickShapeLayout->addRow(textFontStyleLabel,  textFontStyleCBox);
    pickShapeLayout->addRow(textFontWeightLabel, textFontWeightCBox);

    pickShapeLayout->addWidget(page2);

    pickShapeLayout->setFormAlignment(Qt::AlignCenter);

    pickShapeLayout->setVerticalSpacing(25);

    pickShape->setLayout(pickShapeLayout);
}

void CreateShape::SetSecondPgValues()
{
    QLabel *newLabel;

    QSpinBox *newSpinBox;

    int index;
    int cordCounter = 1;
    int shapeBoxIndex = shapeCBox->currentIndex();

    shapeValuesLayout->setSpacing(0);

    switch(shapeBoxIndex)
    {
    case NO_SHAPE:          break;

    case POLYLINE_VALUE:
    case POLYGON_VALUE:     for(index = 0; index < MAX_POLY_SIDES; index++)
                            {
                                newLabel = new QLabel;
                                if(index % 2 == 0)
                                {
                                    newLabel->setText
                                           ("X" + QString::number(cordCounter)
                                                + ":");
                                }
                                else
                                {
                                    newLabel->setText
                                           ("Y" + QString::number(cordCounter)
                                                + ":");
                                    cordCounter++;
                                }
                                dimensionsLabels->push_back(newLabel);
                            }
                            break;
    case LINE_VALUE:
    case RECTANGLE_VALUE:
    case ELLIPSE_VALUE:
    case TEXT_VALUE:        for(index = 0; index < 4; index++)
                            {
                                newLabel = new QLabel;
                                switch(index)
                                {
                                case 0:     newLabel->setText("X1:");
                                            break;
                                case 1:     newLabel->setText("Y1:");
                                            break;
                                case 2:     if(shapeBoxIndex == TEXT_VALUE)
                                                newLabel->setText("X2:");
                                            else if(shapeBoxIndex ==
                                                    ELLIPSE_VALUE)
                                            {
                                                newLabel->setText
                                                        ("Semi Major Axis:");
                                            }
                                            else
                                                newLabel->setText("Length:");
                                            break;
                                case 3:     if(shapeBoxIndex == TEXT_VALUE)
                                                newLabel->setText("Y2:");
                                            else if(shapeBoxIndex ==
                                                    ELLIPSE_VALUE)
                                            {
                                                newLabel->setText
                                                        ("Semi Minor Axis:");
                                            }
                                            else
                                                newLabel->setText("Width:");
                                            break;
                                default:    break;
                                }
                                dimensionsLabels->push_back(newLabel);
                            }
                            break;
    case SQUARE_VALUE:
    case CIRCLE_VALUE:      for(index = 0; index < 3; index++)
                            {
                                newLabel = new QLabel;
                                switch(index)
                                {
                                case 0:     newLabel->setText("X1:");
                                            break;
                                case 1:     newLabel->setText("Y1:");
                                            break;
                                case 2:     if(shapeBoxIndex == SQUARE_VALUE)
                                                newLabel->setText("Length:");
                                            else
                                                newLabel->setText("Radius:");
                                            break;
                                default:    break;
                                }
                                dimensionsLabels->push_back(newLabel);
                            }
                            break;

    default:                break;
    }

    for(index = 0; index < dimensionsLabels->size(); index++)
    {
        newSpinBox = new QSpinBox;
        newSpinBox->setRange(0, MAX_DIMENSION);
        dimensionsSpinBox->push_back(newSpinBox);
        shapeValuesLayout->addRow(dimensionsLabels->operator[](index),
                                  newSpinBox);
    }

    finished->setText("Finished!");

    shapeValuesLayout->addWidget(finished);

    shapeValuesLayout->setFormAlignment(Qt::AlignCenter);

    shapeValuesLayout->setVerticalSpacing(10);

    shapeInfo->setLayout(shapeValuesLayout);
}

void CreateShape::ShapeComboBox(const int& ARGUMENT)
{
    switch(ARGUMENT)
    {
    case NO_SHAPE:          //Disable all features until a shape is chosen
                            penColorCBox        ->setEnabled(false);
                            penStyleCBox        ->setEnabled(false);
                            penCapCBox          ->setEnabled(false);
                            penJoinCBox         ->setEnabled(false);
                            brushColorCBox      ->setEnabled(false);
                            brushStyleCBox      ->setEnabled(false);
                            textColorCBox       ->setEnabled(false);
                            textAllignmentCBox  ->setEnabled(false);
                            textFontFamilyCBox  ->setEnabled(false);
                            textFontStyleCBox   ->setEnabled(false);
                            textFontWeightCBox  ->setEnabled(false);
                            penWidthBox         ->setEnabled(false);
                            textPointBox        ->setEnabled(false);
                            textString          ->setEnabled(false);
                            break;

    case LINE_VALUE:
    case POLYLINE_VALUE:    penColorCBox        ->setEnabled(true);
                            penStyleCBox        ->setEnabled(true);
                            penCapCBox          ->setEnabled(true);
                            penJoinCBox         ->setEnabled(true);
                            brushColorCBox      ->setEnabled(false);
                            brushStyleCBox      ->setEnabled(false);
                            textColorCBox       ->setEnabled(false);
                            textAllignmentCBox  ->setEnabled(false);
                            textFontFamilyCBox  ->setEnabled(false);
                            textFontStyleCBox   ->setEnabled(false);
                            textFontWeightCBox  ->setEnabled(false);
                            penWidthBox         ->setEnabled(true);
                            textPointBox        ->setEnabled(false);
                            textString          ->setEnabled(false);
                            break;
    case POLYGON_VALUE:
    case RECTANGLE_VALUE:
    case SQUARE_VALUE:
    case ELLIPSE_VALUE:
    case CIRCLE_VALUE:      penColorCBox        ->setEnabled(true);
                            penStyleCBox        ->setEnabled(true);
                            penCapCBox          ->setEnabled(true);
                            penJoinCBox         ->setEnabled(true);
                            brushColorCBox      ->setEnabled(true);
                            brushStyleCBox      ->setEnabled(true);
                            textColorCBox       ->setEnabled(false);
                            textAllignmentCBox  ->setEnabled(false);
                            textFontFamilyCBox  ->setEnabled(false);
                            textFontStyleCBox   ->setEnabled(false);
                            textFontWeightCBox  ->setEnabled(false);
                            penWidthBox         ->setEnabled(true);
                            textPointBox        ->setEnabled(false);
                            textString          ->setEnabled(false);
                            break;
    case TEXT_VALUE:        penColorCBox        ->setEnabled(false);
                            penStyleCBox        ->setEnabled(false);
                            penCapCBox          ->setEnabled(false);
                            penJoinCBox         ->setEnabled(false);
                            brushColorCBox      ->setEnabled(false);
                            brushStyleCBox      ->setEnabled(false);
                            textColorCBox       ->setEnabled(true);
                            textAllignmentCBox  ->setEnabled(true);
                            textFontFamilyCBox  ->setEnabled(true);
                            textFontStyleCBox   ->setEnabled(true);
                            textFontWeightCBox  ->setEnabled(true);
                            penWidthBox         ->setEnabled(false);
                            textPointBox        ->setEnabled(true);
                            textString          ->setEnabled(true);
                    break;
    default:        break;
    }
}

void CreateShape::GoToSecPage()
{
    bool completed = false;

    switch(shapeCBox->currentIndex())
    {
    case NO_SHAPE:          break;

    case LINE_VALUE:
    case POLYLINE_VALUE:    if(penColorCBox->currentIndex() != 0 &&
                               penStyleCBox->currentIndex() != 0 &&
                               penWidthBox ->value()        != 0)
                                completed = true;
                            break;
    case POLYGON_VALUE:
    case RECTANGLE_VALUE:
    case SQUARE_VALUE:
    case ELLIPSE_VALUE:
    case CIRCLE_VALUE:      if(penColorCBox->currentIndex()   != 0 &&
                               penStyleCBox->currentIndex()   != 0 &&
                               penWidthBox  ->value()         != 0 &&
                               brushColorCBox->currentIndex() != 0  &&
                               brushStyleCBox->currentIndex() != 0)
                                    completed = true;
                            break;
    case TEXT_VALUE:        if(textColorCBox->currentIndex()   != 0 &&
                               textPointBox ->value()          != 0 &&
                               textString   ->text().isEmpty() == false)
                                    completed = true;
                            break;
    default:                break;
    }

    if(completed == false)
        QMessageBox::warning(this, "Warning", "invalid fields");
    else
    {
        shapeCBox           ->setEnabled(false);
        penColorCBox        ->setEnabled(false);
        penStyleCBox        ->setEnabled(false);
        penCapCBox          ->setEnabled(false);
        penJoinCBox         ->setEnabled(false);
        brushColorCBox      ->setEnabled(false);
        brushStyleCBox      ->setEnabled(false);
        textColorCBox       ->setEnabled(false);
        textAllignmentCBox  ->setEnabled(false);
        textFontFamilyCBox  ->setEnabled(false);
        textFontStyleCBox   ->setEnabled(false);
        textFontWeightCBox  ->setEnabled(false);
        penWidthBox         ->setEnabled(false);
        textPointBox        ->setEnabled(false);
        textString          ->setEnabled(false);
        shapeInfo           ->setEnabled(true);
        page2               ->setEnabled(false);
        SetSecondPgValues();
    }
}

void CreateShape::CompleteShape()
{
    bool completed = false;
    int  index = 2;
    while(index < dimensionsLabels->size() && !completed)
    {
        if( dimensionsSpinBox->operator[](index)->value() != 0)
        {
            completed = true;
        }
        else
            index++;
    }

    if(completed == false)
        QMessageBox::warning(this, "Warning", "invalid fields");
    else
        QMessageBox::information(this, "Shape Created!", "The Shape has "
                                                        "been fully generated");
}
