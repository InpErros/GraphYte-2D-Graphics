#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QLayout>
#include <vector.h>
#include "RenderArea.h"
#include "createshape.h"
#include "Shape.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void GenerateShape(const ShapeType& NEW_SHAPE);
    ~MainWindow();

private slots:
    void shapeChanged();
    void penChanged();
    void brushChanged();



    void on_actionNew_Shape_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    CreateShape *createShape;
};

#endif // MAINWINDOW_H
