#include "adminpage.h"
#include "ui_adminpage.h"

adminPage::adminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);
}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::on_Update_Teams_Button_clicked()
{

}


void adminPage::on_Update_Stadium_Button_clicked()
{

}

