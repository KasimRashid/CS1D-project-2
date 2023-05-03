/********************************************************************************
** Form generated from reading UI file 'adminlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGIN_H
#define UI_ADMINLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminLogin
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *name;
    QLineEdit *password;
    QPushButton *pushButton;
    QLabel *wrongPW;

    void setupUi(QDialog *adminLogin)
    {
        if (adminLogin->objectName().isEmpty())
            adminLogin->setObjectName("adminLogin");
        adminLogin->resize(400, 300);
        groupBox = new QGroupBox(adminLogin);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 291, 261));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(11, 61, 71, 16));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(11, 87, 71, 16));
        name = new QLineEdit(groupBox);
        name->setObjectName("name");
        name->setGeometry(QRect(95, 61, 161, 22));
        password = new QLineEdit(groupBox);
        password->setObjectName("password");
        password->setGeometry(QRect(95, 87, 161, 22));
        password->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(61, 121, 131, 31));
        wrongPW = new QLabel(groupBox);
        wrongPW->setObjectName("wrongPW");
        wrongPW->setGeometry(QRect(60, 210, 161, 16));

        retranslateUi(adminLogin);

        QMetaObject::connectSlotsByName(adminLogin);
    } // setupUi

    void retranslateUi(QDialog *adminLogin)
    {
        adminLogin->setWindowTitle(QCoreApplication::translate("adminLogin", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("adminLogin", "Admin Login", nullptr));
        label_2->setText(QCoreApplication::translate("adminLogin", "Username", nullptr));
        label->setText(QCoreApplication::translate("adminLogin", "Password", nullptr));
        pushButton->setText(QCoreApplication::translate("adminLogin", "Login", nullptr));
        wrongPW->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminLogin: public Ui_adminLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGIN_H
