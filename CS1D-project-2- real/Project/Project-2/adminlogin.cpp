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
    ///Variables to store the user entered data
    QString Unsername = ui->name->text();
    QString Password = ui->password->text();

    adminMaintence = new class adminMaintence;

    if (Unsername == "a" && Password == "a"){
//        adminPage adminpage;
//        adminpage.setModal(true);
//        adminpage.exec();

        ///Hide the login page after the user enters a correct password
        this->hide();
        ///Show the admin maintence window
        adminMaintence->show();

    }
    else {
        ///Incorrect password
        ui->wrongPW->setText("wrong username or password");
    }
}

