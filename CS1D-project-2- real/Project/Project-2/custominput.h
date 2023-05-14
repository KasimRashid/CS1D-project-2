#ifndef CUSTOMINPUT_H
#define CUSTOMINPUT_H

#include <QDialog>

namespace Ui {
class custominput;
}

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
