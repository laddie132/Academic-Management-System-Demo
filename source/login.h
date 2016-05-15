#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "environment.h"
#include "user.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

    void setEnvir(Envir* envir);        //设置系统运行环境

    User* getCurrentUser();             //获取当前登录用户

private slots:
    void on_login_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::Login *ui;
    Envir* m_envir;
    User* m_user;
};

#endif // LOGIN_H
