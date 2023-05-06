#include "dateopenedsorted.h"
#include "ui_dateopenedsorted.h"

dateOpenedSorted::dateOpenedSorted(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dateOpenedSorted)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("Stadiums Sorted by Date Opened");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT Team_name, Stadium_name, Date_opened FROM Stadium ORDER BY Date_opened ASC");

    while(q.next())
    {
        data += "\nTeam Name: " + q.value(0).toString() +
                "\nStadium Name: " + q.value(1).toString() +
                "\nDate Opened: " + q.value(2).toString() + "\n\n";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();
}

dateOpenedSorted::~dateOpenedSorted()
{
    delete ui;
}
