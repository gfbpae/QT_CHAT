#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login_screen.h"
#include "network.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow , public network
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_send_clicked();

    void on_reg_clicked();

    void on_log_clicked();

    void connection_check();

    void catch_message();


private:
    Ui::MainWindow *ui;
    login_screen *log_dialog;

};
#endif // MAINWINDOW_H
