#include "rooftypesorted.h"
#include "ui_rooftypesorted.h"

roofTypeSorted::roofTypeSorted(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::roofTypeSorted)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Teams With Open Roof Types Sorted");
    QString data = "";
    int count = 0;

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT Team_name, Roof_type FROM Stadium WHERE Roof_type "
           "LIKE '%Open%' ORDER BY Team_name ASC");

    while(q.next())
    {
        count++;
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nRoof Type: " + q.value(1).toString() +"\n\n";
    }
    QString numTeams = "Number of teams with a open roof stadium: ";

    data.append(numTeams);
    data.append(QString::number(count));

    ui->textBrowser->setText(data);

    closeDBDebug();
}

roofTypeSorted::~roofTypeSorted()
{
    delete ui;
}
