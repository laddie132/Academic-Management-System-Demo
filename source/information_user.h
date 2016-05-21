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

    void setUser(Admin* admin);

signals:
    void addUser();

private slots:
    void on_cancel_btn_clicked();

    void on_confirm_btn_clicked();

    void on_comboBox_user_type_currentIndexChanged(int index);

private:
    Ui::Information_user *ui;
    Admin* m_user;
};

#endif // INFORMATION_USER_H
