#ifndef DFS_H
#define DFS_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <iostream>
#include <vector>
#include <algorithm>
#include <QString>
#include <map>
#include <tuple>
using namespace std;

namespace Ui {
class dfs;
}

class dfs : public QMainWindow
{
    Q_OBJECT

public:
    explicit dfs(QWidget *parent = nullptr);
    ~dfs();

    /// Holds the database file path
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

    int getTeamCount();

    // DFS traversal function
    void makeDfs(const map<QString, vector<pair<QString, int>>> &graph, const QString &node, map<QString, bool> &visited, vector<tuple<QString, QString, int>> &discovery_edges, vector<tuple<QString, QString, int>> &back_edges, vector<QString> &traversal_sequence, const QString &parent = "")
    {
        // Mark the current node as visited and add it to the traversal sequence
        visited[node] = true;
        traversal_sequence.push_back(node);

        // Get neighbors of the current node and sort them by weight and name
        vector<pair<QString, int>> neighbors = graph.at(node);
        sort(neighbors.begin(), neighbors.end(), [&](const pair<QString, int> &a, const pair<QString, int> &b)
             {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first; });

        // Iterate through all neighbors
        for (const auto &neighbor : neighbors)
        {
            // If the neighbor is not visited, it's a discovery edge
            if (!visited[neighbor.first])
            {
                discovery_edges.push_back({node, neighbor.first, neighbor.second});
                // Perform DFS on the neighbor
                makeDfs(graph, neighbor.first, visited, discovery_edges, back_edges, traversal_sequence, node);
            }
            else if (neighbor.first != parent && find_if(discovery_edges.begin(), discovery_edges.end(), [&](const tuple<QString, QString, int> &edge)
                                                         { return (get<0>(edge) == neighbor.first && get<1>(edge) == node) || (get<0>(edge) == node && get<1>(edge) == neighbor.first); }) == discovery_edges.end())
            {
                // If the edge is not in discovery edges and not from the parent, it's a back edge
                if (find_if(back_edges.begin(), back_edges.end(), [&](const tuple<QString, QString, int> &edge)
                            { return (get<0>(edge) == neighbor.first && get<1>(edge) == node) || (get<0>(edge) == node && get<1>(edge) == neighbor.first); }) == back_edges.end())
                {
                    back_edges.push_back({node, neighbor.first, neighbor.second});
                }
            }
        }
    }


private:
    Ui::dfs *ui;
};

#endif // DFS_H
