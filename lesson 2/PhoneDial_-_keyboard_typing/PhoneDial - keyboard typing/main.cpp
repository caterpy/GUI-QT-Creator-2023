#include "phonedial.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhoneDial w;
    w.show();
    return a.exec();
}
