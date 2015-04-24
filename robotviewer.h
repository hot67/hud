#ifndef ROBOTVIEWER_H
#define ROBOTVIEWER_H

#include <QWidget>
#include <QMdiArea>
#include <QLayout>

class RobotViewer : public QWidget
{
    Q_OBJECT
public:
    explicit RobotViewer(QWidget *parent = 0);
    ~RobotViewer();

signals:

public slots:

private:
    QHBoxLayout* l_mainLayout;
    QMdiArea* w_dataViewArea;
};

#endif // ROBOTVIEWER_H
