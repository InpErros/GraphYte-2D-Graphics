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
#include "login.h"

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

    void on_actionNew_Shape_triggered();

    void on_actionDelete_Shape_triggered();

    void on_actionMove_Shape_triggered();

private:
    Ui::MainWindow *ui;
    RenderArea *renderArea;
    CreateShape *createShape;
    Login *login;
};

#endif // MAINWINDOW_H
