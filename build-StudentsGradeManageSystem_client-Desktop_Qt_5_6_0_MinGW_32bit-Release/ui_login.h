/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *login_btn;
    QPushButton *cancel_btn;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *passowrd_edit;
    QLineEdit *username_edit;
    QLabel *wrong_label;
    QLabel *hello_label;
    QFrame *frame;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(525, 311);
        Login->setStyleSheet(QString::fromUtf8("font: 12pt \"\347\255\211\347\272\277\";\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(159, 209, 255, 255), stop:1 rgba(255, 255, 255, 255));"));
        horizontalLayoutWidget = new QWidget(Login);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 230, 174, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        login_btn = new QPushButton(horizontalLayoutWidget);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        login_btn->setCheckable(true);
        login_btn->setChecked(false);

        horizontalLayout->addWidget(login_btn);

        cancel_btn = new QPushButton(horizontalLayoutWidget);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        cancel_btn->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));

        horizontalLayout->addWidget(cancel_btn);

        gridLayoutWidget = new QWidget(Login);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(270, 110, 201, 101));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        username_label = new QLabel(gridLayoutWidget);
        username_label->setObjectName(QStringLiteral("username_label"));

        gridLayout->addWidget(username_label, 0, 0, 1, 1);

        password_label = new QLabel(gridLayoutWidget);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setFrameShape(QFrame::NoFrame);
        password_label->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(password_label, 1, 0, 1, 1);

        passowrd_edit = new QLineEdit(gridLayoutWidget);
        passowrd_edit->setObjectName(QStringLiteral("passowrd_edit"));
        passowrd_edit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        passowrd_edit->setFrame(true);
        passowrd_edit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passowrd_edit, 1, 1, 1, 1);

        username_edit = new QLineEdit(gridLayoutWidget);
        username_edit->setObjectName(QStringLiteral("username_edit"));
        username_edit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(username_edit, 0, 1, 1, 1);

        wrong_label = new QLabel(Login);
        wrong_label->setObjectName(QStringLiteral("wrong_label"));
        wrong_label->setGeometry(QRect(290, 80, 161, 21));
        wrong_label->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        hello_label = new QLabel(Login);
        hello_label->setObjectName(QStringLiteral("hello_label"));
        hello_label->setGeometry(QRect(210, 20, 211, 41));
        hello_label->setStyleSheet(QStringLiteral(""));
        frame = new QFrame(Login);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 30, 121, 111));
        frame->setStyleSheet(QStringLiteral("border-image: url(:/image/bupt.jpg);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
#ifndef QT_NO_SHORTCUT
        username_label->setBuddy(username_edit);
        password_label->setBuddy(passowrd_edit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(username_edit, passowrd_edit);
        QWidget::setTabOrder(passowrd_edit, login_btn);
        QWidget::setTabOrder(login_btn, cancel_btn);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        login_btn->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        cancel_btn->setText(QApplication::translate("Login", "\345\217\226\346\266\210", 0));
        username_label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215:", 0));
        password_label->setText(QApplication::translate("Login", "\345\257\206\347\240\201:", 0));
        wrong_label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215\346\210\226\345\257\206\347\240\201\351\224\231\350\257\257\357\274\201", 0));
        hello_label->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\254\242\350\277\216\346\235\245\345\210\260\345\214\227\351\202\256\346\225\231\345\212\241\347\263\273\347\273\237</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
