/********************************************************************************
** Form generated from reading UI file 'displaywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWINDOW_H
#define UI_DISPLAYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DisplayWindow)
    {
        if (DisplayWindow->objectName().isEmpty())
            DisplayWindow->setObjectName("DisplayWindow");
        DisplayWindow->resize(800, 686);
        centralwidget = new QWidget(DisplayWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(250, 40, 321, 41));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(250, 90, 321, 41));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(250, 190, 321, 41));
        pushButton_3->setFont(font);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(250, 340, 321, 41));
        pushButton_4->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(250, 240, 321, 41));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(250, 140, 321, 41));
        pushButton_6->setFont(font);
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(250, 390, 321, 41));
        pushButton_7->setFont(font);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(250, 440, 321, 41));
        pushButton_8->setFont(font);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(250, 290, 321, 41));
        pushButton_9->setFont(font);
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(250, 490, 321, 41));
        pushButton_10->setFont(font);
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(250, 540, 321, 41));
        pushButton_11->setFont(font);
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(360, 600, 100, 32));
        QFont font1;
        font1.setBold(true);
        pushButton_12->setFont(font1);
        DisplayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DisplayWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        DisplayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DisplayWindow);
        statusbar->setObjectName("statusbar");
        DisplayWindow->setStatusBar(statusbar);

        retranslateUi(DisplayWindow);

        QMetaObject::connectSlotsByName(DisplayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DisplayWindow)
    {
        DisplayWindow->setWindowTitle(QCoreApplication::translate("DisplayWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("DisplayWindow", "Show Specific MLB Team Information", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DisplayWindow", "Show MLB Teams", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DisplayWindow", "Show American League Teams", nullptr));
        pushButton_4->setText(QCoreApplication::translate("DisplayWindow", "Show Open Roof Stadium Info", nullptr));
        pushButton_5->setText(QCoreApplication::translate("DisplayWindow", "Show National League Teams", nullptr));
        pushButton_6->setText(QCoreApplication::translate("DisplayWindow", "Show MLB Stadium Names and Teams", nullptr));
        pushButton_7->setText(QCoreApplication::translate("DisplayWindow", "Show MLB Stadiums By Date Opened", nullptr));
        pushButton_8->setText(QCoreApplication::translate("DisplayWindow", "Show MLB Stadiums and Total Seating Capacity", nullptr));
        pushButton_9->setText(QCoreApplication::translate("DisplayWindow", "Park Typology", nullptr));
        pushButton_10->setText(QCoreApplication::translate("DisplayWindow", "Greatest Distance to Center Field", nullptr));
        pushButton_11->setText(QCoreApplication::translate("DisplayWindow", "Smallest Distance to Center Field", nullptr));
        pushButton_12->setText(QCoreApplication::translate("DisplayWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
