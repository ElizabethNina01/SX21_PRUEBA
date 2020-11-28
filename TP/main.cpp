#include "mainwindow.h"
#include"registro.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Registro w;
    a.setStyle("fusion");
    w.show();
    return a.exec();
}
