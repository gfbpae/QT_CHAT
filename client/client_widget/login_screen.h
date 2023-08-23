#ifndef LOGIN_SCREEN_H
#define LOGIN_SCREEN_H

#include <QDialog>
#include "network.h"

namespace Ui {
class login_screen;
}

class login_screen : public QDialog , public network
{
    Q_OBJECT

public:
    explicit login_screen(QWidget *parent = nullptr);
    ~login_screen();
    QString data;

private slots:
    void on_login_ok_clicked();

    void on_login_cancel_clicked();

private:
    Ui::login_screen *ui;
};

#endif // LOGIN_SCREEN_H
