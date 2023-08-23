#include "server_app.h"

server_app::server_app()
    :clientSocket_server(new QTcpSocket)
    ,server(new QTcpServer)

{

    if (!server->listen(QHostAddress::Any, 8080)) {
        qDebug() << "Hata: Sohbet sunucusu başlatılamadı: " << server->errorString();
        return;
    }

    connect(server, &QTcpServer::newConnection,this ,&server_app::Connection);
    qDebug() << "Sohbet sunucusu başlatıldı.";    
}

void server_app::Connection()
{
    qDebug() << "Bir istemci bağlandı.";
    clientSocket_server = server->nextPendingConnection();
    clients.append(clientSocket_server);
    connect(clientSocket_server, SIGNAL(readyRead()), this, SLOT(Read()));
    connect(clientSocket_server, &QTcpSocket::disconnected, this, &server_app::deleteCon);
}

void server_app::deleteCon()
{
    qDebug() << "Bir istemci ayrıldı.";
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    clients.removeOne(client);
    client->deleteLater();
}


void server_app::Read()
{
    QTcpSocket *senderSocket = qobject_cast<QTcpSocket*>(sender());

    if (!senderSocket)
        return;

    while (senderSocket->canReadLine())
    {
        QString line = QString::fromUtf8(senderSocket->readAll());
        qDebug() << line;
        QStringList mess = line.split(",:,");
        int CASE;
        if(mess.at(0)=="login") CASE=1;
        else if(mess.at(0)=="register") CASE=2;
        else CASE=3;

        switch (CASE)
        {
            case 1:
            {
                if(log(mess.at(1))) {senderSocket->write("OK ,:, Giriş yapılıyor ..");}
                else {senderSocket->write("NO ,:, Kullanıcı adı veya şifre yanlış ! ");}
                break;
            }
            case 2:
            {
                if(reg(mess.at(1))) {senderSocket->write("OK ,:, Kullanıcı oluşturuldu ..");}
                else {senderSocket->write("OK ,:, Kullanıcı adı kullanılıyor");}
                break;
            }
            case 3:
            {
                for (QTcpSocket *client : clients)
                {
                    ///if (client != senderSocket)
                    ///{
                    client->write(mess[1].toUtf8() + '\n');
                    ///client->flush();
                    ///}
                }
                break;
            }
        }
    }
}

bool server_app::log(QString x)
{
    QFile users("C:/Users/hrndr/Desktop/kullanıcılar.json");
    users.open(QIODevice::ReadOnly | QIODevice::Text);
    QByteArray json_byte = users.readAll();
    QJsonParseError errorptr;
    doc= QJsonDocument::fromJson(json_byte,&errorptr);
    QJsonObject deneme;
    deneme = doc.object();
    QJsonObject deneme2,deneme3;
    deneme2 = deneme["kullanicilar"].toObject();


    QStringList mess_log = x.split("\n")[0].split(",:");
    QString uname = mess_log[0];
    QString pass = mess_log[1];

    if(deneme2.contains(uname))
    {
        deneme3 = deneme2[uname].toObject();
        if(deneme3.value("sifre")==pass){qDebug()<<"Giriş yapılıyor";return true;}
        else {qDebug()<<"Şifre yanlış";return false;}
    }
    else {qDebug()<<"Kullanıcı Bulunamadı";return false;}
    users.close();
}

bool server_app::reg(QString x)
{
    QFile users("C:/Users/hrndr/Desktop/kullanıcılar.json");
    users.open(QIODevice::ReadOnly | QIODevice::Text );
    QByteArray json_byte = users.readAll();
    QJsonParseError errorptr;
    doc= QJsonDocument::fromJson(json_byte,&errorptr);
    if (errorptr.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << errorptr.errorString();
        return false;
    }
    QJsonObject deneme,deneme2,deneme3;
    deneme = doc.object();
    users.close();
    QStringList mess_log = x.split("\n")[0].split(",:");
    deneme3["ad"]=mess_log[1];
    deneme3["soyad"]=mess_log[2];
    deneme3["sifre"]=mess_log[3];
    deneme2 = deneme["kullanicilar"].toObject();
    deneme2.insert(mess_log[0],deneme3);
    deneme["kullanicilar"] = deneme2;
    users.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    users.write(QJsonDocument(deneme).toJson(QJsonDocument::Indented));
    return true;
}
