#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QMainWindow>

namespace Ui {
class summarypage;
}

class summarypage : public QMainWindow
{
    Q_OBJECT

public:
    explicit summarypage(QWidget *parent = nullptr);
    ~summarypage();

private:
    Ui::summarypage *ui;
};

#endif // SUMMARYPAGE_H
