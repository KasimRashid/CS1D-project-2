#ifndef DATEOPENEDSORTED_H
#define DATEOPENEDSORTED_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

namespace Ui {
class dateOpenedSorted;
}

class dateOpenedSorted : public QMainWindow
{
    Q_OBJECT

public:
    explicit dateOpenedSorted(QWidget *parent = nullptr);
    ~dateOpenedSorted();

    // Holds the database file path
    QSqlDatabase db;

    void SetDataBase()
    {

        // Sets database path and name for the database variable
        db = QSqlDatabase::addDatabase("QSQLITE");

        //Adam's db file path
        QString path = "/Users/adamortiz/Desktop/CS1D-Project2-Git/CS1D-project-2/Baseball.db";

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
    Ui::dateOpenedSorted *ui;
};

#endif // DATEOPENEDSORTED_H
