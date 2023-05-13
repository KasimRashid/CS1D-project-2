#ifndef MARLINSPARK_H
#define MARLINSPARK_H

#include <QMainWindow>

namespace Ui {
class MarlinsPark;
}

class MarlinsPark : public QMainWindow
{
    Q_OBJECT

public:
    explicit MarlinsPark(QWidget *parent = nullptr);
    ~MarlinsPark();

private:
    Ui::MarlinsPark *ui;
};

#endif // MARLINSPARK_H
