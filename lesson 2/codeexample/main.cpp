
#include "codeexample.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CodeExample w;
    w.show();
    return a.exec();
}
