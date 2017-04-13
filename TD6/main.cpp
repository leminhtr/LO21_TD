#include <iostream>

#include <QApplication>
#include <QDebug>

using namespace std;

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    qDebug() << QT_VERSION_STR;

qApp;

    return app.exec();
}