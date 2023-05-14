#ifndef ROOFTYPESORTED_H
#define ROOFTYPESORTED_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class roofTypeSorted;
}

class roofTypeSorted : public QMainWindow
{
    Q_OBJECT

public:
    explicit roofTypeSorted(QWidget *parent = nullptr);
    ~roofTypeSorted();

    // Holds the database file path
    QSqlDatabase db;

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

    void closeDBDebug()
    {
        db.close();
    }

private:
    Ui::roofTypeSorted *ui;
};

#endif // ROOFTYPESORTED_H
