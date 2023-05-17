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

      /// Finds closest team
       ///
       /// This method recursively finds the closest team
       /// @param team team to find closest team to
       /// @param teams vector of teams that will be visited
       /// @param size amount of teamss wanting to visit
       /// @param MarlinsPark if the method is being used for the initial Marlins Park plan
       /// @param custom if the method is being used for the custom plan
       /// @param customTeas custom set of colleges to visit


    void FindClosestTeam(const QString& team, std::vector<QString> &teams, int size = 11, bool marlinsPark = false, bool custom = false, vector<QString> customTeams = vector<QString>());



    /// Checks if Team was visited
    ///
    /// Goes through the vector of teams to see if the passed college was already visited
    /// @param team team to check if visited
    /// @param visitedteamss vector of team already visited

    bool CheckIfTeamVisited(const QString& team, std::vector<QString> & visitedTeams);





};

#endif // TRAVELPLAN_H
