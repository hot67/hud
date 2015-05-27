/** RobotNetwork - Network handler for roboRIO communications
 *
 * DATAGRAM LABEL KEY:
 *
 * "HUD-XXXX" (XXXX = team number): This label is used exclusively by the HUD to
 *          request a connection with a roboRIO. It contains a random key that is
 *          later used to verify the communications between the robot and the HUD.
 *          The robot uses this specific message to ensure that:
 *              a) the sender is in fact the HUD
 *              b) the computer running the HUD is the correct team.
 *
 * "U": This label is used exclusively by the roboRIO to provide data updates to the HUD.
 *
 * "D": This label is used exclusively by the HUD to send information back to the roboRIO.
 *
 * "S": This label is used exclusively by the roboRIO to indicate a successful connection.
 *
 * "P": This label indicates a ping from either side. It usually comes attached
 *
 * "I": This label is used to send communications information (that does not qualify as an error).
 *          This label is used by both the roboRIO and the HUD.
 *
 * "E": This label is used to send communications errors. This could include (but not limited to):
 *              - A mismatching team number
 *              - An erroneous sending address (i.e. the sender's address does not match
 *                  the host's address record)
 *          This label is used by both the roboRIO and the HUD.
 */

#ifndef ROBOTNETWORK_H
#define ROBOTNETWORK_H

#include <QtNetwork>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <ctime>

#define ROBOT_PORT 1130
#define HOST_PORT 1140

class RobotNetwork : public QObject
{
    Q_OBJECT
public:
    explicit RobotNetwork(QObject *parent = 0, int team = 0);
    ~RobotNetwork();

    void writeMessage (QString msg);
    void connect();

signals:
    void connected();
    void updateReceived(QString key, QString data);
    void listening();
    void connectionError(QString errorString);

public slots:

private slots:
    void processDatagram();
    void setConnection(QHostInfo info);
    void connectionSuccessful();
    void connectionUnsuccessful(QAbstractSocket::SocketError error);

private:
    void sendConnectRequest();

    QUdpSocket* m_robotComs;

    int m_team;

    QString m_rioHost;
    QHostAddress m_rioAddress;
    bool m_connected;
    int m_connKey;
};

#endif // ROBOTNETWORK_H
