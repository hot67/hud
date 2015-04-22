#ifndef HOTDASHBOARD_H
#define HOTDASHBOARD_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class HotDashboard;
}

class HotDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit HotDashboard(QWidget *parent = 0);
    ~HotDashboard();

private slots:
    void about();

private:
    void createActions();
    void createMenus();
    void createStatusBar();

    Ui::HotDashboard *ui;

    QAction* act_quit;
    QAction* act_about;
    QAction* act_aboutQt;

    QMenu* menu_file;
    QMenu* menu_help;
};

#endif // HOTDASHBOARD_H
