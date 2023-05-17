#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QMainWindow>
#include "adminmaintence.h"

namespace Ui {
class adminLogin;
}

/// adminLogin class definition.
///
/// Allows the admin to acess the admin page
/// by entering a user name and password

class adminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit adminLogin(QWidget *parent = nullptr);
    ~adminLogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::adminLogin *ui;
    adminMaintence* adminMaintence;
};

#endif // ADMINLOGIN_H
