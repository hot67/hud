#include "robotnetwork.h"

robotnetwork::robotnetwork(QObject *parent) : QObject(parent)
{
    robotServer = new QTcpServer(this);

    connect(robotServer,SIGNAL(newConnection()),this,SLOT(newConnection()));

    if(!robotServer->listen(QHostAddress::Any,0067)){
        statusBar()->showMessage(tr("No robot connection available."));
    }
    else{
        statusBar()->showMessage(tr("Robot Connected."));
    }
}

robotnetwork::~robotnetwork()
{

}

void robotnetwork::newConnection()
{

}
