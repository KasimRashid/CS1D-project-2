#include "travelplan.h"

#include <vector>
#include <list>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

using namespace std;


TravelPlan::TravelPlan(QSqlDatabase& db): db{db}
{}
TravelPlan::~TravelPlan()
{}

bool TravelPlan::CheckIfTeamVisited(const QString& team, std::vector<QString>& visitedTeams)
{
    // Checks the teams vector to if the team passed has been visited before
    for(unsigned int i = 0; i < visitedTeams.size(); i++)
    {
        if(Compare(team, visitedTeams[i]))
            return false;
    }
    return true;
}


bool TravelPlan::Compare(const QString& team1, const QString& team2)
{
    // Returns true if they are equal
    if(team1.size() != team2.size())
        return false;

    for(int i = 0; i < team1.size(); i++)
    {
        if(team1[i] != team2[i])
            return false;
    }
    return true;
}




void TravelPlan::FindClosestTeam(const QString& team, std::vector<QString> &teams, int size, bool marlinsPark, bool custom, vector<QString> customTeams){




    // Base Case
        if(teams.size() < size)
        {
            // Opens database
            db.open();
            std::list<QString> End;
            QSqlQuery q;
            QString string;

            // If the Saddleback plan or Custom plan execute a different sql statement
            if(marlinsPark || custom)
            {
                // If custom add each college the user wants to visit into the sql statement
                if(custom)
                {

                    string = "SELECT DISTINCT Destination_stadium FROM Distances WHERE Origin_stadium = \'" + team + "\'"
                            + "AND Destination_stadium = \'";
                    for(int i = 0; i < customTeams.size(); i++)
                    {
                        string += customTeams[i] + "\' OR Origin_stadium = \'" + team + "\'"
                                + "AND Destination_stadium = \'";
                    }
                    string += "\' ORDER BY Distance ASC";
                }
                else
                {



                    string = QString("SELECT DISTINCT Destination_stadium FROM Distances WHERE Origin_stadium = '%1' ORDER BY Distance ASC").arg(team);


                }

                qDebug() << string;
            }
            else
            {
                // Default sql statement
                string = "SELECT DISTINCT Destination_Stadium FROM Distances WHERE Origin_Stadium = \'" + team + "\' ORDER BY Distance ASC";
            }



            q.exec(string);


            // Get first closest stadium from current stadium and add it to list
            while(q.next())
            {
                End.push_back(q.value(0).toString());
            }

            // Check if the college has been visited
            for(; !CheckIfTeamVisited(End.front(), teams); End.pop_front());

            // Add to the vector if it hasn't
            teams.push_back(End.front());

            // Recall function until you reach amount of colleges wanted to visit
            FindClosestTeam(End.front(), teams, size, marlinsPark, custom, customTeams);
        }

        db.close();































//    // Base Case
//    if(teams.size() < size)
//    {

//        // Opens database
//          db.open();
//          std::list<QString> End;
//          QSqlQuery q;
//          QString string;

//     string = "SELECT DISTINCT Destination_stadium FROM Distances WHERE Origin_stadium = 'Marlins Park' ORDER BY Distance ASC";


//qDebug() << string;

//          q.exec(string);

//                 // Get first closest team from current team and add it to list

//                 while(q.next())
//                 {
//                     End.push_back(q.value(0).toString());
//                 }



//                 // Check if the team has been visited
//                for(; !CheckIfTeamVisited(End.front(), teams); End.pop_front());

//                 //Add to the vector if it hasn't
//                 teams.push_back(End.front());

//                 // Recall function until you reach amount of teams wanted to visit
//                 FindClosestTeam(End.front(), teams, size);


//    }

//    db.close();


}
