#ifndef INFORMATION_USER_H
#define INFORMATION_USER_H

#include <QDialog>

namespace Ui {
class Information_user;
}

class Information_user : public QDialog
{
    Q_OBJECT

public:
    explicit Information_user(QWidget *parent = 0);
    ~Information_user();

private:
    Ui::Information_user *ui;
};

#endif // INFORMATION_USER_H
