#ifndef CUSTOMINPUT_H
#define CUSTOMINPUT_H

#include <QDialog>

namespace Ui {
class custominput;
}


/// customInput
///
/// Gets the starting team and all the other
/// teamss the user wants to visit on their custom trip

class custominput : public QDialog
{
    Q_OBJECT

public:
    explicit custominput(QWidget *parent = nullptr);
    ~custominput();

private:
    Ui::custominput *ui;
};

#endif // CUSTOMINPUT_H
