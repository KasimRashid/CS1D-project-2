#include "displaywindow.h"
#include "ui_displaywindow.h"

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

//"Show specific MLB Team Info" button
void DisplayWindow::on_pushButton_clicked()
{
    //If clicked show the teamInfoWindow window
    teamInfoWindow = new class teamInfoWindow;
    teamInfoWindow->show();
}

