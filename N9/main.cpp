#include "BroadcastSocket.h"
#include "qmlapplicationviewer.h"

#include <QtGui/QApplication>
#include <QtNetwork/QUdpSocket>
#include <QtDeclarative/QDeclarativeItem>

//QUdpSocket* socket_ = 0;

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //socket_ = new QUdpSocket(&app);

    qmlRegisterType<BroadcastSocket>("RemoteN9", 1, 0, "BroadcastSocket");

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setMainQmlFile(QLatin1String("qml/RemoteN9/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
