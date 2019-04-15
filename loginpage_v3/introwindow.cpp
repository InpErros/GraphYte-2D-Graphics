#include "introwindow.h"
#include "ui_introwindow.h"
#include <QMovie>

IntroWindow::IntroWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntroWindow)
{
    ui->setupUi(this);

    QMovie *logo = new QMovie("://graphytelogoA.gif");
    ui->label_logo->setMovie(logo);
    ui->label_logo->resize(350,350);
    logo->start();


}

IntroWindow::~IntroWindow()
{
    delete ui;
}
