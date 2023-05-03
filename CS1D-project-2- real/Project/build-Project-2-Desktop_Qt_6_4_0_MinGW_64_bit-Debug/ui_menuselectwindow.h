/********************************************************************************
** Form generated from reading UI file 'menuselectwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUSELECTWINDOW_H
#define UI_MENUSELECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuSelectWindow
{
public:
    QWidget *centralwidget;
    QPushButton *displayButton;
    QPushButton *customButton;
    QPushButton *backButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MenuSelectWindow)
    {
        if (MenuSelectWindow->objectName().isEmpty())
            MenuSelectWindow->setObjectName("MenuSelectWindow");
        MenuSelectWindow->resize(800, 600);
        centralwidget = new QWidget(MenuSelectWindow);
        centralwidget->setObjectName("centralwidget");
        displayButton = new QPushButton(centralwidget);
        displayButton->setObjectName("displayButton");
        displayButton->setGeometry(QRect(270, 190, 271, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        displayButton->setFont(font);
        customButton = new QPushButton(centralwidget);
        customButton->setObjectName("customButton");
        customButton->setGeometry(QRect(270, 270, 271, 61));
        customButton->setFont(font);
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(270, 350, 271, 61));
        backButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 80, 681, 71));
        QFont font1;
        font1.setPointSize(48);
        font1.setBold(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        MenuSelectWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MenuSelectWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MenuSelectWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MenuSelectWindow);
        statusbar->setObjectName("statusbar");
        MenuSelectWindow->setStatusBar(statusbar);

        retranslateUi(MenuSelectWindow);

        QMetaObject::connectSlotsByName(MenuSelectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuSelectWindow)
    {
        MenuSelectWindow->setWindowTitle(QCoreApplication::translate("MenuSelectWindow", "MainWindow", nullptr));
        displayButton->setText(QCoreApplication::translate("MenuSelectWindow", "Display", nullptr));
        customButton->setText(QCoreApplication::translate("MenuSelectWindow", "Custom Trip", nullptr));
        backButton->setText(QCoreApplication::translate("MenuSelectWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MenuSelectWindow", "~ Menu ~", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuSelectWindow: public Ui_MenuSelectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUSELECTWINDOW_H
