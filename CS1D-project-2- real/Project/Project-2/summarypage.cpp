#include "summarypage.h"
#include "ui_summarypage.h"

summarypage::summarypage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::summarypage)
{
    ui->setupUi(this);
}

summarypage::~summarypage()
{
    delete ui;
}
