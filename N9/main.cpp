#include "BroadcastSocket.h"
#include "qmlapplicationviewer.h"

#include <QtGui/QApplication>
#include <QtNetwork/QUdpSocket>
#include <QtDeclarative/QDeclarativeItem>

QUdpSocket* socket_ = 0;

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    {
        socket_ = new QUdpSocket(&app);
        socket_->writeDatagram("Hello\n", 6, QHostAddress::Broadcast, 9999);
    }

    qmlRegisterType<BroadcastSocket>("Pult", 1, 0, "BroadcastSocket");

    QmlApplicationViewer viewer;

    //QDeclarativeContext* ctxt = viewer.rootContext();
    //ctxt->setContextProperty("myModel", model);
    //ctxt->

    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setMainQmlFile(QLatin1String("qml/PultN9/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
