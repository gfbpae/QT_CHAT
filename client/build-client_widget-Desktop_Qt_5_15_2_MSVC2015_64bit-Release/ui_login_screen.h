/********************************************************************************
** Form generated from reading UI file 'login_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_SCREEN_H
#define UI_LOGIN_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login_screen
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *login_ID;
    QLineEdit *login_pass;
    QPushButton *login_ok;
    QPushButton *login_cancel;

    void setupUi(QDialog *login_screen)
    {
        if (login_screen->objectName().isEmpty())
            login_screen->setObjectName(QString::fromUtf8("login_screen"));
        login_screen->resize(253, 158);
        login_screen->setMinimumSize(QSize(253, 158));
        login_screen->setMaximumSize(QSize(253, 158));
        layoutWidget = new QWidget(login_screen);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(22, 22, 201, 105));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        login_ID = new QLineEdit(layoutWidget);
        login_ID->setObjectName(QString::fromUtf8("login_ID"));

        verticalLayout->addWidget(login_ID);

        login_pass = new QLineEdit(layoutWidget);
        login_pass->setObjectName(QString::fromUtf8("login_pass"));
        login_pass->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(login_pass);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 2);

        login_ok = new QPushButton(layoutWidget);
        login_ok->setObjectName(QString::fromUtf8("login_ok"));

        gridLayout_2->addWidget(login_ok, 1, 0, 1, 1);

        login_cancel = new QPushButton(layoutWidget);
        login_cancel->setObjectName(QString::fromUtf8("login_cancel"));

        gridLayout_2->addWidget(login_cancel, 1, 1, 1, 1);


        retranslateUi(login_screen);

        QMetaObject::connectSlotsByName(login_screen);
    } // setupUi

    void retranslateUi(QDialog *login_screen)
    {
        login_screen->setWindowTitle(QCoreApplication::translate("login_screen", "Login", nullptr));
        label->setText(QCoreApplication::translate("login_screen", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("login_screen", "Password", nullptr));
        login_ok->setText(QCoreApplication::translate("login_screen", "OK", nullptr));
        login_cancel->setText(QCoreApplication::translate("login_screen", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login_screen: public Ui_login_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_SCREEN_H
