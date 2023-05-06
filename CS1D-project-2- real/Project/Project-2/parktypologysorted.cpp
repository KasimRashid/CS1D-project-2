#include "parktypologysorted.h"
#include "ui_parktypologysorted.h"

parkTypologySorted::parkTypologySorted(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::parkTypologySorted)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Park Typology Sorted");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT Team_name, Stadium_name, Typology FROM Stadium ORDER BY Typology ASC");

    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() +
                "\nPark Typology: " + q.value(2).toString() + "\n\n";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();
}

parkTypologySorted::~parkTypologySorted()
{
    delete ui;
}
