#ifndef MARLINSPARK_H
#define MARLINSPARK_H

#include "QtSql/qsqldatabase.h"
#include "summarypage.h"
#include "travelplan.h"
#include <QMainWindow>

namespace Ui {
class MarlinsPark;
}

/// Marlins Park
///
/// Provides the user the ability to traverse
/// all of the stadiums and pick souvenirs
/// along the way

class MarlinsPark : public QMainWindow
{
    Q_OBJECT

public:


    /// Holds the database for the program
     QSqlDatabase db;


      /// Sets database
      ///
      /// This method gets a path from the administrator and looks for the database
      /// in that given path and sets the database variable to that database

         void SetDataBase()
         {
             // sets database path and name for the database variable
             db = QSqlDatabase::addDatabase("QSQLITE");

             // Allen's db file path
             //QString path = "/Users/allentarasyuk/Desktop/Baseball-Tour/CS1D-project-2/Baseball.db";


             QString path = "/Users/adamortiz/Desktop/CS1D-Project2-Git/CS1D-project-2/Baseball.db";

             qInfo() << path;
             db.setDatabaseName(path);
         }



                /// Opens database
                 ///
                 /// Calls database method to open database and returns to console
                 /// if opened properly

                 void ConnOpen()
                 {
                     // Opens database and outputs if it opened sucessfully
                     if(db.open())
                     {
                         qDebug() << ("Connected.");

                     } else {

                         qDebug() << ("Not Connected.");
                     }
                 }



                 /// Closes database
                 ///
                 /// Calls database method to close database

                 void ConnClose()
                 {
                  db.close();
                 }



                 /// Display Receipt
                  ///
                  /// This method displays the receipt of the items
                  /// purchased at the current college


                  void DisplayReceipt();



    explicit MarlinsPark(QWidget *parent = nullptr);
    ~MarlinsPark();

private slots:
                  void on_purchaseBtn_clicked();

                  void on_nextBtn_clicked();

private:


    Ui::MarlinsPark *ui;
    TravelPlan *marlinsPark;
    summarypage *summaryWindow;
    TravelPlan::Receipt teamReceipt;







};

#endif // MARLINSPARK_H
