#ifndef BROADCASTSOCKET_H
#define BROADCASTSOCKET_H

#include <QtCore/QString>
#include <QtDeclarative/QDeclarativeItem>

class BroadcastSocket : public QDeclarativeItem
{
    Q_OBJECT
public:
    BroadcastSocket(QDeclarativeItem* parent = 0);
    ~BroadcastSocket();

    Q_INVOKABLE void broadcast(QString const& s);

private:

};
#endif // BROADCASTSOCKET_H
