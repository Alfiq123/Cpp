#include "test.h"
#include <QDebug>

Test::Test(QObject *parent) : QObject{parent} {

}

void Test::doStuff() {
    qInfo() << "Doing Stuff!";
    emit close();
}
