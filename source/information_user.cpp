#include "information_user.h"
#include "ui_information_user.h"

Information_user::Information_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information_user)
{
    ui->setupUi(this);
}

Information_user::~Information_user()
{
    delete ui;
}
