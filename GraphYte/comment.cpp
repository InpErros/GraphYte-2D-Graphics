#include "comment.h"
#include "ui_comment.h"
#include <fstream>

using std::ofstream;
using std::endl;

Comment::Comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Comment)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);

    QPixmap image("://comments.png");
    ui->label->setPixmap(image);
}

Comment::~Comment()
{
    delete ui;
}

void Comment::on_pushButton_clicked()
{
    QString comment = ui->plainTextEdit->toPlainText();


    ofstream fout;
    fout.open("testimonials.txt", std::ios_base::app);
    fout << comment.toStdString() << endl << endl;
    fout.close();
    this->hide();
}
