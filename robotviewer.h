#ifndef ROBOTVIEWER_H
#define ROBOTVIEWER_H

#include <QWidget>

class RobotViewer : public QWidget
{
    Q_OBJECT
public:
    explicit RobotViewer(QWidget *parent = 0);
    ~RobotViewer();

signals:

public slots:
};

#endif // ROBOTVIEWER_H
