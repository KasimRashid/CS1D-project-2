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
    QPushButton *mlbTeamName_pushButton;
    QPushButton *americanLeagueSorted_pushButton;
    QPushButton *openRoof_pushButton;
    QPushButton *nationalLeagueSorted_pushButton;
    QPushButton *teamNameSortedByStadium_pushButton;
    QPushButton *dateOpened_pushButton;
    QPushButton *seatingCapacity_pushButton;
    QPushButton *parkTypologySorted_pushButton;
    QPushButton *greatestDistance_pushButton;
    QPushButton *smallesDistance_pushButton;
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
        mlbTeamName_pushButton = new QPushButton(centralwidget);
        mlbTeamName_pushButton->setObjectName("mlbTeamName_pushButton");
        mlbTeamName_pushButton->setGeometry(QRect(250, 90, 321, 41));
        mlbTeamName_pushButton->setFont(font);
        americanLeagueSorted_pushButton = new QPushButton(centralwidget);
        americanLeagueSorted_pushButton->setObjectName("americanLeagueSorted_pushButton");
        americanLeagueSorted_pushButton->setGeometry(QRect(250, 190, 321, 41));
        americanLeagueSorted_pushButton->setFont(font);
        openRoof_pushButton = new QPushButton(centralwidget);
        openRoof_pushButton->setObjectName("openRoof_pushButton");
        openRoof_pushButton->setGeometry(QRect(250, 340, 321, 41));
        openRoof_pushButton->setFont(font);
        nationalLeagueSorted_pushButton = new QPushButton(centralwidget);
        nationalLeagueSorted_pushButton->setObjectName("nationalLeagueSorted_pushButton");
        nationalLeagueSorted_pushButton->setGeometry(QRect(250, 240, 321, 41));
        nationalLeagueSorted_pushButton->setFont(font);
        teamNameSortedByStadium_pushButton = new QPushButton(centralwidget);
        teamNameSortedByStadium_pushButton->setObjectName("teamNameSortedByStadium_pushButton");
        teamNameSortedByStadium_pushButton->setGeometry(QRect(250, 140, 321, 41));
        teamNameSortedByStadium_pushButton->setFont(font);
        dateOpened_pushButton = new QPushButton(centralwidget);
        dateOpened_pushButton->setObjectName("dateOpened_pushButton");
        dateOpened_pushButton->setGeometry(QRect(250, 390, 321, 41));
        dateOpened_pushButton->setFont(font);
        seatingCapacity_pushButton = new QPushButton(centralwidget);
        seatingCapacity_pushButton->setObjectName("seatingCapacity_pushButton");
        seatingCapacity_pushButton->setGeometry(QRect(250, 440, 321, 41));
        seatingCapacity_pushButton->setFont(font);
        parkTypologySorted_pushButton = new QPushButton(centralwidget);
        parkTypologySorted_pushButton->setObjectName("parkTypologySorted_pushButton");
        parkTypologySorted_pushButton->setGeometry(QRect(250, 290, 321, 41));
        parkTypologySorted_pushButton->setFont(font);
        greatestDistance_pushButton = new QPushButton(centralwidget);
        greatestDistance_pushButton->setObjectName("greatestDistance_pushButton");
        greatestDistance_pushButton->setGeometry(QRect(250, 490, 321, 41));
        greatestDistance_pushButton->setFont(font);
        smallesDistance_pushButton = new QPushButton(centralwidget);
        smallesDistance_pushButton->setObjectName("smallesDistance_pushButton");
        smallesDistance_pushButton->setGeometry(QRect(250, 540, 321, 41));
        smallesDistance_pushButton->setFont(font);
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(360, 600, 100, 32));
        QFont font1;
        font1.setBold(true);
        pushButton_12->setFont(font1);
        DisplayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DisplayWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
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
        mlbTeamName_pushButton->setText(QCoreApplication::translate("DisplayWindow", "MLB Teams Sorted By Team Name", nullptr));
        americanLeagueSorted_pushButton->setText(QCoreApplication::translate("DisplayWindow", "American League Teams Sorted By Team Name", nullptr));
        openRoof_pushButton->setText(QCoreApplication::translate("DisplayWindow", "Open Roof Stadiums Sorted", nullptr));
        nationalLeagueSorted_pushButton->setText(QCoreApplication::translate("DisplayWindow", "National League Teams Sorted By Team Name", nullptr));
        teamNameSortedByStadium_pushButton->setText(QCoreApplication::translate("DisplayWindow", "MLB Team Names Sorted By Stadium Name", nullptr));
        dateOpened_pushButton->setText(QCoreApplication::translate("DisplayWindow", "Stadiums Sorted By Date Opened", nullptr));
        seatingCapacity_pushButton->setText(QCoreApplication::translate("DisplayWindow", "Stadiums Sorted by Seating Capacity", nullptr));
        parkTypologySorted_pushButton->setText(QCoreApplication::translate("DisplayWindow", "Park Typology Sorted", nullptr));
        greatestDistance_pushButton->setText(QCoreApplication::translate("DisplayWindow", "Greatest Distance to Center Field", nullptr));
        smallesDistance_pushButton->setText(QCoreApplication::translate("DisplayWindow", "Smallest Distance to Center Field", nullptr));
        pushButton_12->setText(QCoreApplication::translate("DisplayWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DisplayWindow: public Ui_DisplayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWINDOW_H
