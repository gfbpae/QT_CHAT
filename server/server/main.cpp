#include <QCoreApplication>
#include "server_app.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server_app x;

    return a.exec();
}
