#include "mainwindow.h"
#include "linkedlist.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    QString comment = ui->textEdit->toPlainText();



    QScrollBar *horizontalScroll = ui->horizontalScrollBar;
    int valueH = horizontalScroll->value();


    linkedListType array;
    array.retrieveFromTxt();                    // Retrieve comments from txt file
                                                // and save it in the linked list
    array.insertlast(comment.toStdString(), valueH);    // Save new comment to the linked list

    array.saveToTxt();                          // Save all comments back to txt file


    // Close the window after submitting
    close();

}




void MainWindow::on_horizontalScrollBar_valueChanged()
{
    //Syncing horizontalScrollBar and spinBox
    QObject::connect (ui->horizontalScrollBar, SIGNAL(valueChanged(int)),
                      ui->spinBox, SLOT(setValue(int)));
    QObject::connect (ui->spinBox, SIGNAL(valueChanged(int)),
                      ui->horizontalScrollBar, SLOT(setValue(int)));

}
