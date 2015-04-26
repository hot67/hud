#ifndef ROBOTNETWORK_H
#define ROBOTNETWORK_H

#include <QObject>

class robotNetwork: public QObject
{
    Q_OBJECT
public:
    robotNetwork();
    ~robotNetwork();

private:
    void IP();
};

#endif // ROBOTNETWORK_H
