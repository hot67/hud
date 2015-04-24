#include "robotviewer.h"

RobotViewer::RobotViewer(QWidget *parent) : QWidget(parent)
{
    l_mainLayout = new QHBoxLayout;
    w_dataViewArea = new QMdiArea(this);

    l_mainLayout->addWidget(w_dataViewArea);

    setLayout(l_mainLayout);
}

RobotViewer::~RobotViewer()
{

}

