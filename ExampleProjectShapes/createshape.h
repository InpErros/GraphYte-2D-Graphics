#ifndef CREATESHAPE_H
#define CREATESHAPE_H

#include <QDialog>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Textbox.h"

const int MAX_DIMENSION  = 1000;
const int MAX_POLY_SIDES = 12;

enum ShapeValues
{
    NO_SHAPE        = 0,
    LINE_VALUE      = 1,
    POLYLINE_VALUE  = 2,
    POLYGON_VALUE   = 3,
    RECTANGLE_VALUE = 4,
    SQUARE_VALUE    = 5,
    ELLIPSE_VALUE   = 6,
    CIRCLE_VALUE    = 7,
    TEXT_VALUE      = 8
};

namespace Ui {
class CreateShape;
}

class CreateShape : public QDialog
{
    Q_OBJECT

public:
    explicit CreateShape(QWidget *parent = nullptr);
    ~CreateShape();

    void InitializeUIValues();
    void SetFirstPgValues();
    void SetSecondPgValues();

private slots:
    void ShapeComboBox(const int& ARGUMENT);
    void GoToSecPage();
    void CompleteShape();


private:
    Ui::CreateShape *ui;

    QGroupBox *pickShape;
    QGroupBox *shapeInfo;

    QVBoxLayout *mainLayout;
    QFormLayout *pickShapeLayout;
    QFormLayout *shapeValuesLayout;

    QLabel *shapeLabel;
    QLabel *penWidthLabel;
    QLabel *penStyleLabel;
    QLabel *penCapLabel;
    QLabel *penJoinLabel;
    QLabel *penColorLabel;
    QLabel *brushColorLabel;
    QLabel *brushStyleLabel;
    QLabel *textStringLabel;
    QLabel *textColorLabel;
    QLabel *textAlignmentLabel;
    QLabel *textPointSizeLabel;
    QLabel *textFontFamilyLabel;
    QLabel *textFontStyleLabel;
    QLabel *textFontWeightLabel;

    QPushButton *page2;
    QPushButton *finished;

    QComboBox *shapeCBox;
    QComboBox *penStyleCBox;
    QComboBox *penCapCBox;
    QComboBox *penJoinCBox;
    QComboBox *penColorCBox;
    QComboBox *brushColorCBox;
    QComboBox *brushStyleCBox;
    QComboBox *textColorCBox;
    QComboBox *textAllignmentCBox;
    QComboBox *textFontFamilyCBox;
    QComboBox *textFontStyleCBox;
    QComboBox *textFontWeightCBox;

    QSpinBox *penWidthBox;
    QSpinBox *textPointBox;

    QLineEdit *textString;

    Vector<QLabel*> *dimensionsLabels;
    Vector<QSpinBox*> *dimensionsSpinBox;
};

#endif // CREATESHAPE_H
