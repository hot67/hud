#include "hotdashboard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("hotteam67");
    a.setOrganizationDomain("org");
    a.setApplicationName("HUD");

    HotDashboard w;
    w.show();

    return a.exec();
}
