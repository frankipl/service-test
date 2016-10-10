#ifndef SERVICEAPP_H
#define SERVICEAPP_H

#include <QtWidgets>
#include <QAndroidJniObject>
#include <QAndroidJniEnvironment>
#include <QtAndroid>
#include <QtRemoteObjects>
#include "rep_service_replica.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class ServiceApp: public QMainWindow {
    Q_OBJECT
public:
    ServiceApp(QWidget *parent=0);
public slots:
signals:
private slots:
    void elapsed(int counter,int time);
private:
    Ui::MainWindow      *ui;
    ServiceReplica      *service;
    QRemoteObjectNode   *repNode;
};

#endif // SERVICEAPP_H
