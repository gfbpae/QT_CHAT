#include "network.h"

network::network() : socket(new QTcpSocket(nullptr))
{

}

QTcpSocket* network::get_socket(){return socket;}

void network::connection_start()
{
    get_socket()->connectToHost(QHostAddress::LocalHost, 8080);
    if (!get_socket()->waitForConnected()) {
        qCritical() << "Sunucuya bağlanılamadı.";
        return;
    }
    qDebug() << "Sunucuya bağlanıldı.";


}

void network::message_sender(QString message)
{
    socket->write(message.toUtf8());
}
