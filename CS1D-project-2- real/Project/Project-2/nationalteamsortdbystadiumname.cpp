#include "nationalteamsortdbystadiumname.h"
#include "ui_nationalteamsortdbystadiumname.h"

nationalTeamSortdByStadiumName::nationalTeamSortdByStadiumName(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::nationalTeamSortdByStadiumName)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
   // ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("National League Teams Sorted");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("");

    //Sql statement to show the team name, the corresponding stadium and their league sorted by team name
    q.exec("SELECT Team_name, Stadium_name, League FROM Stadium WHERE League LIKE '%National%' ORDER BY Stadium_name ASC");


    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() +
                "\nLeague: " + q.value(2).toString() + "\n\n";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();

}

nationalTeamSortdByStadiumName::~nationalTeamSortdByStadiumName()
{
    delete ui;
}
