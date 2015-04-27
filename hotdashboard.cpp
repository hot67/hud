#include "hotdashboard.h"
#include "ui_hotdashboard.h"

HotDashboard::HotDashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HotDashboard)
{
    ui->setupUi(this);

    readSettings();

    m_networkManager = new RobotNetwork (this, m_team);
    w_viewer = new RobotViewer (this);

    setCentralWidget(w_viewer);

    createActions();
    createMenus();
    createStatusBar();
    setupNetworkSlots();
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

void HotDashboard::clear()
{

}

void HotDashboard::updateStatusMessage(QString message)
{
    statusBar()->showMessage(message);
}

void HotDashboard::robotConnected()
{
    statusBar()->showMessage("Robot connected, team #"+QString::number(m_team));
}

void HotDashboard::createActions()
{
    act_quit = new QAction(tr("&Quit"),this);
    act_quit->setShortcuts(QKeySequence::Quit);
    act_quit->setStatusTip(tr("Close the HUD."));
    connect(act_quit, SIGNAL(triggered()), this, SLOT(close()));

    act_clear = new QAction(tr("&Clear"), this);
    act_clear->setStatusTip(tr("Clear current HUD data."));
    connect(act_clear, SIGNAL(triggered()), this, SLOT(clear()));

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
    menu_file->addAction(act_clear);
    menu_file->addAction(act_quit);

    menu_help = menuBar()->addMenu(tr("&Help"));
    menu_help->addAction(act_about);
    menu_help->addAction(act_aboutQt);
}

void HotDashboard::createStatusBar()
{
    statusBar()->showMessage(tr("No robot connected."));
}

void HotDashboard::readSettings()
{
    QSettings settings;

    m_team = settings.value("teamNumber").toInt();
}

void HotDashboard::saveSettings()
{
    QSettings settings;

    settings.setValue("teamNumber",m_team);

    settings.sync();
}

void HotDashboard::setupNetworkSlots()
{
    connect(m_networkManager,SIGNAL(connected()),this,SLOT(robotConnected()));
    connect(m_networkManager,SIGNAL(connectionError(QString)),this,SLOT(updateStatusMessage(QString)));
}
