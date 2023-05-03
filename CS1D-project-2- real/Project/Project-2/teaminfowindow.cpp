#include "teaminfowindow.h"
#include "ui_teaminfowindow.h"

teamInfoWindow::teamInfoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teamInfoWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Team Information");

    ui->selectTeamcomboBox->addItem("Select Team");

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT * FROM Stadium ORDER BY Team_name ASC");

    QString name = "";

    //populate the ui combo box with the team names
    while(q.next())
    {
        if(name != q.value(0).toString()){
            ui->selectTeamcomboBox->addItem(q.value(0).toString());
        }
        name = q.value(0).toString();
    }

    closeDBDebug();

}


//Function for when a team is selected on the combo box
void teamInfoWindow::on_selectTeamcomboBox_currentIndexChanged(int index)
{
    openDBDebug();

    QSqlQuery q;
    q.exec("SELECT Stadium_name, Seating_capacity, Location, Playing_surface, "
           "League, Date_opened, Distance_to_center, Typology, Roof_type FROM Stadium WHERE Team_name = \'"
           + ui->selectTeamcomboBox->itemText(index) + "\'");

    QString data = "";

    while(q.next())
    {
        data += "Stadium Name: " + q.value(0).toString() + "\n" +
                "\nSeating Capacity: " + q.value(1).toString() + "\n" +
                "\nLocation: " + q.value(2).toString() + "\n" +
                "\nPlaying Surface: " + q.value(3).toString() + "\n" +
                "\nLeague: " + q.value(4).toString() + "\n" +
                "\nDate Opened: " + q.value(5).toString() + "\n" +
                "\nDistance to Center Field: " + q.value(6).toString() + "\n" +
                "\nTypology: " + q.value(7).toString() + "\n" +
                "\nRoof Type: " + q.value(8).toString() + "\n";
    }

    ui->textBrowser->setText(data);


    closeDBDebug();
}


teamInfoWindow::~teamInfoWindow()
{
    delete ui;
}



