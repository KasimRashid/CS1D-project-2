#ifndef CUSTOMTRIPWINDOW_H
#define CUSTOMTRIPWINDOW_H

#include "marlinspark.h"
#include <QMainWindow>

namespace Ui {
class CustomTripWindow;
}

class CustomTripWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CustomTripWindow(QWidget *parent = nullptr);
    ~CustomTripWindow();

private slots:
    void on_visitAllBtn_clicked();

private:
    Ui::CustomTripWindow *ui;

    MarlinsPark *visitAll;
};

#endif // CUSTOMTRIPWINDOW_H
