#include "login.h"
#include "./ui_login.h"
#include <QMessageBox>
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}


void Login::on_Student_clicked()
{


}

void Login::on_Login_2_clicked()
{
    QString username = ui->theName->text();
    QString password = ui->thePassword->text();

    if(username == "A" && password == "a"){
        QMessageBox::information(this, "Login", "correct");

    }
    else{
    QMessageBox::warning(this, "Lgin", "not correct");
    }
}

