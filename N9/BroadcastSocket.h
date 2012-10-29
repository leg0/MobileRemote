#ifndef BROADCASTSOCKET_H
#define BROADCASTSOCKET_H

#include <QtCore/QString>
#include <QtDeclarative/QDeclarativeItem>

class QUdpSocket;

class BroadcastSocket : public QDeclarativeItem
{
    Q_OBJECT

public:

    BroadcastSocket(QDeclarativeItem* parent = 0);
    virtual ~BroadcastSocket();

    Q_INVOKABLE void broadcast(QString const& s);

private:

    QUdpSocket* socket_;
};
#endif // BROADCASTSOCKET_H
