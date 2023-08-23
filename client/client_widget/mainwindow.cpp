#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connection_start();


    connect(get_socket(),&QTcpSocket::readyRead,this,&MainWindow::catch_message);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connection_check()
{
}

void MainWindow::on_send_clicked()///girilen mesajı gönderir
{
    QString message = ui->sended->text(); ///girilen mesajı alır

    if (!message.isEmpty())
    {
        QString messag = "mess,:,Client : "+message+"\n";
        message_sender(messag);
        get_socket()-> write(messag.toUtf8());
        ui->messages->append("You: " + message);

    }
    ui->sended->clear();
}


void MainWindow::on_reg_clicked()///kullanıcı oluşturmak için bilgileri servera gönderir
{

    /*QString ID = ui->reg_ID->text();
    QString password = ui->reg_PASSWORD->text();
    QString name = ui->reg_NAME->text();
    QString sname = ui->reg_SNAME->text();
    QString data = "register,:," + ID + ",:" + password + ",:" + name + ",:" + sname + "\n";
    socket->write(data.toUtf8());
    ui->reg_ID->clear();
    ui->reg_PASSWORD->clear();
    ui->reg_NAME->clear();
    ui->reg_SNAME->clear(); */
}


void MainWindow::on_log_clicked()///kullanıcı girişi yaparken bilgileri servera gönderir
{
    log_dialog = new login_screen(this);
    log_dialog->show();
}

void MainWindow::catch_message()
{
    QTcpSocket *socket_gelen = new QTcpSocket(this);
    socket_gelen = qobject_cast<QTcpSocket *>(sender());
    if (!socket_gelen)
        return;
    QString message = QString::fromUtf8(socket_gelen->readAll());
    ui->messages->append(message);

}
