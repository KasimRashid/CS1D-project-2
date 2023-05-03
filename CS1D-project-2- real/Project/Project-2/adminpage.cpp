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
