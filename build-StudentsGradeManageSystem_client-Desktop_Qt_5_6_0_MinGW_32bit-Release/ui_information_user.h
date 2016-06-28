/********************************************************************************
** Form generated from reading UI file 'information_user.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_USER_H
#define UI_INFORMATION_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Information_user
{
public:
    QLabel *label_title;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_user_institude;
    QLineEdit *lineEdit_user_id;
    QLineEdit *lineEdit_user_name;
    QLineEdit *lineEdit_user_institude;
    QLabel *label_user_id;
    QLabel *label_user_name;
    QLabel *label__user_password;
    QLineEdit *lineEdit_user_password;
    QLabel *label_user_class;
    QLineEdit *lineEdit_user_class;
    QLabel *label_user_type;
    QComboBox *comboBox_user_type;
    QLabel *label_course;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_btn;
    QPushButton *update_btn;
    QPushButton *del_btn;
    QPushButton *cancel_btn;
    QTableView *tableView_course_y;
    QTableView *tableView_course_n;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QCommandLinkButton *select_course_btn;
    QCommandLinkButton *cancel_course_btn;

    void setupUi(QDialog *Information_user)
    {
        if (Information_user->objectName().isEmpty())
            Information_user->setObjectName(QStringLiteral("Information_user"));
        Information_user->resize(644, 444);
        Information_user->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        label_title = new QLabel(Information_user);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(250, 20, 171, 41));
        gridLayoutWidget = new QWidget(Information_user);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 70, 491, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_user_institude = new QLabel(gridLayoutWidget);
        label_user_institude->setObjectName(QStringLiteral("label_user_institude"));

        gridLayout->addWidget(label_user_institude, 0, 4, 1, 1);

        lineEdit_user_id = new QLineEdit(gridLayoutWidget);
        lineEdit_user_id->setObjectName(QStringLiteral("lineEdit_user_id"));
        lineEdit_user_id->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_user_id, 0, 1, 1, 1);

        lineEdit_user_name = new QLineEdit(gridLayoutWidget);
        lineEdit_user_name->setObjectName(QStringLiteral("lineEdit_user_name"));
        lineEdit_user_name->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_user_name, 0, 3, 1, 1);

        lineEdit_user_institude = new QLineEdit(gridLayoutWidget);
        lineEdit_user_institude->setObjectName(QStringLiteral("lineEdit_user_institude"));
        lineEdit_user_institude->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_user_institude, 0, 5, 1, 1);

        label_user_id = new QLabel(gridLayoutWidget);
        label_user_id->setObjectName(QStringLiteral("label_user_id"));

        gridLayout->addWidget(label_user_id, 0, 0, 1, 1);

        label_user_name = new QLabel(gridLayoutWidget);
        label_user_name->setObjectName(QStringLiteral("label_user_name"));

        gridLayout->addWidget(label_user_name, 0, 2, 1, 1);

        label__user_password = new QLabel(gridLayoutWidget);
        label__user_password->setObjectName(QStringLiteral("label__user_password"));

        gridLayout->addWidget(label__user_password, 1, 0, 1, 1);

        lineEdit_user_password = new QLineEdit(gridLayoutWidget);
        lineEdit_user_password->setObjectName(QStringLiteral("lineEdit_user_password"));
        lineEdit_user_password->setContextMenuPolicy(Qt::DefaultContextMenu);
        lineEdit_user_password->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        lineEdit_user_password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_user_password, 1, 1, 1, 1);

        label_user_class = new QLabel(gridLayoutWidget);
        label_user_class->setObjectName(QStringLiteral("label_user_class"));
        label_user_class->setEnabled(true);

        gridLayout->addWidget(label_user_class, 1, 2, 1, 1);

        lineEdit_user_class = new QLineEdit(gridLayoutWidget);
        lineEdit_user_class->setObjectName(QStringLiteral("lineEdit_user_class"));
        lineEdit_user_class->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        lineEdit_user_class->setReadOnly(false);

        gridLayout->addWidget(lineEdit_user_class, 1, 3, 1, 1);

        label_user_type = new QLabel(gridLayoutWidget);
        label_user_type->setObjectName(QStringLiteral("label_user_type"));

        gridLayout->addWidget(label_user_type, 1, 4, 1, 1);

        comboBox_user_type = new QComboBox(gridLayoutWidget);
        comboBox_user_type->setObjectName(QStringLiteral("comboBox_user_type"));

        gridLayout->addWidget(comboBox_user_type, 1, 5, 1, 1);

        label_course = new QLabel(Information_user);
        label_course->setObjectName(QStringLiteral("label_course"));
        label_course->setGeometry(QRect(280, 160, 61, 16));
        label_course->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        horizontalLayoutWidget = new QWidget(Information_user);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 380, 320, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        add_btn = new QPushButton(horizontalLayoutWidget);
        add_btn->setObjectName(QStringLiteral("add_btn"));

        horizontalLayout->addWidget(add_btn);

        update_btn = new QPushButton(horizontalLayoutWidget);
        update_btn->setObjectName(QStringLiteral("update_btn"));

        horizontalLayout->addWidget(update_btn);

        del_btn = new QPushButton(horizontalLayoutWidget);
        del_btn->setObjectName(QStringLiteral("del_btn"));

        horizontalLayout->addWidget(del_btn);

        cancel_btn = new QPushButton(horizontalLayoutWidget);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);

        tableView_course_y = new QTableView(Information_user);
        tableView_course_y->setObjectName(QStringLiteral("tableView_course_y"));
        tableView_course_y->setGeometry(QRect(100, 180, 181, 181));
        tableView_course_y->setStyleSheet(QLatin1String("QTableView:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        tableView_course_y->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_y->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_y->horizontalHeader()->setVisible(false);
        tableView_course_y->horizontalHeader()->setDefaultSectionSize(88);
        tableView_course_y->horizontalHeader()->setMinimumSectionSize(20);
        tableView_course_y->horizontalHeader()->setStretchLastSection(false);
        tableView_course_y->verticalHeader()->setVisible(false);
        tableView_course_y->verticalHeader()->setDefaultSectionSize(25);
        tableView_course_n = new QTableView(Information_user);
        tableView_course_n->setObjectName(QStringLiteral("tableView_course_n"));
        tableView_course_n->setGeometry(QRect(340, 180, 181, 181));
        tableView_course_n->setStyleSheet(QLatin1String("QTableView:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        tableView_course_n->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_n->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_n->horizontalHeader()->setVisible(false);
        tableView_course_n->horizontalHeader()->setDefaultSectionSize(88);
        tableView_course_n->horizontalHeader()->setMinimumSectionSize(20);
        tableView_course_n->horizontalHeader()->setStretchLastSection(false);
        tableView_course_n->verticalHeader()->setVisible(false);
        tableView_course_n->verticalHeader()->setDefaultSectionSize(25);
        verticalLayoutWidget_2 = new QWidget(Information_user);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(290, 210, 41, 101));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        select_course_btn = new QCommandLinkButton(verticalLayoutWidget_2);
        select_course_btn->setObjectName(QStringLiteral("select_course_btn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/link_l.png"), QSize(), QIcon::Normal, QIcon::Off);
        select_course_btn->setIcon(icon);

        verticalLayout_2->addWidget(select_course_btn);

        cancel_course_btn = new QCommandLinkButton(verticalLayoutWidget_2);
        cancel_course_btn->setObjectName(QStringLiteral("cancel_course_btn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/link_r.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancel_course_btn->setIcon(icon1);

        verticalLayout_2->addWidget(cancel_course_btn);


        retranslateUi(Information_user);

        QMetaObject::connectSlotsByName(Information_user);
    } // setupUi

    void retranslateUi(QDialog *Information_user)
    {
        Information_user->setWindowTitle(QApplication::translate("Information_user", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        label_title->setText(QApplication::translate("Information_user", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\267\273\345\212\240/\347\274\226\350\276\221\347\224\250\346\210\267\344\277\241\346\201\257</span></p></body></html>", 0));
        label_user_institude->setText(QApplication::translate("Information_user", "\347\224\250\346\210\267\345\255\246\351\231\242", 0));
        label_user_id->setText(QApplication::translate("Information_user", "\347\224\250\346\210\267ID", 0));
        label_user_name->setText(QApplication::translate("Information_user", "\347\224\250\346\210\267\345\247\223\345\220\215", 0));
        label__user_password->setText(QApplication::translate("Information_user", "\347\224\250\346\210\267\345\257\206\347\240\201", 0));
        lineEdit_user_password->setText(QString());
        label_user_class->setText(QApplication::translate("Information_user", "\347\224\250\346\210\267\347\217\255\347\272\247", 0));
        label_user_type->setText(QApplication::translate("Information_user", "\347\224\250\346\210\267\347\261\273\345\236\213", 0));
        comboBox_user_type->clear();
        comboBox_user_type->insertItems(0, QStringList()
         << QApplication::translate("Information_user", "\345\255\246\347\224\237", 0)
         << QApplication::translate("Information_user", "\346\225\231\345\270\210", 0)
         << QApplication::translate("Information_user", "\347\256\241\347\220\206\345\221\230", 0)
        );
        label_course->setText(QApplication::translate("Information_user", "\346\211\200\345\261\236\350\257\276\347\250\213", 0));
        add_btn->setText(QApplication::translate("Information_user", "\346\267\273\345\212\240", 0));
        update_btn->setText(QApplication::translate("Information_user", "\344\277\256\346\224\271", 0));
        del_btn->setText(QApplication::translate("Information_user", "\345\210\240\351\231\244", 0));
        cancel_btn->setText(QApplication::translate("Information_user", "\345\217\226\346\266\210", 0));
        select_course_btn->setText(QString());
        cancel_course_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Information_user: public Ui_Information_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_USER_H
