#include "mst.h"
#include "ui_mst.h"


mst::mst(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mst)
{
    ui->setupUi(this);

    this->setWindowTitle("MST");
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
        ///Edges for the MST
        insertEdge("Angel Stadium", "Petco Park", 110);
        insertEdge("Petco Park", "Angel Stadium", 110);
        insertEdge("Angel Stadium", "Dodger Stadium", 50);
        insertEdge("Busch Stadium", "Minute Maid Park", 680);
        insertEdge("Minute Maid Park", "Busch Stadium", 680);
        insertEdge("Busch Stadium", "Great American Ball Park", 310);
        insertEdge("Great American Ball Park", "Busch Stadium", 310);
        insertEdge("Busch Stadium", "Target Field", 465);
        insertEdge("Target Field", "Busch Stadium", 465);
        insertEdge("Busch Stadium", "Kauffman Stadium", 235);
        insertEdge("Kauffman Stadium", "Busch Stadium", 235);
        insertEdge("Chase Field", "Coors Field", 580);
        insertEdge("Chase Field", "Globe Life Park", 870);
        insertEdge("Chase Field", "Minute Maid Park", 1115);
        insertEdge("Minute Maid Park", "Chase Field", 1115);
        insertEdge("Chase Field", "Oakland-Alameda County Coliseum", 650);
        insertEdge("Oakland-Alameda County Coliseum", "Chase Field", 650);
        insertEdge("Chase Field", "Petco Park", 300);
        insertEdge("Petco Park", "Chase Field", 300);
        insertEdge("Citi Field", "Fenway Park", 195);
        insertEdge("Fenway Park", "Citi Field", 195);
        insertEdge("Citi Field", "Yankee Stadium", 50);
        insertEdge("Yankee Stadium", "Citi Field", 50);
        insertEdge("Citizens Bank Park", "Yankee Stadium", 80);
        insertEdge("Yankee Stadium", "Citizens Bank Park", 80);
        insertEdge("Citizens Bank Park", "Oriole Park at Camden Yards", 90);
        insertEdge("Oriole Park at Camden Yards", "Citizens Bank Park", 90);
        insertEdge("Comerica Park", "Guaranteed Rate Field", 240);
        insertEdge("Guaranteed Rate Field", "Comerica Park", 240);
        insertEdge("Comerica Park", "Rogers Centre", 210);
        insertEdge("Rogers Centre", "Comerica Park", 210);
        insertEdge("Comerica Park", "Progressive Field", 90);
        insertEdge("Coors Field", "Chase Field", 580);
        insertEdge("Coors Field", "Kauffman Stadium", 560);
        insertEdge("Kauffman Stadium", "Coors Field", 560);
        insertEdge("Coors Field", "Globe Life Park", 650);
        insertEdge("Coors Field", "Petco Park", 830);
        insertEdge("Petco Park", "Coors Field", 830);
        insertEdge("Dodger Stadium", "Angel Stadium", 50);
        insertEdge("Dodger Stadium", "Target Field", 1500);
        insertEdge("Target Field", "Dodger Stadium", 1500);
        insertEdge("Dodger Stadium", "Oakland-Alameda County Coliseum", 340);
        insertEdge("Oakland-Alameda County Coliseum", "Dodger Stadium", 340);
        insertEdge("Fenway Park", "Citi Field", 195);
        insertEdge("Fenway Park", "Marlins Park", 1255);
        insertEdge("Marlins Park", "Fenway Park", 1255);
        insertEdge("Fenway Park", "Rogers Center", 430);
        insertEdge("Rogers Center", "Fenway Park", 430);
        insertEdge("Globe Life Park", "Chase Field", 870);
        insertEdge("Globe Life Park", "Kauffman Stadium", 460);
        insertEdge("Kauffman Stadium", "Globe Life Park", 460);
        insertEdge("Globe Life Park", "SunTrust Park", 740);
        insertEdge("SunTrust Park", "Globe Life Park", 740);
        insertEdge("Globe Life Park", "Minute Maid Park", 230);
        insertEdge("Minute Maid Park", "Globe Life Park", 230);
        insertEdge("Globe Life Park", "Coors Field", 650);
        insertEdge("Great American Ball Park", "PNC Park", 260);
        insertEdge("PNC Park", "Great American Ball Park", 260);
        insertEdge("Great American Ball Park", "Progressive Field", 225);
        insertEdge("Progressive Field", "Great American Ball Park", 225);
        insertEdge("Great American Ball Park", "Tropicana Field", 790);
        insertEdge("Tropicana Field", "Great American Ball Park", 790);
        insertEdge("Great American Ball Park", "Guaranteed Rate Field", 250);
        insertEdge("Guaranteed Rate Field", "Great American Ball Park", 250);
        insertEdge("Great American Ball Park", "SunTrust Park", 375);
        insertEdge("SunTrust Park", "Great American Ball Park", 375);
        insertEdge("Guaranteed Rate Field", "Wrigley Field", 50);
        insertEdge("Wrigley Field", "Guaranteed Rate Field", 50);
        insertEdge("Kauffman Stadium", "Wrigley Field", 415);
        insertEdge("Wrigley Field", "Kauffman Stadium", 415);
        insertEdge("Marlins Field", "SunTrust Park", 600);
        insertEdge("SunTrust Park", "Marlins Field", 600);
        insertEdge("Marlins Field", "Nationals Field", 930);
        insertEdge("Nationals Field", "Marlins Field", 930);
        insertEdge("Marlins Field", "Tropicana Field", 210);
        insertEdge("Tropicana Field", "Marlins Field", 210);
        insertEdge("Marlins Field", "Fenway Park", 1255);
        insertEdge("Fenway Park", "Marlins Field", 1255);
        insertEdge("Marlins Field", "Minute Maid Park", 965);
        insertEdge("Minute Maid Park", "Marlins Field", 965);
        insertEdge("Miller Park", "Rodgers Center", 430);
        insertEdge("Rodgers Center", "Miller Park", 430);
        insertEdge("Miller Park", "Wrigley Field", 80);
        insertEdge("Wrigley Field", "Miller Park", 80);
        insertEdge("Miller Park", "Target Field", 300);
        insertEdge("Target Field", "Miller Park", 300);
        insertEdge("Minute Maid Park", "Tropicana Field", 790);
        insertEdge("Tropicana Field", "Minute Maid Park", 790);
        insertEdge("Nationals Park", "SunTrust Park", 560);
        insertEdge("SunTrust Park", "Nationals Park", 560);
        insertEdge("Nationals Park", "PNC Park", 195);
        insertEdge("PNC Park", "Nationals Park", 195);
        insertEdge("Nationals Park", "Oriole Park at Camden Yards", 50);
        insertEdge("Oriole Park at Camden Yards", "Nationals Park", 50);
        insertEdge("Oakland-Alameda County Coliseum", "Oracle Park", 50);
        insertEdge("Oracle Park", "Oakland-Alameda County Coliseum", 50);
        insertEdge("Oracle Park", "Safeco Field", 680);
        insertEdge("Safeco Field", "Oracle Park", 680);
        insertEdge("PNC Park", "Rogers Center", 225);
        insertEdge("Rogers Center", "PNC Park", 225);
        insertEdge("PNC Park", "Yankee Stadium", 315);
        insertEdge("Yankee Stadium", "PNC Park", 315);
        insertEdge("Progressive Field", "PNC Park", 115);
        insertEdge("PNC Park", "Progressive Field", 115);
        insertEdge("Rogers Center", "Fenway Park", 430);
        insertEdge("Fenway Park", "Rogers Center", 430);
        insertEdge("Rogers Center", "Safeco Field", 2070);
        insertEdge("Safeco Field", "Rogers Center", 2070);
        insertEdge("Safeco Field", "Target Field", 1390);
        insertEdge("Target Field", "Safeco Field", 1390);


        cout << "\nThe are the edges for the first 30 Stadiums:" << endl << endl;

        QString mstData = kruskalMST();

        ///Display the MST
        ui->textBrowser->setText(mstData);
    }


    ///If the new team is added use these edges
    if(count == 31)
    {
        ///Edges for the MST
        insertEdge("Angel Stadium", "Petco Park", 110);
        insertEdge("Petco Park", "Angel Stadium", 110);
        insertEdge("Angel Stadium", "Dodger Stadium", 50);
        insertEdge("Busch Stadium", "Minute Maid Park", 680);
        insertEdge("Minute Maid Park", "Busch Stadium", 680);
        insertEdge("Busch Stadium", "Great American Ball Park", 310);
        insertEdge("Great American Ball Park", "Busch Stadium", 310);
        insertEdge("Busch Stadium", "Target Field", 465);
        insertEdge("Target Field", "Busch Stadium", 465);
        insertEdge("Busch Stadium", "Kauffman Stadium", 235);
        insertEdge("Kauffman Stadium", "Busch Stadium", 235);
        insertEdge("Chase Field", "Coors Field", 580);
        insertEdge("Chase Field", "Globe Life Park", 870);
        insertEdge("Chase Field", "Minute Maid Park", 1115);
        insertEdge("Minute Maid Park", "Chase Field", 1115);
        insertEdge("Chase Field", "Oakland-Alameda County Coliseum", 650);
        insertEdge("Oakland-Alameda County Coliseum", "Chase Field", 650);
        insertEdge("Chase Field", "Petco Park", 300);
        insertEdge("Petco Park", "Chase Field", 300);
        insertEdge("Citi Field", "Fenway Park", 195);
        insertEdge("Fenway Park", "Citi Field", 195);
        insertEdge("Citi Field", "Yankee Stadium", 50);
        insertEdge("Yankee Stadium", "Citi Field", 50);
        insertEdge("Citizens Bank Park", "Yankee Stadium", 80);
        insertEdge("Yankee Stadium", "Citizens Bank Park", 80);
        insertEdge("Citizens Bank Park", "Oriole Park at Camden Yards", 90);
        insertEdge("Oriole Park at Camden Yards", "Citizens Bank Park", 90);
        insertEdge("Comerica Park", "Guaranteed Rate Field", 240);
        insertEdge("Guaranteed Rate Field", "Comerica Park", 240);
        insertEdge("Comerica Park", "Rogers Centre", 210);
        insertEdge("Rogers Centre", "Comerica Park", 210);
        insertEdge("Comerica Park", "Progressive Field", 90);
        insertEdge("Coors Field", "Chase Field", 580);
        insertEdge("Coors Field", "Kauffman Stadium", 560);
        insertEdge("Kauffman Stadium", "Coors Field", 560);
        insertEdge("Coors Field", "Globe Life Park", 650);
        insertEdge("Coors Field", "Petco Park", 830);
        insertEdge("Petco Park", "Coors Field", 830);
        insertEdge("Dodger Stadium", "Angel Stadium", 50);
        insertEdge("Dodger Stadium", "Target Field", 1500);
        insertEdge("Target Field", "Dodger Stadium", 1500);
        insertEdge("Dodger Stadium", "Oakland-Alameda County Coliseum", 340);
        insertEdge("Oakland-Alameda County Coliseum", "Dodger Stadium", 340);
        insertEdge("Fenway Park", "Citi Field", 195);
        insertEdge("Fenway Park", "Marlins Park", 1255);
        insertEdge("Marlins Park", "Fenway Park", 1255);
        insertEdge("Fenway Park", "Rogers Center", 430);
        insertEdge("Rogers Center", "Fenway Park", 430);
        insertEdge("Globe Life Park", "Chase Field", 870);
        insertEdge("Globe Life Park", "Kauffman Stadium", 460);
        insertEdge("Kauffman Stadium", "Globe Life Park", 460);
        insertEdge("Globe Life Park", "SunTrust Park", 740);
        insertEdge("SunTrust Park", "Globe Life Park", 740);
        insertEdge("Globe Life Park", "Minute Maid Park", 230);
        insertEdge("Minute Maid Park", "Globe Life Park", 230);
        insertEdge("Globe Life Park", "Coors Field", 650);
        insertEdge("Great American Ball Park", "PNC Park", 260);
        insertEdge("PNC Park", "Great American Ball Park", 260);
        insertEdge("Great American Ball Park", "Progressive Field", 225);
        insertEdge("Progressive Field", "Great American Ball Park", 225);
        insertEdge("Great American Ball Park", "Tropicana Field", 790);
        insertEdge("Tropicana Field", "Great American Ball Park", 790);
        insertEdge("Great American Ball Park", "Guaranteed Rate Field", 250);
        insertEdge("Guaranteed Rate Field", "Great American Ball Park", 250);
        insertEdge("Great American Ball Park", "SunTrust Park", 375);
        insertEdge("SunTrust Park", "Great American Ball Park", 375);
        insertEdge("Guaranteed Rate Field", "Wrigley Field", 50);
        insertEdge("Wrigley Field", "Guaranteed Rate Field", 50);
        insertEdge("Kauffman Stadium", "Wrigley Field", 415);
        insertEdge("Wrigley Field", "Kauffman Stadium", 415);
        insertEdge("Marlins Field", "SunTrust Park", 600);
        insertEdge("SunTrust Park", "Marlins Field", 600);
        insertEdge("Marlins Field", "Nationals Field", 930);
        insertEdge("Nationals Field", "Marlins Field", 930);
        insertEdge("Marlins Field", "Tropicana Field", 210);
        insertEdge("Tropicana Field", "Marlins Field", 210);
        insertEdge("Marlins Field", "Fenway Park", 1255);
        insertEdge("Fenway Park", "Marlins Field", 1255);
        insertEdge("Marlins Field", "Minute Maid Park", 965);
        insertEdge("Minute Maid Park", "Marlins Field", 965);
        insertEdge("Miller Park", "Rodgers Center", 430);
        insertEdge("Rodgers Center", "Miller Park", 430);
        insertEdge("Miller Park", "Wrigley Field", 80);
        insertEdge("Wrigley Field", "Miller Park", 80);
        insertEdge("Miller Park", "Target Field", 300);
        insertEdge("Target Field", "Miller Park", 300);
        insertEdge("Minute Maid Park", "Tropicana Field", 790);
        insertEdge("Tropicana Field", "Minute Maid Park", 790);
        insertEdge("Nationals Park", "SunTrust Park", 560);
        insertEdge("SunTrust Park", "Nationals Park", 560);
        insertEdge("Nationals Park", "PNC Park", 195);
        insertEdge("PNC Park", "Nationals Park", 195);
        insertEdge("Nationals Park", "Oriole Park at Camden Yards", 50);
        insertEdge("Oriole Park at Camden Yards", "Nationals Park", 50);
        insertEdge("Oakland-Alameda County Coliseum", "Oracle Park", 50);
        insertEdge("Oracle Park", "Oakland-Alameda County Coliseum", 50);
        insertEdge("Oracle Park", "Safeco Field", 680);
        insertEdge("Safeco Field", "Oracle Park", 680);
        insertEdge("PNC Park", "Rogers Center", 225);
        insertEdge("Rogers Center", "PNC Park", 225);
        insertEdge("PNC Park", "Yankee Stadium", 315);
        insertEdge("Yankee Stadium", "PNC Park", 315);
        insertEdge("Progressive Field", "PNC Park", 115);
        insertEdge("PNC Park", "Progressive Field", 115);
        insertEdge("Rogers Center", "Fenway Park", 430);
        insertEdge("Fenway Park", "Rogers Center", 430);
        insertEdge("Rogers Center", "Safeco Field", 2070);
        insertEdge("Safeco Field", "Rogers Center", 2070);
        insertEdge("Safeco Field", "Target Field", 1390);
        insertEdge("Target Field", "Safeco Field", 1390);

        ///New edges for the new added team
        insertEdge("Las Vegas Stadium", "Oakland-Alameda County Coliseum", 325);
        insertEdge("Oakland-Alameda County Coliseum", "Las Vegas Stadium", 325);
        insertEdge("Dodger Stadium", "Las Vegas Stadium", 300);
        insertEdge("Las Vegas Stadium", "Dodger Stadium", 300);
        insertEdge("Las Vegas Stadium", "Chase Field", 250);
        insertEdge("Chase Field", "Las Vegas Stadium", 250);

        cout << "\nThe are the edges for the first 30 Stadiums:" << endl << endl;

        QString mstData = kruskalMST();

        ///Display the MST
        ui->textBrowser->setText(mstData);
    }


}



int mst::getTeamCount()
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


mst::~mst()
{
    delete ui;
}
