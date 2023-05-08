#ifndef ADMINMAINTENCE_H
#define ADMINMAINTENCE_H

#include <QMainWindow>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class adminMaintence;
}

class adminMaintence : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminMaintence(QWidget *parent = nullptr);
    ~adminMaintence();

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

private slots:
    void on_teamName_comboBox_currentIndexChanged(int index);

    void on_souvenirsTeam_comboBox_currentIndexChanged(int index);

    void on_selectSouvenir_comboBox_currentIndexChanged(int index);

    void on_editPrice_pushButton_clicked();

    void on_addSouvenir_pushButton_clicked();

    void on_rmSouvenir_pushButton_clicked();

    void on_AddTeam_pushButton_clicked();

    void on_editCapacity_pushButton_clicked();

    void on_editRoof_pushButton_clicked();

    void on_editDate_pushButton_clicked();

    void on_editTypology_pushButton_clicked();

    void on_editPlayingSurface_pushButton_clicked();

    void on_editDistanceCenter_pushButton_clicked();

    void on_editLocation_pushButton_clicked();

    void on_editStadiumName_pushButton_clicked();

private:
    Ui::adminMaintence *ui;

    void addTeam(QTextStream& fileNewTeam);
    void addTeamDistance(QTextStream& fileNewTeam);
    bool checkPrice(QString price);
    bool checkString(QString s);
    bool checkNum(QString editNum);
};

#endif // ADMINMAINTENCE_H
