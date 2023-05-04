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

private slots:
    void on_Update_Teams_Button_clicked();

    void on_Update_Stadium_Button_clicked();

private:
    Ui::adminPage *ui;
};

#endif // ADMINPAGE_H
