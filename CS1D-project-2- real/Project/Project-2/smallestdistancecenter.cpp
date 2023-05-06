#include "smallestdistancecenter.h"
#include "ui_smallestdistancecenter.h"

smallestDistanceCenter::smallestDistanceCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::smallestDistanceCenter)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Stadiums with Smallest Distance to Center Field");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;

    q.exec("SELECT Team_name, Stadium_name, Distance_to_center FROM Stadium WHERE Distance_to_center = (SELECT MIN(Distance_to_center) FROM Stadium)");

    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() +
                "\nDistance to Center Field: " + q.value(2).toString() + "\n\n";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();
}

smallestDistanceCenter::~smallestDistanceCenter()
{
    delete ui;
}
