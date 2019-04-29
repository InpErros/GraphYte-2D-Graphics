/********************************************************************************
** Form generated from reading UI file 'introwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTROWINDOW_H
#define UI_INTROWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IntroWindow
{
public:
    QLabel *label_logo;

    void setupUi(QWidget *IntroWindow)
    {
        if (IntroWindow->objectName().isEmpty())
            IntroWindow->setObjectName(QString::fromUtf8("IntroWindow"));
        IntroWindow->resize(381, 381);
        label_logo = new QLabel(IntroWindow);
        label_logo->setObjectName(QString::fromUtf8("label_logo"));
        label_logo->setGeometry(QRect(16, 12, 355, 355));
        label_logo->setAlignment(Qt::AlignCenter);

        retranslateUi(IntroWindow);

        QMetaObject::connectSlotsByName(IntroWindow);
    } // setupUi

    void retranslateUi(QWidget *IntroWindow)
    {
        IntroWindow->setWindowTitle(QApplication::translate("IntroWindow", "GraphYte | 2D Graphics Generator", nullptr));
        label_logo->setText(QApplication::translate("IntroWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntroWindow: public Ui_IntroWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTROWINDOW_H
