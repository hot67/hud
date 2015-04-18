#include "hotdashboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HotDashboard w;
    w.show();

    return a.exec();
}
