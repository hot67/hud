#include "robotnetwork.h"

RobotNetwork::RobotNetwork(QObject *parent, int team) : QObject(parent)
{
    m_rioHost = QString("roboRIO-") + QString::number(team) + QString(".local");
    m_team = team;

    m_connKey = 0;

    m_robotComs = new QUdpSocket(this);
    m_robotComs->bind(QHostAddress::LocalHost,HOST_PORT);

    connect(m_robotComs,SIGNAL(readyRead(),this,SLOT(processDatagram()));
    connect(m_robotComs,SIGNAL(connected()),this,SLOT(connectionSuccessful()));
}

RobotNetwork::~RobotNetwork()
{

}

void RobotNetwork::writeMessage(QString msg)
{
    m_robotComs->writeDatagram(msg.toStdString().c_str(),msg.size(),m_rioAddress,ROBOT_PORT);
}

void RobotNetwork::connect()
{
    if (m_rioHost != QHostAddress::Null)
        sendConnectRequest();
    else
        QHostInfo::lookupHost(m_rioHost,this,SLOT(setConnection(QHostInfo)));
}

void RobotNetwork::processDatagram()
{
    QByteArray data;
    QHostAddress senderAddress;

    data.resize(m_robotComs->pendingDatagramSize());

    m_robotComs->readDatagram(data.data(),data.size(),&senderAddress);

    if (senderAddress == m_rioAddress)
    {

    }
}

void RobotNetwork::connectionSuccessful()
{
    emit listening();
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

void RobotNetwork::setConnection(QHostInfo info)
{
    if (info.error() == QHostInfo::NoError)
    {
        m_rioAddress = info.addresses().first();

        sendConnectRequest();
    }
    else
        emit connectionError(info.errorString());
}

void RobotNetwork::sendConnectRequest()
{
    QString datagram;

    datagram = "HUD-"+QString::number(m_team)+':';

    if (m_connKey == 0)
        m_connKey = qrand() % ((0xffff - 0x1000) + 1) + 0x1000;

    datagram.append(QString::number(m_connKey,16));

    writeMessage(datagram);
}
