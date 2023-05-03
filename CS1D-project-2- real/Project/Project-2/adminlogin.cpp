#include "adminlogin.h"
#include "ui_adminlogin.h"

adminLogin::adminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);
}

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::on_pushButton_clicked()
{
    QString Unsername = ui->name->text();
    QString Password = ui->password->text();
    if(Unsername == "a" && Password == "a"){
adminPage adminpage;
adminpage.setModal(true);
adminpage.exec();
    }
else{
ui->wrongPW->setText("wrong username or password");

    }
}

