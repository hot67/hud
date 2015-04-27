#ifndef ROBOTNETWORK_H
#define ROBOTNETWORK_H

#include <QtNetwork>
#include <QMainWindow>
#include <QObject>
#include <QWidget>

class robotnetwork : public QObject
{
    Q_OBJECT
public:
    explicit robotnetwork(QObject *parent = 0);
    ~robotnetwork();

signals:

public slots:
    void newConnection();

private:
    QTcpServer* robotServer;
};

#endif // ROBOTNETWORK_H
