#include "marlinspark.h"
#include "ui_marlinspark.h"

MarlinsPark::MarlinsPark(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarlinsPark)
{
    ui->setupUi(this);
}

MarlinsPark::~MarlinsPark()
{
    delete ui;
}
