#ifndef ROBOTNETWORK_H
#define ROBOTNETWORK_H

#include <QtNetwork>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class RobotNetwork : public QObject
{
    Q_OBJECT
public:
    explicit RobotNetwork(QObject *parent = 0, int team = 0);
    ~RobotNetwork();

signals:
    void connected();
    void connectionError(QString errorString);

public slots:

private slots:
    void setupSockets(QHostInfo info);
    void connectionSuccessful();
    void connectionUnsuccessful(QAbstractSocket::SocketError error);

private:
    QUdpSocket* m_robotListener;
    QUdpSocket* m_robotWriter;

    QString m_address;
};

#endif // ROBOTNETWORK_H
