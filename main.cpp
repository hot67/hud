#include "hotdashboard.h"
#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qsrand(time(NULL));

    a.setOrganizationName("hotteam67");
    a.setOrganizationDomain("org");
    a.setApplicationName("HUD");

    HotDashboard w;
    w.show();

    return a.exec();
}
