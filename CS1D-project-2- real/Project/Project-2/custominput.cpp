#include "custominput.h"
#include "ui_custominput.h"

custominput::custominput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::custominput)
{
    ui->setupUi(this);
}

custominput::~custominput()
{
    delete ui;
}
