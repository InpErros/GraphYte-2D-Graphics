/********************************************************************************
** Form generated from reading UI file 'CreateShape.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESHAPE_H
#define UI_CREATESHAPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CreateShape
{
public:

    void setupUi(QDialog *CreateShape)
    {
        if (CreateShape->objectName().isEmpty())
            CreateShape->setObjectName(QString::fromUtf8("CreateShape"));
        CreateShape->resize(482, 356);

        retranslateUi(CreateShape);

        QMetaObject::connectSlotsByName(CreateShape);
    } // setupUi

    void retranslateUi(QDialog *CreateShape)
    {
        CreateShape->setWindowTitle(QApplication::translate("CreateShape", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateShape: public Ui_CreateShape {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESHAPE_H
