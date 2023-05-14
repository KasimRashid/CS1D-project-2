#include "customtripwindow.h"
#include "ui_customtripwindow.h"

CustomTripWindow::CustomTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomTripWindow)
{
    ui->setupUi(this);
}

CustomTripWindow::~CustomTripWindow()
{
    delete ui;
}

void CustomTripWindow::on_visitAllBtn_clicked()
{
    visitAll = new MarlinsPark;
    visitAll->show();
}


void CustomTripWindow::on_customTripBtn_clicked()
{
    customInput = new custominput;
    customInput->show();

}

