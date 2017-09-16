#include "mainwindow.h"
#include <QApplication>

Connection* Connection::instance_ = 0;
ACT* ACT::instance_ = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
