#include "set.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    List<int> l;
     Set<int> s;

    return a.exec();
}
