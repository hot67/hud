#ifndef HOTDASHBOARD_H
#define HOTDASHBOARD_H

#include <QMainWindow>
#include <QMessageBox>
#include "robotviewer.h"

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
    void clear();

private:
    void createActions();
    void createMenus();
    void createStatusBar();

    Ui::HotDashboard *ui;

    RobotViewer* w_viewer;

    QAction* act_quit;
    QAction* act_clear;
    QAction* act_about;
    QAction* act_aboutQt;

    QMenu* menu_file;
    QMenu* menu_help;
};

#endif // HOTDASHBOARD_H
