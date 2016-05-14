#include "login.h"
#include "ui_login.h"
#include "environment.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

/*void Login::on_login_button_clicked()
{
    std::string usename = ui->User_ID_text->text();
    std::string password = ui->User_password_text->text();
    User* user = m_envir->checkUser(username, password);
    if(user != NULL){

    }
}
*/
