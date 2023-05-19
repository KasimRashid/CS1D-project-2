#include "dfs.h"
#include "ui_dfs.h"

dfs::dfs(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dfs)
{
    ui->setupUi(this);

    this->setWindowTitle("DFS");
    QString data = "";

    ///Get the number of teams in the data base
    int count = getTeamCount();

    /// Sets font for ui display
    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(15);
    ui->label->setFont(font);

    if(count == 30)
    {
        vector<tuple<QString, QString, int>> edges = {
        {"Angel Stadium", "Petco Park", 110},
        {"Petco Park", "Angel Stadium", 110},
            {"Angel Stadium", "Dodger Stadium", 50},
            {"Busch Stadium", "Minute Maid Park", 680},
            {"Minute Maid Park", "Busch Stadium", 680},
            {"Busch Stadium", "Great American Ball Park", 310},
            {"Great American Ball Park", "Busch Stadium", 310},
            {"Busch Stadium", "Target Field", 465},
            {"Target Field", "Busch Stadium", 465},
            {"Busch Stadium", "Kauffman Stadium", 235},
            {"Kauffman Stadium", "Busch Stadium", 235},
            {"Chase Field", "Coors Field", 580},
            {"Chase Field", "Globe Life Park", 870},
            {"Chase Field", "Minute Maid Park", 1115},
            {"Minute Maid Park", "Chase Field", 1115},
            {"Chase Field", "Oakland-Alameda County Coliseum", 650},
            {"Oakland-Alameda County Coliseum", "Chase Field", 650},
            {"Chase Field", "Petco Park", 300},
            {"Petco Park", "Chase Field", 300},
            {"Citi Field", "Fenway Park", 195},
            {"Fenway Park", "Citi Field", 195},
            {"Citi Field", "Yankee Stadium", 50},
            {"Yankee Stadium", "Citi Field", 50},
            {"Citizens Bank Park", "Yankee Stadium", 80},
            {"Yankee Stadium", "Citizens Bank Park", 80},
            {"Citizens Bank Park", "Oriole Park at Camden Yards", 90},
            {"Oriole Park at Camden Yards", "Citizens Bank Park", 90},
            {"Comerica Park", "Guaranteed Rate Field", 240},
            {"Guaranteed Rate Field", "Comerica Park", 240},
            {"Comerica Park", "Rogers Centre", 210},
            {"Rogers Centre", "Comerica Park", 210},
            {"Comerica Park", "Progressive Field", 90},
            {"Coors Field", "Chase Field", 580},
            {"Coors Field", "Kauffman Stadium", 560},
            {"Kauffman Stadium", "Coors Field", 560},
            {"Coors Field", "Globe Life Park", 650},
            {"Coors Field", "Petco Park", 830},
            {"Petco Park", "Coors Field", 830},
            {"Dodger Stadium", "Angel Stadium", 50},
            {"Dodger Stadium", "Target Field", 1500},
            {"Target Field", "Dodger Stadium", 1500},
            {"Dodger Stadium", "Oakland-Alameda County Coliseum", 340},
            {"Oakland-Alameda County Coliseum", "Dodger Stadium", 340},
            {"Fenway Park", "Citi Field", 195},
            {"Fenway Park", "Marlins Park", 1255},
            {"Marlins Park", "Fenway Park", 1255},
            {"Fenway Park", "Rogers Center", 430},
            {"Rogers Center", "Fenway Park", 430},
            {"Globe Life Park", "Chase Field", 870},
            {"Globe Life Park", "Kauffman Stadium", 460},
            {"Kauffman Stadium", "Globe Life Park", 460},
            {"Globe Life Park", "SunTrust Park", 740},
            {"SunTrust Park", "Globe Life Park", 740},
            {"Globe Life Park", "Minute Maid Park", 230},
            {"Minute Maid Park", "Globe Life Park", 230},
            {"Globe Life Park", "Coors Field", 650},
            {"Great American Ball Park", "PNC Park", 260},
            {"PNC Park", "Great American Ball Park", 260},
            {"Great American Ball Park", "Progressive Field", 225},
            {"Progressive Field", "Great American Ball Park", 225},
            {"Great American Ball Park", "Tropicana Field", 790},
            {"Tropicana Field", "Great American Ball Park", 790},
            {"Great American Ball Park", "Guaranteed Rate Field", 250},
            {"Guaranteed Rate Field", "Great American Ball Park", 250},
            {"Great American Ball Park", "SunTrust Park", 375},
            {"SunTrust Park", "Great American Ball Park", 375},
            {"Guaranteed Rate Field", "Wrigley Field", 50},
            {"Wrigley Field", "Guaranteed Rate Field", 50},
            {"Kauffman Stadium", "Wrigley Field", 415},
            {"Wrigley Field", "Kauffman Stadium", 415},
            {"Marlins Field", "SunTrust Park", 600},
            {"SunTrust Park", "Marlins Field", 600},
            {"Marlins Field", "Nationals Field", 930},
            {"Nationals Field", "Marlins Field", 93},
            {"Marlins Field", "Tropicana Field", 210},
            {"Tropicana Field", "Marlins Field", 210},
            {"Marlins Field", "Fenway Park", 1255},
            {"Fenway Park", "Marlins Field", 1255},
            {"Marlins Field", "Minute Maid Park", 965},
            {"Minute Maid Park", "Marlins Field", 965},
            {"Miller Park", "Rodgers Center", 430},
            {"Rodgers Center", "Miller Park", 430},
            {"Miller Park", "Wrigley Field", 80},
            {"Wrigley Field", "Miller Park", 80},
            {"Miller Park", "Target Field", 300},
            {"Target Field", "Miller Park", 300},
            {"Minute Maid Park", "Tropicana Field", 790},
            {"Tropicana Field", "Minute Maid Park", 790},
            {"Nationals Park", "SunTrust Park", 560},
            {"SunTrust Park", "Nationals Park", 560},
            {"Nationals Park", "PNC Park", 195},
            {"PNC Park", "Nationals Park", 195},
            {"Nationals Park", "Oriole Park at Camden Yards", 50},
            {"Oriole Park at Camden Yards", "Nationals Park", 50},
            {"Oakland-Alameda County Coliseum", "Oracle Park", 50},
            {"Oracle Park", "Oakland-Alameda County Coliseum", 50},
            {"Oracle Park", "Safeco Field", 680},
            {"Safeco Field", "Oracle Park", 680},
            {"PNC Park", "Rogers Center", 225},
            {"Rogers Center", "PNC Park", 225},
            {"PNC Park", "Yankee Stadium", 315},
            {"Yankee Stadium", "PNC Park", 315},
            {"Progressive Field", "PNC Park", 115},
            {"PNC Park", "Progressive Field", 115},
            {"Rogers Center", "Fenway Park", 430},
            {"Fenway Park", "Rogers Center", 430},
            {"Rogers Center", "Safeco Field", 2070},
            {"Safeco Field", "Rogers Center", 2070},
            {"Safeco Field", "Target Field", 1390},
            {"Target Field", "Safeco Field", 1390}
        };



        // Build the adjacency list for the graph
           map<QString, vector<pair<QString, int>>> graph;
           for (const auto &edge : edges)
           {
               graph[get<0>(edge)].emplace_back(get<1>(edge), get<2>(edge));
               graph[get<1>(edge)].emplace_back(get<0>(edge), get<2>(edge));
           }

           // Initialize variables for DFS traversal
        QString start_node = "Dallas";
        map<QString, bool> visited;
        vector<tuple<QString, QString, int>> discovery_edges;
        vector<tuple<QString, QString, int>> back_edges;
        vector<QString> traversal_sequence;

        // Perform DFS traversal
        makeDfs(graph, start_node, visited, discovery_edges, back_edges, traversal_sequence);

        // Print DFS traversal sequence
        cout << "DFS traversal sequence:" << endl;
        for (const auto &node : traversal_sequence)
        {
            //cout << node << endl;
             data += node + "\n";
        }

        cout << endl;

        // Print discovery edges
        cout << "Discovery edges:" << endl;
        for (const auto &edge : discovery_edges)
        {
            //cout << get<0>(edge) << " -> " << get<1>(edge) << endl;
        }

        // Print back edges
        cout << endl
             << "Back edges:" << endl;
        for (const auto &edge : back_edges)
        {
            //cout << get<0>(edge) << " -> " << get<1>(edge) << endl;
        }

        // Calculate and print total distance traveled on discovery edges
        int total_discovery_distance = 0;
        for (const auto &edge : discovery_edges)
        {
            total_discovery_distance += get<2>(edge);
        }

       //cout << endl << "Total distance travelled on discovery edges: " << total_discovery_distance << endl;

        //QString mstData = kruskalMST();

        ///Display the MST
        ui->textBrowser->setText(data);
    }



}




int dfs::getTeamCount()
{
    int count = 0;

    SetDataBase();
    openDBDebug();
    QSqlQuery q;
    q.exec("SELECT Team_name FROM Stadium");

    ///Count the number of teams in the data base
    while(q.next())
    {
        count++;
    }

    qInfo() << count;

    ///Return the number of teams in the data base
    return count;
}

dfs::~dfs()
{
    delete ui;
}
