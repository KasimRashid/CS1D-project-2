#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "teaminfowindow.h"

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QMainWindow
{
    Q_OBJECT

public:

    // Holds the database file path
    QSqlDatabase db;

    void SetDataBase()
    {

        // Sets database path and name for the database variable
        db = QSqlDatabase::addDatabase("QSQLITE");

        //Adam's db file path
        QString path = "/Users/adamortiz/Desktop/CS1D-Project2-Git/CS1D-project-2/CS1D-project-2- real/Baseball.db";

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

    explicit DisplayWindow(QWidget *parent = nullptr);
    ~DisplayWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DisplayWindow *ui;
    teamInfoWindow *teamInfoWindow;
};

#endif // DISPLAYWINDOW_H
