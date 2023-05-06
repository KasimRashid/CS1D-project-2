#include "displaywindow.h"
#include "ui_displaywindow.h"

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DisplayWindow)
{
    ui->setupUi(this);
}

DisplayWindow::~DisplayWindow()
{
    delete ui;
}

//"Show specific MLB Team Info" button
void DisplayWindow::on_pushButton_clicked()
{
    //If clicked show the teamInfoWindow window
    teamInfoWindow = new class teamInfoWindow;
    teamInfoWindow->show();
}

void DisplayWindow::on_mlbTeamName_pushButton_clicked()
{
    teamNameSortedByTeamName = new class teamNameSortedByTeamName;
    teamNameSortedByTeamName->show();
}


void DisplayWindow::on_teamNameSortedByStadium_pushButton_clicked()
{
    teamNameSortedByStadium = new class teamNameSortedByStadium;
    teamNameSortedByStadium->show();
}


void DisplayWindow::on_americanLeagueSorted_pushButton_clicked()
{
    americanTeamsSortedByTeamName = new class americanTeamsSortedByTeamName;
    americanTeamsSortedByTeamName->show();
}


void DisplayWindow::on_nationalLeagueSorted_pushButton_clicked()
{
    nationalTeamSortdByStadiumName = new class nationalTeamSortdByStadiumName;
    nationalTeamSortdByStadiumName->show();
}


void DisplayWindow::on_parkTypologySorted_pushButton_clicked()
{
    parkTypologySorted = new class parkTypologySorted;
    parkTypologySorted->show();
}

