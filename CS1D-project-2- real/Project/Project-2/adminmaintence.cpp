#include "adminmaintence.h"
#include "ui_adminmaintence.h"

adminMaintence::adminMaintence(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminMaintence)
{
    ui->setupUi(this);

    this->setWindowTitle("Admin Maintence");

    ui->teamName_comboBox->addItem("Select Team");
    ui->souvenirsTeam_comboBox->addItem("Select Team");
    ui->selectSouvenir_comboBox->addItem("Select Souvenir");

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT * FROM Stadium ORDER BY Team_name ASC");

    //populate the ui combo box with the team names
    while(q.next())
    {
        ui->teamName_comboBox->addItem(q.value(0).toString());
        ui->souvenirsTeam_comboBox->addItem(q.value(0).toString());
    }

    closeDBDebug();

}

adminMaintence::~adminMaintence()
{
    delete ui;
}

//Function for displaying team info when a team is selected on combobox
void adminMaintence::on_teamName_comboBox_currentIndexChanged(int index)
{
    openDBDebug();

    QSqlQuery q;
    q.exec("SELECT Stadium_name, Seating_capacity, Location, Playing_surface, "
           "League, Date_opened, Distance_to_center, Typology, Roof_type FROM Stadium WHERE Team_name = \'"
           + ui->teamName_comboBox->itemText(index) + "\'");

    QString data = "";

    //Add new team
    ui->teamName_comboBox->addItem("Las Vegas Gamblers");

    while(q.next())
    {
        data += "Stadium Name: " + q.value(0).toString() + "" +
                "\nSeating Capacity: " + q.value(1).toString() + "" +
                "\nLocation: " + q.value(2).toString() + "" +
                "\nPlaying Surface: " + q.value(3).toString() + "" +
                "\nLeague: " + q.value(4).toString() + "" +
                "\nDate Opened: " + q.value(5).toString() + "" +
                "\nDistance to Center Field: " + q.value(6).toString() + "" +
                "\nTypology: " + q.value(7).toString() + "" +
                "\nRoof Type: " + q.value(8).toString() + "";
    }

    ui->team_textBrowser->setText(data);

    closeDBDebug();
}


void adminMaintence::on_souvenirsTeam_comboBox_currentIndexChanged(int index)
{
    openDBDebug();

    QSqlQuery q;
    q.exec("SELECT Item, Price FROM Souvenirs WHERE Team_name =\'" + ui->souvenirsTeam_comboBox->itemText(index) + "\'");

    QString data = "";

    //Show the souvenirs for the selected team in the text browser
    while(q.next())
    {
        data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";
    }

    ui->souvenir_textBrowser->setText(data);

    ///Populate the combo box under the souvenir text browser
    q.exec("SELECT Item FROM Souvenirs WHERE Team_name = \'" + ui->souvenirsTeam_comboBox->itemText(index) + "\'");


    while(q.next())
    {
        ui->selectSouvenir_comboBox->addItem(q.value(0).toString());
    }


    closeDBDebug();
}

//The combo box under the souvenir text browser
void adminMaintence::on_selectSouvenir_comboBox_currentIndexChanged(int index)
{
    //ui->selectSouvenir_comboBox->clear();

}


void adminMaintence::on_editPrice_pushButton_clicked()
{
    QString souvenirItem = ui->selectSouvenir_comboBox->currentText();
    QString souvenirTeam = ui->souvenirsTeam_comboBox->currentText();

    qDebug() << souvenirItem;
    qDebug() << souvenirTeam;

    QString newPrice = ui->editPrice_lineEdit->text();

    QSqlQuery q;

    //Show error message if price is invalid
    if (checkPrice(newPrice))
    {
        openDBDebug();

        q.exec("UPDATE Souvenirs set Price = '"+ newPrice +"' WHERE Item = '" + souvenirItem + "'");

        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited Price");
    }
    else {
        QMessageBox::critical(this, "", "Invalid Price");
    }
}

///This function will check the modified price
bool adminMaintence::checkPrice(QString editPrice)
{
    ///Edit the string so that the decimal place is removed (12.99 -> 1299).
    editPrice.replace(QString("."), QString(""));

    ///Check every character in the string for a number.
    for(int i = 0; i < editPrice.size(); i++)
    {
        if(!editPrice[i].isDigit())
        {
            return false;
        }
    }
    return true;
}


void adminMaintence::on_addSouvenir_pushButton_clicked()
{
    ///Get the current team selected in souvenirsTeam_comboBox
    QString addTeamSouvenir = ui->souvenirsTeam_comboBox->currentText();
    ///Get the new souvenir price
    QString addPrice = ui->souvenirPrice_lineEdit->text();
    ///Get the new souvenir name
    QString addName = ui->souvenirName_lineEdit->text();
    QSqlQuery q;

    ///If a team is selected on the first combo box then add the souvenir.
    if(ui->souvenirsTeam_comboBox->currentIndex() > 0 && ui->souvenirPrice_lineEdit->isEnabled())
    {
        ///If the price entered is valid
        if(checkPrice(addPrice))
        {
            openDBDebug();

            //Execute sql query
            q.exec("INSERT into Souvenirs (Team_name, Item, Price) VALUES (\'" + addTeamSouvenir + "\', \'" + addName + "\', \'" + addPrice + "\')");

            ///Inform user that the souvenir was added.
            QMessageBox::information(this, "", "Added Souvenir");
            closeDBDebug();
        }
        else
        {
            ///Inform user the new souvenir price was invalid
            QMessageBox::critical(this, "", "Invalid Price");
        }
    }
    else
        QMessageBox::warning(this, "", "Select a MLB team and enter a souvenir name and price");
}


void adminMaintence::on_rmSouvenir_pushButton_clicked()
{
    ///Get the current team selected in souvenirsTeam_comboBox
    QString souvenirTeam = ui->souvenirsTeam_comboBox->currentText();
    ///Get the current souvenir selected in selectSouvenir_comboBox
    QString souvenirRemove = ui->selectSouvenir_comboBox->currentText();

    QSqlQuery remove;

    ///If a team and souvenir is selected then a souvenir can be removed
    if(ui->souvenirsTeam_comboBox->currentIndex() > 0 && ui->selectSouvenir_comboBox->currentIndex() > 0 )
    {
        openDBDebug();

        remove.exec("DELETE FROM Souvenirs WHERE Item = '" + souvenirRemove + "'" + "AND Team_name = '" + souvenirTeam + "'");

        ///Inform user that the souvenir was removed.
        QMessageBox::information(this, "", "Removed Souvenir");
        closeDBDebug();
    }
    else
        QMessageBox::warning(this, "", "Select a MLB Team and souvenir");
}


void adminMaintence::on_AddTeam_pushButton_clicked()
{
    ///Get the current team selected in the teamName_comboBox
    QString teamSelected = ui->teamName_comboBox->currentText();

    //Adam's StadiumAddon.txt file Path (Replace with your on file path)
    QFile file("/Users/adamortiz/Desktop/CS1D-Project2-Git/CS1D-project-2/StadiumAddon.txt");

    QFile fileNewDistance("/Users/adamortiz/Desktop/CS1D-Project2-Git/CS1D-project-2/DistanceAddon.txt");

    qDebug() << teamSelected;

    ///Only add the new team if the new team is selected it the combo box
    if(teamSelected == "Las Vegas Gamblers")
    {
        ///If the file opens successfully then add its data
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::information(this, "information", "Successfully added new team.");

            QTextStream fileNewTeam(&file);

            addTeam(fileNewTeam);

            file.close();


        }
        else
        {
            QMessageBox::critical(this, "Error", "Failed adding team. Error opening txt");
        }
        ///If the new distance file opens successfully then add its data
        if(fileNewDistance.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            //Add new team distances
            QTextStream fileNewTeamDistance(&fileNewDistance);

            addTeamDistance(fileNewTeamDistance);

            fileNewDistance.close();
        }
        else
        {
            QMessageBox::critical(this, "Error", "Failed adding team distance. Error opening txt");
        }
    }
    else
    {
        ///Error is shown if team alreading exist in the DB file
        QMessageBox::critical(this, "Error", "This team is already in the data base.");
    }

}


void adminMaintence::addTeam(QTextStream& fileNewTeam)
{
    QStringList newTeamData;
    QString readLine;
    QString addDB;
    QSqlQuery insert;
    openDBDebug();

    //Add the txt file data into the data base
    while(!fileNewTeam.atEnd())
    {
        //Read the txt file and split the line at ":".
        readLine = fileNewTeam.readLine();
        newTeamData.append(readLine.split(':'));

        //Get the sql exec parameters
        addDB = "INSERT into Stadium (Team_name, Stadium_name, Seating_capacity, "
                "Location, Playing_surface, League, Date_opened, Distance_to_center, Typology, Roof_type) "
                "VALUES (\'" + newTeamData.at(0) + "\', \'" + newTeamData.at(1) + "\', \'" + newTeamData.at(2) + "\', \'" + newTeamData.at(3) + "\', \'" + newTeamData.at(4) + "\', \'" + newTeamData.at(5) + "\', \'" + newTeamData.at(6) + "\', \'" + newTeamData.at(7) + "\', \'" + newTeamData.at(8) + "\', \'" + newTeamData.at(9) + "\')";
        //Execute sql query
        insert.exec(addDB);

        //Clear list for the next line.
        newTeamData.clear();
    }

    closeDBDebug();
}


void adminMaintence::addTeamDistance(QTextStream& fileNewDistance)
{
    QStringList newTeamDistance;
    QSqlQuery insertDistance;
    QString readLineDistance;
    QString addDBDistance;

    openDBDebug();

    //Add new distance into DB
    //Add the txt file data into the data base
    while(!fileNewDistance.atEnd())
    {
        //Read the txt file and split the line at ":".
        readLineDistance = fileNewDistance.readLine();
        newTeamDistance.append(readLineDistance.split(':'));

        //Get the sql exec parameters
        addDBDistance = "INSERT into Distances (Origin_stadium, Destination_stadium, Distance) "
                "VALUES (\'" + newTeamDistance.at(0) + "\', \'" + newTeamDistance.at(1) + "\', \'" + newTeamDistance.at(2) + "\')";

        //Execute sql query
        insertDistance.exec(addDBDistance);

        //Clear list for the next line.
        newTeamDistance.clear();
    }

    ///Close DB debug
    closeDBDebug();
}


void adminMaintence::on_editCapacity_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new capacity entered by the user
    QString editCapacity = ui->capacity_lineEdit->text();

    QSqlQuery q;

    ///check if number is valid
    if (checkNum(editCapacity))
    {
        ///open db
        openDBDebug();

        ///Sql execute statement
        q.exec("UPDATE Stadium SET Seating_capacity = '"+ editCapacity +"' WHERE Team_name = '" + editTeamName + "'");

        ///close db
        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited seating capacity");
    }
    else {
        ///Show error message if price is invalid
        QMessageBox::critical(this, "", "Invalid number");
    }
}


void adminMaintence::on_editRoof_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new roof entered by the user
    QString editRoof = ui->roof_lineEdit->text();

    QSqlQuery q;

    ///check if number is valid
    if (checkString(editRoof))
    {
        ///open db
        openDBDebug();

        ///Sql execute statement
        q.exec("UPDATE Stadium SET Roof_type = '"+ editRoof +"' WHERE Team_name = '" + editTeamName + "'");

        ///close db
        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited roof type");
    }
    else {
        ///Show error message if price is invalid
        QMessageBox::critical(this, "", "Invalid number");
    }
}


void adminMaintence::on_editDate_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new date entered by the user
    QString editDate = ui->date_lineEdit->text();

    QSqlQuery q;

    ///check if number is valid
    if (checkPrice(editDate))
    {
        ///open db
        openDBDebug();

        ///Sql execute statement
        q.exec("UPDATE Stadium SET Date_opened = '"+ editDate +"' WHERE Team_name = '" + editTeamName + "'");

        ///close db
        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited Opening date");
    }
    else {
        ///Show error message if price is invalid
        QMessageBox::critical(this, "", "Invalid number");
    }
}


void adminMaintence::on_editTypology_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new date entered by the user
    QString editTypology = ui->typology_lineEdit->text();

    QSqlQuery q;

    ///check if number is valid
    if (checkString(editTypology))
    {
        ///open db
        openDBDebug();

        ///Sql execute statement
        q.exec("UPDATE Stadium SET Typology = '"+ editTypology +"' WHERE Team_name = '" + editTeamName + "'");

        ///close db
        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited stadium typology");
    }
    else {
        ///Show error message if price is invalid
        QMessageBox::critical(this, "", "Invalid string");
    }
}


void adminMaintence::on_editPlayingSurface_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new playing surface entered by the user
    QString editPlayingSurface = ui->surface_lineEdit->text();

    QSqlQuery q;

    ///check if string contains all letters
    if (checkString(editPlayingSurface))
    {
        ///open db
        openDBDebug();

        ///Sql execute statement
        q.exec("UPDATE Stadium SET Playing_surface = '"+ editPlayingSurface +"' WHERE Team_name = '" + editTeamName + "'");

        ///close db
        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited stadium playing surface");
    }
    else {
        ///Show error message if string is invalid
        QMessageBox::critical(this, "", "Invalid string");
    }
}


///This function will check if a string contains all letters
bool adminMaintence::checkString(QString s)
{
    ///Edit the string so that the spaces are replace
    s.replace(QString(" "), QString(""));

    ///Check every character in the string for a number.
    for(int i = 0; i < s.size(); i++)
    {
        if(!s[i].isLetter())
        {
            return false;
        }
    }
    return true;
}

void adminMaintence::on_editDistanceCenter_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new distance to center entered by the user
    QString editDistanceCenter = ui->distanceCenter_lineEdit->text();

    QSqlQuery q;

    ///open db
    openDBDebug();

    ///Sql execute statement
    q.exec("UPDATE Stadium SET Distance_to_center = '"+ editDistanceCenter +"' WHERE Team_name = '" + editTeamName + "'");

    ///close db
    closeDBDebug();

    ///Inform that the distance to center was updated
    QMessageBox::information(this, "", "Edited the distance to center");
}


void adminMaintence::on_editLocation_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new location entered by the user
    QString editLocation = ui->location_lineEdit->text();

    QSqlQuery q;

    ///open db
    openDBDebug();

    ///Sql execute statement
    q.exec("UPDATE Stadium SET Location = '"+ editLocation +"' WHERE Team_name = '" + editTeamName + "'");

    ///close db
    closeDBDebug();

    ///Inform that the location was updated
    QMessageBox::information(this, "", "Edited the location");

}


void adminMaintence::on_editStadiumName_pushButton_clicked()
{
    ///Get the current team name selected
    QString editTeamName = ui->teamName_comboBox->currentText();
    qDebug() << editTeamName;
    ///Store the new playing surface entered by the user
    QString editStadiumName = ui->stadiumName_lineEdit->text();

    QSqlQuery q;

    ///check if string contains all letters
    if (checkString(editStadiumName))
    {
        ///open db
        openDBDebug();

        ///Sql execute statement
        q.exec("UPDATE Stadium SET Stadium_name = '"+ editStadiumName +"' WHERE Team_name = '" + editTeamName + "'");

        ///close db
        closeDBDebug();

        ///Inform that the price was updated
        QMessageBox::information(this, "", "Edited stadium name");
    }
    else {
        ///Show error message if string is invalid
        QMessageBox::critical(this, "", "Invalid string");
    }
}

///This function will check the entered number
bool adminMaintence::checkNum(QString editNum)
{
    ///Edit the string so that the decimal place is removed (12.99 -> 1299).
    editNum.replace(QString(","), QString(""));

    ///Check every character in the string for a number.
    for(int i = 0; i < editNum.size(); i++)
    {
        if(!editNum[i].isDigit())
        {
            return false;
        }
    }
    return true;
}
