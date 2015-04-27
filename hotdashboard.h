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
    void updateStatusMessage(QString message);
    void robotConnected();

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void readSettings();
    void saveSettings();
    void setupNetworkSlots();

    Ui::HotDashboard *ui;

    RobotViewer* w_viewer;
    RobotNetwork* m_networkManager;

    QAction* act_quit;
    QAction* act_clear;
    QAction* act_about;
    QAction* act_aboutQt;

    QMenu* menu_file;
    QMenu* menu_help;

    int m_team;
};

#endif // HOTDASHBOARD_H
