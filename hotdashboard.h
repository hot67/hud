#ifndef HOTDASHBOARD_H
#define HOTDASHBOARD_H

#include <QMainWindow>

namespace Ui {
class HotDashboard;
}

class HotDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit HotDashboard(QWidget *parent = 0);
    ~HotDashboard();

private:
    Ui::HotDashboard *ui;
};

#endif // HOTDASHBOARD_H
