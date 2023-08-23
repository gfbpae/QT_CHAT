#ifndef SERVER_APP_H
#define SERVER_APP_H
#include <QCoreApplication>
#include <QTcpSocket>
#include <QTcpServer>
#include <QtNetwork>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>
#include <QByteArray>
#include <QArrayData>
#include <QJsonParseError>
#include <QString>
#include <QMap>
#include <QVector>

class server_app : public QObject
{
    Q_OBJECT
public:
    server_app();
private slots:
    void Connection();
    void Read();
    void deleteCon();
    bool log(QString);
    bool reg(QString);
signals:

private:
QTcpSocket *clientSocket_server;
QTcpServer *server;
QList <QTcpSocket *>clients;
//QFile users;
QJsonObject rootObj;
QJsonDocument doc;
};

#endif // SERVER_APP_H
