#include "contactinfo.h"
#include "ui_contactinfo.h"
#include <QDesktopServices>
#include <QUrl>
#include <QCoreApplication>

ContactInfo::ContactInfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ContactInfo)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal);


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
    //QString link = "://graphytehome.html";
    //QDesktopServices::openUrl(QUrl("file:///" + QCoreApplication::applicationDirPath() + "/graphytehome.html"));
    //QDesktopServices::openUrl(QUrl("https://www.google.com"));
    QDesktopServices::openUrl(QUrl("file:///" + QCoreApplication::applicationDirPath() + "/graphytehome.html"));
    //QCoreApplication::applicationFilePath()
}

void ContactInfo::on_pushButton_discord_clicked()
{
    QString link = "https://discord.gg/k9Dxpu2";
    QDesktopServices::openUrl(QUrl(link));
}

void ContactInfo::on_pushButton_github_clicked()
{
    QString link = "https://github.com/brandonTheProgram/GraphYte-2D-Graphics";
    QDesktopServices::openUrl(QUrl(link));
}

void ContactInfo::on_pushButton_email_clicked()
{
    QString link = "mailto:graphyte.help@cyberservices.com";
    QDesktopServices::openUrl(QUrl(link));
}
