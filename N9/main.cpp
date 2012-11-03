#include "BroadcastSocket.h"
#include "qmlapplicationviewer.h"
#include "WlanConnectionIndicator.h"

#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeItem>

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    qmlRegisterType<BroadcastSocket>("RemoteN9", 1, 0, "BroadcastSocket");
    qmlRegisterType<WlanConnectionIndicator>("RemoteN9", 1, 0, "WlanConnectionIndicator");

    QApplication app(argc, argv);

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationLockPortrait);
    viewer.setMainQmlFile(QLatin1String("qml/RemoteN9/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
