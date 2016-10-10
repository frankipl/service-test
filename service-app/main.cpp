#include <QGuiApplication>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#include <QtAndroid>
#include <QDateTime>
#include "service-app.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    ServiceApp s;

    s.show();

    return app.exec();
}
