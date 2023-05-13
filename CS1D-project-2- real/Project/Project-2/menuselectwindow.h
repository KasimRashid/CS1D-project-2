#ifndef MENUSELECTWINDOW_H
#define MENUSELECTWINDOW_H

#include "customtripwindow.h"
#include "displaywindow.h"

#include <QMainWindow>

namespace Ui {
class MenuSelectWindow;
}

class MenuSelectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuSelectWindow(QWidget *parent = nullptr);
    ~MenuSelectWindow();

private slots:


    void on_displayButton_clicked();

    void on_backButton_clicked();

    void on_customButton_clicked();



private:
    Ui::MenuSelectWindow *ui;
    DisplayWindow *displaywindow;

    CustomTripWindow *customTripWindow;
//    MainWindow *mainwindow;
};

#endif // MENUSELECTWINDOW_H
