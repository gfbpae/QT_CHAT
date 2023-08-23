#include "login_screen.h"
#include "ui_login_screen.h"

login_screen::login_screen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_screen)
{
    ui->setupUi(this);
}

login_screen::~login_screen()
{
    delete ui;
}

void login_screen::on_login_ok_clicked()
{
    QString ID = ui->login_ID->text();
    QString password = ui->login_pass->text();
    data = "login,:," + ID + ",:" + password + "\n";
    ui->login_ID->clear();
    ui->login_pass->clear();
    message_sender(data);
    //get_socket()->write(data.toUtf8());
}

void login_screen::on_login_cancel_clicked()
{

}

