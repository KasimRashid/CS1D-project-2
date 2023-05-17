#ifndef MST_H
#define MST_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <iostream>
#include <vector>
#include <algorithm>
#include <QString>
#include <map>
#include <QString>
using namespace std;

namespace Ui {
class mst;
}

class mst : public QMainWindow
{
    Q_OBJECT

public:
    explicit mst(QWidget *parent = nullptr);
    ~mst();

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





    struct Edge {
        //QString src, dest;
        QString src, dest;

        int weight = 0;
    };


    vector<Edge> edges;



    int Q1 = 0;
    // Function to add an edge to the graph
    void insertEdge(QString src, QString dest, int weight) {
        Edge e;
        e.src = src;
        e.dest = dest;
        e.weight = weight;
        edges.push_back(e);
        Q1 += weight;
    }


    // Function to find the parent of a vertex in the disjoint set
    QString findParent(QString vertex, map<QString, QString>& parent) {
        if (parent[vertex] == vertex)
            return vertex;
        return findParent(parent[vertex], parent);
    }


    // Function to perform union of two sets
    void performUnion(QString vertex1, QString vertex2, map<QString, QString>& parent) {
        QString parent1 = findParent(vertex1, parent);
        QString parent2 = findParent(vertex2, parent);
        parent[parent1] = parent2;
    }


    // Function to perform Kruskal's algorithm
    QString kruskalMST() {

        QString data = "";

        // Sort edges in ascending order of their weights
        sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) { return e1.weight < e2.weight; });
        // Initialize parent of each vertex as the vertex itself
        map<QString, QString> parent;
        for (auto e : edges) {
            parent[e.src] = e.src;
            parent[e.dest] = e.dest;
        }
        // Initialize the MST as an empty vector of edges
        vector<Edge> MST;
        // Iterate over all edges and add them to the MST if they don't create a cycle
        for (auto e : edges) {
            QString parent1 = findParent(e.src, parent);
            QString parent2 = findParent(e.dest, parent);
            if (parent1 != parent2) {
                MST.push_back(e);
                performUnion(e.src, e.dest, parent);
            }
        }
        int total = 0;

        // Print the MST
        for (auto e : MST) {
            //cout << e.src << " - " << e.dest << " : " << e.weight << endl;
            int i = e.weight;
            QString weight = QString::number(i);
            //QString str = QLocale().toQString(e.src);
            //QString str1 = QLocale().toQString(i);
            //QString str2 = e.weight.toString();
            data += e.src + " - " + e.dest + " : " +  weight + "\n";
            //data += "hey\n";
            total += e.weight;
        }

        QString weightSTR = "\n\nTotal weight is : " + QString::number(total) + "\n\n";

        return data + weightSTR;
    }


    int sumEdges(vector<pair<QString, int>> edges) {
        int total = 0;
        for (auto edge : edges) {
            total += edge.second;
        } return total;
    }



private:
    Ui::mst *ui;
};

#endif // MST_H
