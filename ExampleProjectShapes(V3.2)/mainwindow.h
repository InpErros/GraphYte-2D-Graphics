#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QLayout>
#include <QInputDialog>
#include <vector.h>
#include "RenderArea.h"
#include "createshape.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();

    void GenerateShape(const newShapeInfo&);

    void GetNewCordinates();

    void GetCordinateInput(bool &ok, Vector<int>&shapeCords);

    void on_actionNew_Shape_triggered();

    void on_actionDelete_Shape_triggered();

    void on_actionMove_Shape_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    CreateShape *createShape;
};

#endif // MAINWINDOW_H
