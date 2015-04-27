#include "robotnetwork.h"

RobotNetwork::RobotNetwork(QObject *parent, int team) : QObject(parent)
{
    m_address = QString("roboRIO-") + QString::number(team) + QString(".local");

    m_robotListener = new QUdpSocket(this);
    m_robotWriter = new QUdpSocket(this);

    connect(m_robotListener,SIGNAL(connected()),this,SLOT(connectionSuccessful()));
    connect(m_robotWriter,SIGNAL(connected()),this,SLOT(connectionSuccessful()));
    connect(m_robotListener,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(connectionUnsuccessful(QAbstractSocket::SocketError)));
    connect(m_robotWriter,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(connectionUnsuccessful(QAbstractSocket::SocketError)));

    QHostInfo::lookupHost(m_address,this,SLOT(setupSockets(QHostInfo)));
}

RobotNetwork::~RobotNetwork()
{

}

void RobotNetwork::connectionSuccessful()
{
    emit connected();
}

void RobotNetwork::connectionUnsuccessful(QAbstractSocket::SocketError error)
{
    switch (error)
    {
    case QAbstractSocket::ConnectionRefusedError:
        emit connectionError("Could not connect to robot: connection refused or timed out.");
        break;
    case QAbstractSocket::RemoteHostClosedError:
        emit connectionError("Robot terminated connection.");
        break;
    case QAbstractSocket::HostNotFoundError:
        emit connectionError("Could not find robot host at "+m_address+".");
        break;
    case QAbstractSocket::NetworkError:
        emit connectionError("Network error.");
        break;
    case QAbstractSocket::SocketAccessError:
        emit connectionError("Insufficient privileges to start socket connection.");
        break;
    case QAbstractSocket::AddressInUseError:
        emit connectionError("Could not connect: robot socket is already in exclusive use.");
        break;
    default:
        emit connectionError("Socket error "+QString::number(error)+". Please refer to the QAbstractSocket documentation for more details.");
    }
}

void RobotNetwork::setupSockets(QHostInfo info)
{
    QHostAddress roborio;

    if (info.error() == QHostInfo::NoError)
    {
        roborio = info.addresses().first();

        m_robotWriter->bind(roborio,1130);
        m_robotListener->bind(roborio,1140);
    }
    else
        emit connectionError(info.errorString());
}
