#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "environment.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

//private slots:
//    void on_login_button_clicked();

private:
    Ui::Login *ui;
    Envir* m_envir;
};

#endif // LOGIN_H
