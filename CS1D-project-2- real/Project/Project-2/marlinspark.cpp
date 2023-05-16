#include "marlinspark.h"
#include "ui_marlinspark.h"

#include <QDialog>
#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVector>
#include "summarypage.h"
#include "travelplan.h"

#include <QMessageBox>


MarlinsPark::MarlinsPark(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MarlinsPark)
{
    ui->setupUi(this);


      // Sets the database
      SetDataBase();
      ConnOpen();

      marlinsPark = new TravelPlan(db);

      // Instantiates variables
       marlinsPark->teamIndex = 0;
       marlinsPark->receipt.cost = 0;
       marlinsPark->receipt.distanceTraveled = 0;
       marlinsPark->currentTeam = "Marlins Park";

       // Sets font for ui display
       QFont font = ui->label->font();
       font.setBold(true);
       font.setPointSize(30);
       ui->label->setFont(font);

       // Shows the current college
       ui->label->setText(marlinsPark->currentTeam);

       // Outputs the souvenirs of the current college
       QSqlQuery q;

    q.exec("SELECT Item, Price FROM Souvenirs WHERE Team_name = 'Miami Marlins'");


//       q.exec("SELECT DISTINCT Team_name FROM Souvenirs");


//       QString teamName = "Miami Marlins"; // Replace with the team you are interested in
//       q.exec("SELECT Product, Price FROM Merchandise WHERE Team = '" + teamName + "'");




       QString data = "";
       QString dataCombo = "";

       while(q.next())
        {
                 dataCombo = q.value(0).toString();
                 ui->comboBox->addItem(q.value(0).toString());
                 data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

        }


       font.setBold(true);
       font.setPointSize(15);
       ui->textBrowser->setFont(font);
       ui->textBrowser->setText(data);
       ConnClose();


       // Finds the closest teams recursively
       marlinsPark->visitedTeams.push_back(marlinsPark->currentTeam);



       marlinsPark->FindClosestTeam(marlinsPark->currentTeam, marlinsPark->visitedTeams, 11, true);



       marlinsPark->teamReceipt.cost = 0;


        // Displays the colleges receipt
        DisplayReceipt();



}

MarlinsPark::~MarlinsPark()
{
    delete ui;
}

void MarlinsPark::on_purchaseBtn_clicked()
{
        ConnOpen();
        QString string = "";
        QString s = "";
        QSqlQuery q;
        s = ui->comboBox->currentText();
        marlinsPark->receipt.itemsBought.push_back(s);
        marlinsPark->teamReceipt.itemsBought.push_back(s);

        // Gets the cost of the souvenir item
        string = "SELECT Price FROM Souvenirs WHERE Item = \'" + s + "\'";

        q.exec(string);

        while(q.next())
        {
            s = q.value(0).toString();
        }

        marlinsPark->receipt.costOfItems.push_back(s.toDouble());
        marlinsPark->teamReceipt.costOfItems.push_back(s.toDouble());
        marlinsPark->teamReceipt.cost += s.toDouble();
        marlinsPark->receipt.cost += s.toDouble();

        // Updates the colleges receipt
        DisplayReceipt();

        qInfo() << marlinsPark->receipt.cost;

        ConnClose();


}


void MarlinsPark::on_nextBtn_clicked()
{

    if(marlinsPark->teamIndex != 10)
          {
              // Updates ui and variables for new college
              marlinsPark->teamReceipt.itemsBought.clear();
              marlinsPark->teamReceipt.costOfItems.clear();
              marlinsPark->teamReceipt.cost = 0;
              DisplayReceipt();

              ui->comboBox->clear();
              marlinsPark->teamIndex++;
              ui->comboBox->clear();
              ConnOpen();
              QSqlQuery q;

              qInfo() << marlinsPark->visitedTeams[marlinsPark->teamIndex];

              marlinsPark->currentTeam = marlinsPark->visitedTeams[marlinsPark->teamIndex];

              ui->label->setText(marlinsPark->currentTeam);

              // Displays the souvenir of the current college

             q.exec("SELECT Item, Price FROM Souvenirs WHERE Team_name = \'" + marlinsPark->currentTeam + "\'");

              QString data = "";
              QString dataCombo = "";


              while(q.next())
              {
                  dataCombo = q.value(0).toString();
                  ui->comboBox->addItem(q.value(0).toString());
                  data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

              }
              ui->textBrowser->setText(data);

              // Gets the distance from previous college to current college and adds it to the travelPlan
             q.exec("SELECT Distance FROM Distances WHERE Origin_stadium = \'" + marlinsPark->currentTeam + "\' AND Destination_stadium = \'" + marlinsPark->visitedTeams[marlinsPark->teamIndex-1] + "\'");


              while(q.next())
              {
                  marlinsPark->receipt.distanceTraveled += q.value(0).toDouble();
                  qInfo() << marlinsPark->receipt.distanceTraveled;

              }

              ConnClose();
          }
          else
          {
              // If we reached the end of colleges display the summaryPage
              this->hide();
              summaryWindow = new summarypage(this);
              summaryWindow->GetData(marlinsPark->receipt);

              summaryWindow->show();
          }




}


void MarlinsPark::DisplayReceipt()
{
    // Displays the total cost of items purchased from the current college
    QString receipt = "";
    QList<QString> items;
    QHash<QString, double> itemCosts;
    QHash<QString, int> itemCounts;

    for(int i = 0; i < marlinsPark->teamReceipt.itemsBought.size(); i++)
    {
        QString item = marlinsPark->teamReceipt.itemsBought[i];
        double cost = marlinsPark->teamReceipt.costOfItems[i];
        if (!itemCosts.contains(item)) {
            itemCosts.insert(item, cost);
            itemCounts.insert(item, 1);
            items.append(item);
        } else {
            itemCosts[item] += cost;
            itemCounts[item]++;
        }
    }

    for (int i = 0; i < items.size(); i++) {
        QString itemName = items.at(i);
        double cost = itemCosts[itemName];
        int count = itemCounts[itemName];
        QString itemString = itemName + (count > 1 ? " (x" + QString::number(count) + ")" : "");
        receipt += itemString + ": $" + QString::number(cost) + "\n";
    }

    receipt += "\n\n---------------------------\nTotal cost: $" + QString::number(marlinsPark->teamReceipt.cost);

    ui->textBrowser_2->setText(receipt);
}





















