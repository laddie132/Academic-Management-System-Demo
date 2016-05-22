#ifndef INFORMATION_USER_H
#define INFORMATION_USER_H

#include <QDialog>
#include "user.h"

namespace Ui {
class Information_user;
}

class Information_user : public QDialog
{
    Q_OBJECT

public:
    explicit Information_user(QWidget *parent = 0);
    ~Information_user();

    void setUser_admin(Admin* admin);
    void setUser(User* user);

    void showInfo();

signals:
    void updateUser();

private slots:
    void on_cancel_btn_clicked();

    void on_confirm_btn_clicked();

    void on_comboBox_user_type_currentIndexChanged(int index);

    void on_add_btn_clicked();

    void on_update_btn_clicked();

    void on_del_btn_clicked();

private:
    Ui::Information_user *ui;
    Admin* m_admin;

    User* m_user = NULL;
};

#endif // INFORMATION_USER_H
