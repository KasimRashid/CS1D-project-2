#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_adminlogin.h"
#include "adminlogin.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_adminButton_clicked()
{
// admin login

    adminLogin adminlogin;
    adminlogin.setModal(true);
    adminlogin.exec();

}


void MainWindow::on_exitButton_clicked()
{

}


void MainWindow::on_menuButton_clicked()
{
    menuselectwindow = new MenuSelectWindow;
    menuselectwindow->show();
    //this->hide();

}

