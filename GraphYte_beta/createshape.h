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
const int MAX_POLY_SIDES = 10;
const int IdRole         = Qt::UserRole;

namespace Ui {
class CreateShape;
}

class CreateShape : public QDialog
{
    Q_OBJECT

public:
    //Constructor
    explicit CreateShape(QWidget *parent = nullptr);

    //Deconstructor
    ~CreateShape();

    //Initialize the values needed for the UI
    void InitializeUIValues();

    //Set the values of the first page
    void SetFirstPgValues();

    //Set the values of the second page
    void SetSecondPgValues();

    //Generate the info needed for a new shape
    newShapeInfo GenerateShape();

    //Helper functions for setting the new shape values
    Qt::GlobalColor  StrToColor     (QString) const;
    Qt::PenStyle     StrToPenStyle  (const QString&) const;
    Qt::PenCapStyle  StrToCapStyle  (const QString&)const;
    Qt::PenJoinStyle StrToJoinStyle (const QString&)const;
    Qt::BrushStyle   StrToBrushStyle(const QString&)const;
    QFont::Style     StrToFontStyle (const QString&)const;
    QFont::Weight    StrToFontWeight(const QString&)const;
    QString          StrToAllignment(const QString&) const;

signals:
    //The signal to generate a new shape
    void shapeGenerated(const newShapeInfo& NEW_SHAPE);

private slots:

    //Controller of the shape combobox
    void ShapeComboBox(const int& ARGUMENT);

    //Controller to go to the second page
    void GoToSecPage();

    //Controller to enable the spinbox for polys
    void EnablePolySides(const int& ARGUMENT);

    //Controller to finish the screen
    void CompleteShape();


private:
    Ui::CreateShape *ui;    //The main UI

    QGroupBox *pickShape;   //The combobox that contanins info to pick a shape
    QGroupBox *shapeInfo;   //The combobox that contanins the info of the shape

    QVBoxLayout *mainLayout;        //The main layout for the program
    QFormLayout *pickShapeLayout;   //The layout for the pickShape groupbox
    QFormLayout *shapeValuesLayout; //The layout for the shapesValues groupbox

    QLabel *shapeLabel;         //Label for the shapes
    QLabel *shapeNameLabel;     //Label for the shape names
    QLabel *penWidthLabel;      //Label for the pen width
    QLabel *penStyleLabel;      //Label for the pen style
    QLabel *penCapLabel;        //Label for the pen cap
    QLabel *penJoinLabel;       //Label for the pen join
    QLabel *penColorLabel;      //Label for the pen color
    QLabel *brushColorLabel;    //Label for the brush color
    QLabel *brushStyleLabel;    //Label for the brush style
    QLabel *textStringLabel;    //Label for the text
    QLabel *textColorLabel;     //Label for the text color
    QLabel *textAlignmentLabel; //Label for the text allignment
    QLabel *textPointSizeLabel; //Label for the text point size
    QLabel *textFontFamilyLabel;//Label for the text font family
    QLabel *textFontStyleLabel; //Label for the text font style
    QLabel *textFontWeightLabel;//Label for the text font weight
    QLabel *polySidesLabel;     //Label for the polysides spinbox

    QPushButton *page2;         //Button to go to the next screen
    QPushButton *finished;      //Button to finish the shape

    QComboBox *shapeCBox;           //The combobox for the shapes
    QComboBox *penStyleCBox;        //The combobox for the pen style
    QComboBox *penCapCBox;          //The combobox for the pen cap
    QComboBox *penJoinCBox;         //The combobox for the pen join
    QComboBox *penColorCBox;        //The combobox for the pen color
    QComboBox *brushColorCBox;      //The combobox for the brush color
    QComboBox *brushStyleCBox;      //The combobox for the brush style
    QComboBox *textColorCBox;       //The combobox for the text color
    QComboBox *textAllignmentCBox;  //The combobox for the text allignment
    QComboBox *textFontFamilyCBox;  //The combobox for the text font family
    QComboBox *textFontStyleCBox;   //The combobox for the text font style
    QComboBox *textFontWeightCBox;  //The combobox for the text font weight

    QSpinBox *penWidthBox;  //The spinbox for the pen width
    QSpinBox *textPointBox; //The spinbox for the text point size
    QSpinBox *polySidesBox; //The spinbox for the text font weight

    QLineEdit *shapeName;   //The line edit for the shape name
    QLineEdit *textString;  //The line edit for the text

    Vector<QLabel*> *dimensionsLabels;      //The vector for all the label
    Vector<QSpinBox*> *dimensionsSpinBox;   //The vector for all the spinboxs
};

#endif // CREATESHAPE_H
