#include "secondscreen.h"
#include "ui_secondscreen.h"
#include <QPixmap>

secondScreen::secondScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondScreen)
{
    ui->setupUi(this);

    QPixmap pix(":/image/image/6c32ca0d39895510414ff4e8f8d4a1c1.png");
    ui->label_2->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
}

secondScreen::~secondScreen()
{
    delete ui;
}
