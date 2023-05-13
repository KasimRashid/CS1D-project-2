/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *adminButton;
    QPushButton *exitButton;
    QPushButton *menuButton;
    QPushButton *aboutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 90, 681, 71));
        QFont font;
        font.setPointSize(53);
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        adminButton = new QPushButton(centralwidget);
        adminButton->setObjectName("adminButton");
        adminButton->setGeometry(QRect(270, 290, 281, 71));
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        adminButton->setFont(font1);
        adminButton->setCursor(QCursor(Qt::PointingHandCursor));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(420, 390, 131, 51));
        exitButton->setFont(font1);
        exitButton->setCursor(QCursor(Qt::PointingHandCursor));
        menuButton = new QPushButton(centralwidget);
        menuButton->setObjectName("menuButton");
        menuButton->setGeometry(QRect(270, 200, 281, 71));
        menuButton->setFont(font1);
        menuButton->setCursor(QCursor(Qt::PointingHandCursor));
        aboutButton = new QPushButton(centralwidget);
        aboutButton->setObjectName("aboutButton");
        aboutButton->setGeometry(QRect(270, 390, 131, 51));
        aboutButton->setFont(font1);
        aboutButton->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Welcome!", nullptr));
        adminButton->setText(QCoreApplication::translate("MainWindow", "Admin", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuButton->setText(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        aboutButton->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
