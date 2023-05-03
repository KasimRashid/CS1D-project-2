/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_adminPage
{
public:
    QLabel *label;

    void setupUi(QDialog *adminPage)
    {
        if (adminPage->objectName().isEmpty())
            adminPage->setObjectName("adminPage");
        adminPage->resize(400, 300);
        label = new QLabel(adminPage);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 100, 181, 71));

        retranslateUi(adminPage);

        QMetaObject::connectSlotsByName(adminPage);
    } // setupUi

    void retranslateUi(QDialog *adminPage)
    {
        adminPage->setWindowTitle(QCoreApplication::translate("adminPage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("adminPage", "here is the admin page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminPage: public Ui_adminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H
