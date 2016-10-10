#include "service-app.h"

ServiceApp::ServiceApp(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow) {
    ui->setupUi(this);

    QAndroidJniObject::callStaticMethod<void>("com/kdab/training/MyService",
                                              "startMyService",
                                              "(Landroid/content/Context;)V",
                                              QtAndroid::androidActivity().object());

    repNode=new QRemoteObjectNode(this);
    repNode->connectToNode(QUrl(QStringLiteral("local:replica")));
    service=repNode->acquire<ServiceReplica>();
    bool res = service->waitForSource(10000);
    if(!res) {
        qDebug()<<"ServiceApp::ServiceApp not acquired";
    } else {
        qDebug()<<"ServiceApp::ServiceApp acquired";
    }

    connect(service,SIGNAL(elapsed(int,int)),this,SLOT(elapsed(int,int)));
    connect(ui->resetButton,SIGNAL(clicked(bool)),service,SLOT(reset()));
}
void ServiceApp::elapsed(int counter, int time) {
    ui->elapsedLabel->setText(QString("time seconds:%1").arg(time));
    ui->timerLabel->setText(QString("counter seconds:%1").arg(counter));
}
