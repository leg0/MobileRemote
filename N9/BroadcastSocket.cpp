#include "BroadcastSocket.h"

#include <QtCore/QByteArray>
#include <QtNetwork/QUdpSocket>

//extern QUdpSocket* socket_;

BroadcastSocket::BroadcastSocket(QDeclarativeItem* parent)
    : QDeclarativeItem(parent)
    , socket_(new QUdpSocket(parent))
{ }

BroadcastSocket::~BroadcastSocket()
{ }

void BroadcastSocket::broadcast(QString const& s)
{
    Q_ASSERT(socket_ != 0);

    qDebug() << "Broadcasting" << s;
    QByteArray const& bytes = s.toLatin1();
    socket_->writeDatagram(bytes, bytes.size(), QHostAddress::Broadcast, 9999);
}
