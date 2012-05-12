#include "daedalus.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    daedalus w;
    w.show();
    return a.exec();
}
