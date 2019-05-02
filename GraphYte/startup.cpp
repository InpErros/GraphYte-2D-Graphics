#include "startup.h"
#include "ui_startup.h"
#include <QMovie>

Startup::Startup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Startup)
{
    ui->setupUi(this);
    QMovie *logo = new QMovie("://graphytelogoA.gif");
    ui->label_logo->setMovie(logo);
    ui->label_logo->resize(350,350);
    logo->start();
}

Startup::~Startup()
{
    delete ui;
}
