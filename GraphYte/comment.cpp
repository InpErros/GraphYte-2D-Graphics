#include "comment.h"
#include "ui_comment.h"

Comment::Comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Comment)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);
}

Comment::~Comment()
{
    delete ui;
}
