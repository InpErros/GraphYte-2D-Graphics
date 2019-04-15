#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "createaccountwindow.h"
#include "introwindow.h"

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
    void on_pushButton_login_clicked();

    void on_pushButton_createaccount_clicked();

private:
    Ui::MainWindow *ui;
    CreateAccountWindow *createAccountWindow;
    IntroWindow *introWindow;
};

#endif // MAINWINDOW_H
