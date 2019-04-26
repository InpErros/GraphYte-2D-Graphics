#ifndef SECONDSCREEN_H
#define SECONDSCREEN_H

#include <QDialog>

namespace Ui {
class secondScreen;
}

class secondScreen : public QDialog
{
    Q_OBJECT

public:
    explicit secondScreen(QWidget *parent = nullptr);
    ~secondScreen();

private:
    Ui::secondScreen *ui;
};

#endif // SECONDSCREEN_H
