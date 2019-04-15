#ifndef CREATEACCOUNTWINDOW_H
#define CREATEACCOUNTWINDOW_H

#include <QMainWindow>

namespace Ui {
class CreateAccountWindow;
}

class CreateAccountWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateAccountWindow(QWidget *parent = nullptr);
    ~CreateAccountWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateAccountWindow *ui;
};

#endif // CREATEACCOUNTWINDOW_H
