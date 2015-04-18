#include "hotdashboard.h"
#include "ui_hotdashboard.h"

HotDashboard::HotDashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HotDashboard)
{
    ui->setupUi(this);
}

HotDashboard::~HotDashboard()
{
    delete ui;
}
