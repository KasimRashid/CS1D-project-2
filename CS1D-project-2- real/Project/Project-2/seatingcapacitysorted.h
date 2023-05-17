#ifndef SEATINGCAPACITYSORTED_H
#define SEATINGCAPACITYSORTED_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class seatingCapacitySorted;
}

/// seatingCapacitySorted
///
/// Dipslays the seating capacity of all
/// stadiums sorted

class seatingCapacitySorted : public QMainWindow
{
    Q_OBJECT

public:
    explicit seatingCapacitySorted(QWidget *parent = nullptr);
    ~seatingCapacitySorted();

    // Holds the database file path
    QSqlDatabase db;

    /// Sets database
    ///
    /// This method gets a path from the administrator and looks for the database
    /// in that given path and sets the database variable to that database

    void SetDataBase()
    {

        // Sets database path and name for the database variable
        db = QSqlDatabase::addDatabase("QSQLITE");

        //Adam's db file path
       QString path = "/Users/adamortiz/Desktop/CS1D-Project2-Git/CS1D-project-2/Baseball.db";

        // Allen's db file path
         // QString path = "/Users/allentarasyuk/Desktop/Baseball-Tour/CS1D-project-2/Baseball.db";

        qInfo() << path;
        db.setDatabaseName(path);
    }


    /// Opens database
    ///
    /// Calls database method to open database and returns to console
    /// if opened properly

    void openDBDebug()
    {
        // Opens database and output debug message if opened sucessfully
        if(db.open())
        {
            qDebug() << ("Connected.");
        }
        else
        {
            qDebug() << ("Not Connected.");
        }
    }



    /// Closes database
    ///
    /// Calls database method to close databases

    void closeDBDebug()
    {
        db.close();
    }

private:
    Ui::seatingCapacitySorted *ui;
};

#endif // SEATINGCAPACITYSORTED_H
