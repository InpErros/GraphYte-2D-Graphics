#include "mainwindow.h"
#include <QApplication>
#include "accountlist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    int i = a.exec();
    return i;
}
