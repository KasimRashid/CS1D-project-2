#include "menuselectwindow.h"
#include "ui_menuselectwindow.h"

MenuSelectWindow::MenuSelectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuSelectWindow)
{
    ui->setupUi(this);
}

MenuSelectWindow::~MenuSelectWindow()
{
    delete ui;
}




void MenuSelectWindow::on_displayButton_clicked()
{
    displaywindow = new DisplayWindow;
    displaywindow->show();
    //this->hide();
}


void MenuSelectWindow::on_backButton_clicked()
{





}


void MenuSelectWindow::on_customButton_clicked()
{

}

