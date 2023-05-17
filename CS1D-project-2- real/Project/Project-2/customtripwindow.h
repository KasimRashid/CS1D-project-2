#ifndef CUSTOMTRIPWINDOW_H
#define CUSTOMTRIPWINDOW_H

#include "custominput.h"
#include "marlinspark.h"
#include <QMainWindow>

namespace Ui {
class CustomTripWindow;
}

/// customTripWindow
///
/// Displays options to either visit all
/// stadiums or selet the custom plan

class CustomTripWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomTripWindow(QWidget *parent = nullptr);
    ~CustomTripWindow();

private slots:
    void on_visitAllBtn_clicked();

    void on_customTripBtn_clicked();

private:
    Ui::CustomTripWindow *ui;

    MarlinsPark *visitAll;
    custominput *customInput;
};

#endif // CUSTOMTRIPWINDOW_H
