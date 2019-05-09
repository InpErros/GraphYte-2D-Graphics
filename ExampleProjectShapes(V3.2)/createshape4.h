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
#include <QDebug>

#include "Ellipse.h"
#include "Line.h"
#include "Polygon.h"
#include "Polyline.h"
#include "Rectangle.h"
#include "Textbox.h"

const int MAX_DIMENSION  = 1000;
const int MAX_POLY_SIDES = 10;
const int IdRole = Qt::UserRole;

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

    newShapeInfo GenerateShape();

    Qt::GlobalColor StrToColor(QString) const;
    Qt::PenStyle StrToPenStyle(const QString&) const;
    Qt::PenCapStyle StrToCapStyle(const QString&)const;
    Qt::PenJoinStyle StrToJoinStyle(const QString&)const;
    Qt::BrushStyle StrToBrushStyle(const QString&)const;
    QFont::Style StrToFontStyle(const QString&)const;
    QFont::Weight StrToFontWeight(const QString&)const;
    QString StrToAllignment(const QString&) const;

signals:
    void shapeGenerated(const newShapeInfo& NEW_SHAPE);

private slots:
    void ShapeComboBox(const int& ARGUMENT);
    void GoToSecPage();
    void EnablePolySides(const int& ARGUMENT);
    void CompleteShape();


private:
    Ui::CreateShape *ui;

    QGroupBox *pickShape;
    QGroupBox *shapeInfo;

    QVBoxLayout *mainLayout;
    QFormLayout *pickShapeLayout;
    QFormLayout *shapeValuesLayout;

    QLabel *shapeLabel;
    QLabel *shapeNameLabel;
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
    QLabel *polySidesLabel;

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
    QSpinBox *polySidesBox;

    QLineEdit *shapeName;
    QLineEdit *textString;

    Vector<QLabel*> *dimensionsLabels;
    Vector<QSpinBox*> *dimensionsSpinBox;
};

#endif // CREATESHAPE_H
