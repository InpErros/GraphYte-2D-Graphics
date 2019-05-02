#include "contactinfo.h"
#include "ui_contactinfo.h"

ContactInfo::ContactInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this);


    // Pixmaps
    QPixmap discordIcon("://discordIcon.png");
    QPixmap githubIcon("://githubIcon.png");
    QPixmap logo("://graphyteicon.png");
    QPixmap emailIcon("://emailIcon.png");

    // Icons
    QIcon discordButton(discordIcon);
    QIcon githubButton(githubIcon);
    QIcon logoButton(logo);
    QIcon emailButton(emailIcon);

    QSize size(100,100);

    //Button Assignments
    ui->pushButton_discord->setIcon(discordButton);
    ui->pushButton_discord->setIconSize(size);

    ui->pushButton_github->setIcon(githubButton);
    ui->pushButton_github->setIconSize(size);

    ui->pushButton_email->setIcon(emailButton);
    ui->pushButton_email->setIconSize(size);

    ui->pushButton_URL->setIcon(logoButton);
    ui->pushButton_URL->setIconSize(size);
}

ContactInfo::~ContactInfo()
{
    delete ui;
}

void ContactInfo::on_pushButton_URL_clicked()
{

}

void ContactInfo::on_pushButton_discord_clicked()
{

}

void ContactInfo::on_pushButton_github_clicked()
{

}

void ContactInfo::on_pushButton_email_clicked()
{

}
