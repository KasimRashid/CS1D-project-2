#include "seatingcapacitysorted.h"
#include "ui_seatingcapacitysorted.h"

seatingCapacitySorted::seatingCapacitySorted(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::seatingCapacitySorted)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Stadiums Sorted by Seating Capacity");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    //q.exec("SELECT Team_name, Stadium_name, Seating_capacity FROM Stadium ORDER BY Seating_capacity ASC");
    q.exec("SELECT Team_name, Stadium_name, Seating_capacity FROM Stadium ORDER BY Seating_capacity ASC");
    int sum = 0;

    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() +
                "\nSeating Capacity: " + q.value(2).toString() + "\n\n";
        sum += q.value(2).toString().toInt();
    }

    QString seatSum = "Total capacity of all major league teams: ";

    data.append(seatSum);
    data.append(QString::number(sum));
    ui->textBrowser->setText(data);

    closeDBDebug();
}

seatingCapacitySorted::~seatingCapacitySorted()
{
    delete ui;
}
