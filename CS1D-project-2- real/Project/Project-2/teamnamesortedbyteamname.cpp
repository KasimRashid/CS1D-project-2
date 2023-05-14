#include "teamnamesortedbyteamname.h"
#include "ui_teamnamesortedbyteamname.h"

teamNameSortedByTeamName::teamNameSortedByTeamName(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teamNameSortedByTeamName)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    // ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Team Names Sorted");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT Team_name, Stadium_name FROM Stadium ORDER BY Team_name ASC");

    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() + "\n\n";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();
}

teamNameSortedByTeamName::~teamNameSortedByTeamName()
{
    delete ui;
}
