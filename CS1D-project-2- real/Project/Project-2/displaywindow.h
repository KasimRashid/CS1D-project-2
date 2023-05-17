#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include "teaminfowindow.h"
#include "teamnamesortedbyteamname.h"
#include "teamnamesortedbystadium.h"
#include "americanteamssortedbyteamname.h"
#include "nationalteamsortdbystadiumname.h"
#include "parktypologysorted.h"
#include "rooftypesorted.h"
#include "dateopenedsorted.h"
#include "seatingcapacitysorted.h"
#include "greatestdistancecenter.h"
#include "smallestdistancecenter.h"

namespace Ui {
class DisplayWindow;
}

/// DisplayWindow
///
/// Provides the user a selection of buttons
/// that would provide relevent information about
/// stadiums, teams, and souvenirs

class DisplayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DisplayWindow(QWidget *parent = nullptr);
    ~DisplayWindow();

private slots:
    void on_pushButton_clicked();

    void on_mlbTeamName_pushButton_clicked();

    void on_teamNameSortedByStadium_pushButton_clicked();

    void on_americanLeagueSorted_pushButton_clicked();

    void on_nationalLeagueSorted_pushButton_clicked();

    void on_parkTypologySorted_pushButton_clicked();

    void on_openRoof_pushButton_clicked();

    void on_dateOpened_pushButton_clicked();

    void on_seatingCapacity_pushButton_clicked();

    void on_greatestDistance_pushButton_clicked();

    void on_smallesDistance_pushButton_clicked();

private:
    Ui::DisplayWindow *ui;
    teamInfoWindow *teamInfoWindow;
    teamNameSortedByTeamName* teamNameSortedByTeamName;
    teamNameSortedByStadium* teamNameSortedByStadium;
    americanTeamsSortedByTeamName* americanTeamsSortedByTeamName;
    nationalTeamSortdByStadiumName* nationalTeamSortdByStadiumName;
    parkTypologySorted* parkTypologySorted;
    roofTypeSorted* roofTypeSorted;
    dateOpenedSorted* dateOpenedSorted;
    seatingCapacitySorted* seatingCapacitySorted;
    greatestDistanceCenter* greatestDistanceCenter;
    smallestDistanceCenter* smallestDistanceCenter;
};

#endif // DISPLAYWINDOW_H
