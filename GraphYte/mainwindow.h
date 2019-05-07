#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QLayout>
#include <QInputDialog>
#include "RenderArea.h"  /** RenderArea  **/
#include "createshape.h" /** CreateShape **/
#include "login.h"
#include "contactinfo.h"
#include "aboutus.h"
#include "comment.h"

const QString USERNAME = "admin";
const QString PASSWORD = "C++";

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor
    explicit MainWindow(QWidget *parent = nullptr);

    //Decconstructor
    ~MainWindow();

private slots:
    //Generate a new Shape
    void GenerateShape(const newShapeInfo&);

    //Get new Cordiantes for the shape
    void GetNewCordinates();

    //Get the new cordiantes as input
    void GetCordinateInput(bool &ok, Vector<int>&shapeCords);

    //Button to create a new shape window
    void on_actionNew_Shape_triggered();

    //Button to delete a shape
    void on_actionDelete_Shape_triggered();

    //Button to move a shape
    void on_actionMove_Shape_triggered();

    //Button to login
    void on_actionLogin_triggered();

    void on_actionContact_Us_triggered();

    void on_actionComments_triggered();

    void on_actionAbout_Us_triggered();

private:
    Ui::MainWindow *ui;             //The main ui for the program
    RenderArea     *renderArea;     //The canvas that draws the shapes
    CreateShape    *createShape;    //The Dialog to create a new shape
    Login* login;
    ContactInfo* contactInfo;
    AboutUs* aboutUs;
    Comment* comment;
};

#endif // MAINWINDOW_H
