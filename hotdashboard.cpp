#include "hotdashboard.h"
#include "ui_hotdashboard.h"

HotDashboard::HotDashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HotDashboard)
{
    ui->setupUi(this);

    createActions();
    createMenus();
    createStatusBar();
}

HotDashboard::~HotDashboard()
{
    delete ui;
}

void HotDashboard::about()
{
    QMessageBox::about(this,tr("About HUD"),tr("The <b>HOT Unique Dashboard (HUD)</b> is a robot dashboard designed by the Heroes of Tomorrow (FRC #67) "
                                               "to improve robot data reporting and organization, in tandem with the HOT RobotUtils project."));
}

void HotDashboard::createActions()
{
    act_quit = new QAction(tr("&Quit"),this);
    act_quit->setShortcuts(QKeySequence::Quit);
    act_quit->setStatusTip(tr("Close the HUD."));
    connect(act_quit, SIGNAL(triggered()), this, SLOT(close()));

    act_about = new QAction(tr("&About"),this);
    act_about->setStatusTip("About the HUD.");
    connect(act_about, SIGNAL(triggered()), this, SLOT(about()));

    act_aboutQt = new QAction(tr("About &Qt"),this);
    act_aboutQt->setStatusTip("About the Qt platform.");
    connect(act_aboutQt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void HotDashboard::createMenus()
{
    menu_file = menuBar()->addMenu(tr("&File"));
    menu_file->addAction(act_quit);

    menu_help = menuBar()->addMenu(tr("&Help"));
    menu_help->addAction(act_about);
    menu_help->addAction(act_aboutQt);
}

void HotDashboard::createStatusBar()
{
    statusBar()->showMessage(tr("Robot not found."));
}
