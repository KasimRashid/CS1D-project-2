#include "americanteamssortedbyteamname.h"
#include "ui_americanteamssortedbyteamname.h"

americanTeamsSortedByTeamName::americanTeamsSortedByTeamName(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::americanTeamsSortedByTeamName)
{
    ui->setupUi(this);

    //Change the style of the label at the top of the text browser
    ui->label->setStyleSheet("font : 16pt Times New Roman");

    this->setWindowTitle("American League Teams Sorted");
    QString data = "";

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("");

    while(q.next())
    {
        data += "";
    }

    ui->textBrowser->setText(data);

    closeDBDebug();
}

americanTeamsSortedByTeamName::~americanTeamsSortedByTeamName()
{
    delete ui;
}
