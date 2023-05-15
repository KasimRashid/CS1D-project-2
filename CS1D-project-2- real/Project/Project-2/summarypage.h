#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QMainWindow>

#include <QDialog>
#include "travelplan.h"

namespace Ui {
class summarypage;
}

class summarypage : public QMainWindow
{
    Q_OBJECT

public:
    explicit summarypage(QWidget *parent = nullptr);




    /// Gets data to output to ui
    ///
    /// Gets a travelPlan receipt object to output
    /// to the values of to the ui

    void GetData(TravelPlan::Receipt currentReceipt);
    ~summarypage();

private:
    Ui::summarypage *ui;
};

#endif // SUMMARYPAGE_H
