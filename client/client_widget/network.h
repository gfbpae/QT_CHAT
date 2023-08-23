#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QDataStream>

class network
{
public:
    network();
    QTcpSocket *get_socket(void);
    void connection_start();
    void message_sender(QString message);

private:
    QTcpSocket *socket;
public slots:

};

#endif // NETWORK_H
