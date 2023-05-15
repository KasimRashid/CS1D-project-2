#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QtSql/QSqlDatabase>
#include <vector>
#include <QString>

using namespace std;



/// TravelPlan class
///
/// Holds the functionality and the data used for the different
/// travel plans

class TravelPlan
{

private:

    /// Compare Teamss
    ///
    /// Checks if two team strings are the same
    /// @param team1 first college name
    /// @param team2 second college name
    /// @returns if they are the same or not
    bool Compare(const QString& team1, const QString& team2);


public:

    /// Contains previosly visited teams' names.
    vector<QString> visitedTeams;

    /// Pointer to primary, shared sql database.
    QSqlDatabase& db;

    /// Index of current team.
    int teamIndex;

    /// Number of teams in this plan.
    int teamCount;



      /// Receipt struct
      ///
      /// Holds the items needed to display the receipt
      struct Receipt
      {
          /// Cost of each purchased item. Order synced with itemsBought
          std::vector<double> costOfItems;

          /// Name of each purchased item. Order synced with costOfItems
          std::vector<QString> itemsBought;

          /// Total travel expenses
          double cost;

          /// Total distance traveled.
          int distanceTraveled;

      };



      /// Name of current team
      QString currentTeam;

      /// This plan's receipt
      Receipt receipt;

      /// This plan's current team receipt
      Receipt teamReceipt;



         /// TravelPlan constructor
         ///
         /// Constructs TravelPlan object needs database
      TravelPlan(QSqlDatabase& db);


      ~TravelPlan();


    void FindClosestTeam(const QString& team, std::vector<QString> &teams, int size = 29);



    bool CheckIfTeamVisited(const QString& team, std::vector<QString> & visitedTeams);


//const QString& college, std::vector<QString>& visitedColleges





};

#endif // TRAVELPLAN_H
