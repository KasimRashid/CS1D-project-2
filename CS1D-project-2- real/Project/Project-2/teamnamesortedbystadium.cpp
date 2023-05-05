#include "teamnamesortedbystadium.h"
#include "ui_teamnamesortedbystadium.h"

teamNameSortedByStadium::teamNameSortedByStadium(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teamNameSortedByStadium)
{
    ui->setupUi(this);


    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Team Names Sorted by Stadium");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT Team_name, Stadium_name FROM Stadium ORDER BY Stadium_name ASC");

    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() + "\n\n";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();
}

teamNameSortedByStadium::~teamNameSortedByStadium()
{
    delete ui;
}
