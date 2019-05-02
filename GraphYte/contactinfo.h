#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <QMainWindow>

namespace Ui {
class ContactInfo;
}

class ContactInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit ContactInfo(QWidget *parent = nullptr);
    ~ContactInfo();

private slots:
    void on_pushButton_URL_clicked();

    void on_pushButton_discord_clicked();

    void on_pushButton_github_clicked();

    void on_pushButton_email_clicked();

private:
    Ui::ContactInfo *ui;
};

#endif // CONTACTINFO_H
