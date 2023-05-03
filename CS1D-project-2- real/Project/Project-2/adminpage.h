#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class adminPage;
}

class adminPage : public QDialog
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    ~adminPage();

private:
    Ui::adminPage *ui;
};

#endif // ADMINPAGE_H
