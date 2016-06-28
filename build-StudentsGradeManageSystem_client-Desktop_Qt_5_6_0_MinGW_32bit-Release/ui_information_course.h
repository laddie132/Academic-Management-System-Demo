/********************************************************************************
** Form generated from reading UI file 'information_course.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATION_COURSE_H
#define UI_INFORMATION_COURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_Information_course
{
public:
    QLabel *label_titile;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_course_id;
    QLineEdit *lineEdit_course_id;
    QLineEdit *lineEdit_course_name;
    QLineEdit *lineEdit_course_credit;
    QLabel *label_course_num;
    QLabel *label_course_credit;
    QLabel *label_course_capicity;
    QLabel *label_course_type;
    QComboBox *comboBox_type;
    QLineEdit *lineEdit_course_capicity;
    QLabel *label_course_name;
    QLabel *label_course_student;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_btn;
    QPushButton *update_btn;
    QPushButton *del_btn;
    QPushButton *cancel_btn;
    QLabel *label_student;
    QLabel *label_teacher;
    QCheckBox *checkBox_start_course;
    QComboBox *comboBox_teacher;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *select_student_btn;
    QCommandLinkButton *cancel_student_btn;
    QTableView *tableView_student_y;
    QTableView *tableView_student_n;
    QLabel *label_teacher_2;
    QLabel *label_teacher_name;
    QLabel *label;

    void setupUi(QDialog *Information_course)
    {
        if (Information_course->objectName().isEmpty())
            Information_course->setObjectName(QStringLiteral("Information_course"));
        Information_course->resize(702, 471);
        Information_course->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        label_titile = new QLabel(Information_course);
        label_titile->setObjectName(QStringLiteral("label_titile"));
        label_titile->setGeometry(QRect(270, 20, 171, 41));
        gridLayoutWidget = new QWidget(Information_course);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 70, 521, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_course_id = new QLabel(gridLayoutWidget);
        label_course_id->setObjectName(QStringLiteral("label_course_id"));
        label_course_id->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label_course_id, 0, 0, 1, 1);

        lineEdit_course_id = new QLineEdit(gridLayoutWidget);
        lineEdit_course_id->setObjectName(QStringLiteral("lineEdit_course_id"));
        lineEdit_course_id->setEnabled(true);
        lineEdit_course_id->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_course_id, 0, 1, 1, 1);

        lineEdit_course_name = new QLineEdit(gridLayoutWidget);
        lineEdit_course_name->setObjectName(QStringLiteral("lineEdit_course_name"));
        lineEdit_course_name->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_course_name, 0, 3, 1, 1);

        lineEdit_course_credit = new QLineEdit(gridLayoutWidget);
        lineEdit_course_credit->setObjectName(QStringLiteral("lineEdit_course_credit"));
        lineEdit_course_credit->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_course_credit, 0, 5, 1, 1);

        label_course_num = new QLabel(gridLayoutWidget);
        label_course_num->setObjectName(QStringLiteral("label_course_num"));

        gridLayout->addWidget(label_course_num, 1, 0, 1, 1);

        label_course_credit = new QLabel(gridLayoutWidget);
        label_course_credit->setObjectName(QStringLiteral("label_course_credit"));

        gridLayout->addWidget(label_course_credit, 0, 4, 1, 1);

        label_course_capicity = new QLabel(gridLayoutWidget);
        label_course_capicity->setObjectName(QStringLiteral("label_course_capicity"));

        gridLayout->addWidget(label_course_capicity, 1, 2, 1, 1);

        label_course_type = new QLabel(gridLayoutWidget);
        label_course_type->setObjectName(QStringLiteral("label_course_type"));

        gridLayout->addWidget(label_course_type, 1, 4, 1, 1);

        comboBox_type = new QComboBox(gridLayoutWidget);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));

        gridLayout->addWidget(comboBox_type, 1, 5, 1, 1);

        lineEdit_course_capicity = new QLineEdit(gridLayoutWidget);
        lineEdit_course_capicity->setObjectName(QStringLiteral("lineEdit_course_capicity"));
        lineEdit_course_capicity->setStyleSheet(QLatin1String("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85); \n"
"    border-radius: 3px; \n"
"    background: white;   \n"
"    selection-background-color: green; \n"
"}\n"
" \n"
"QLineEdit:hover {\n"
"    border: 1px solid blue; \n"
"}"));

        gridLayout->addWidget(lineEdit_course_capicity, 1, 3, 1, 1);

        label_course_name = new QLabel(gridLayoutWidget);
        label_course_name->setObjectName(QStringLiteral("label_course_name"));

        gridLayout->addWidget(label_course_name, 0, 2, 1, 1);

        label_course_student = new QLabel(gridLayoutWidget);
        label_course_student->setObjectName(QStringLiteral("label_course_student"));

        gridLayout->addWidget(label_course_student, 1, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(Information_course);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(340, 400, 320, 51));
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

        label_student = new QLabel(Information_course);
        label_student->setObjectName(QStringLiteral("label_student"));
        label_student->setGeometry(QRect(260, 160, 71, 31));
        label_student->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        label_teacher = new QLabel(Information_course);
        label_teacher->setObjectName(QStringLiteral("label_teacher"));
        label_teacher->setGeometry(QRect(570, 160, 71, 31));
        label_teacher->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        checkBox_start_course = new QCheckBox(Information_course);
        checkBox_start_course->setObjectName(QStringLiteral("checkBox_start_course"));
        checkBox_start_course->setGeometry(QRect(540, 330, 131, 21));
        checkBox_start_course->setChecked(false);
        comboBox_teacher = new QComboBox(Information_course);
        comboBox_teacher->setObjectName(QStringLiteral("comboBox_teacher"));
        comboBox_teacher->setGeometry(QRect(570, 210, 91, 22));
        verticalLayoutWidget = new QWidget(Information_course);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 230, 41, 91));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        select_student_btn = new QCommandLinkButton(verticalLayoutWidget);
        select_student_btn->setObjectName(QStringLiteral("select_student_btn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/link_l.png"), QSize(), QIcon::Normal, QIcon::Off);
        select_student_btn->setIcon(icon);

        verticalLayout->addWidget(select_student_btn);

        cancel_student_btn = new QCommandLinkButton(verticalLayoutWidget);
        cancel_student_btn->setObjectName(QStringLiteral("cancel_student_btn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/link_r.png"), QSize(), QIcon::Normal, QIcon::Off);
        cancel_student_btn->setIcon(icon1);

        verticalLayout->addWidget(cancel_student_btn);

        tableView_student_y = new QTableView(Information_course);
        tableView_student_y->setObjectName(QStringLiteral("tableView_student_y"));
        tableView_student_y->setGeometry(QRect(80, 200, 181, 181));
        tableView_student_y->setStyleSheet(QLatin1String("QTableView:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        tableView_student_y->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_student_y->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_student_y->horizontalHeader()->setVisible(false);
        tableView_student_y->horizontalHeader()->setDefaultSectionSize(88);
        tableView_student_y->horizontalHeader()->setStretchLastSection(false);
        tableView_student_y->verticalHeader()->setVisible(false);
        tableView_student_y->verticalHeader()->setDefaultSectionSize(25);
        tableView_student_n = new QTableView(Information_course);
        tableView_student_n->setObjectName(QStringLiteral("tableView_student_n"));
        tableView_student_n->setGeometry(QRect(320, 200, 181, 181));
        tableView_student_n->setStyleSheet(QLatin1String("QTableView:hover {\n"
"    border: 1px solid blue; \n"
"}"));
        tableView_student_n->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_student_n->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_student_n->horizontalHeader()->setVisible(false);
        tableView_student_n->horizontalHeader()->setDefaultSectionSize(88);
        tableView_student_n->horizontalHeader()->setStretchLastSection(false);
        tableView_student_n->verticalHeader()->setVisible(false);
        tableView_student_n->verticalHeader()->setDefaultSectionSize(25);
        label_teacher_2 = new QLabel(Information_course);
        label_teacher_2->setObjectName(QStringLiteral("label_teacher_2"));
        label_teacher_2->setGeometry(QRect(530, 240, 61, 31));
        label_teacher_name = new QLabel(Information_course);
        label_teacher_name->setObjectName(QStringLiteral("label_teacher_name"));
        label_teacher_name->setGeometry(QRect(590, 240, 61, 31));
        label = new QLabel(Information_course);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 210, 21, 21));
#ifndef QT_NO_SHORTCUT
        label_course_id->setBuddy(lineEdit_course_id);
        label_course_credit->setBuddy(lineEdit_course_credit);
        label_course_capicity->setBuddy(lineEdit_course_capicity);
        label_course_type->setBuddy(comboBox_type);
        label_course_name->setBuddy(lineEdit_course_name);
#endif // QT_NO_SHORTCUT

        retranslateUi(Information_course);

        QMetaObject::connectSlotsByName(Information_course);
    } // setupUi

    void retranslateUi(QDialog *Information_course)
    {
        Information_course->setWindowTitle(QApplication::translate("Information_course", "\350\257\276\347\250\213\344\277\241\346\201\257", 0));
        label_titile->setText(QApplication::translate("Information_course", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\267\273\345\212\240/\347\274\226\350\276\221\350\257\276\347\250\213\344\277\241\346\201\257</span></p></body></html>", 0));
        label_course_id->setText(QApplication::translate("Information_course", "\350\257\276\347\250\213\347\274\226\345\217\267", 0));
        label_course_num->setText(QApplication::translate("Information_course", "\350\257\276\347\250\213\344\272\272\346\225\260", 0));
        label_course_credit->setText(QApplication::translate("Information_course", "\350\257\276\347\250\213\345\255\246\345\210\206", 0));
        label_course_capicity->setText(QApplication::translate("Information_course", "\350\257\276\347\250\213\345\256\271\351\207\217", 0));
        label_course_type->setText(QApplication::translate("Information_course", "\350\257\276\347\250\213\347\261\273\345\236\213", 0));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("Information_course", "\345\277\205\344\277\256", 0)
         << QApplication::translate("Information_course", "\351\200\211\344\277\256", 0)
        );
        label_course_name->setText(QApplication::translate("Information_course", "\350\257\276\347\250\213\345\220\215\347\247\260", 0));
        label_course_student->setText(QString());
        add_btn->setText(QApplication::translate("Information_course", "\346\267\273\345\212\240", 0));
        update_btn->setText(QApplication::translate("Information_course", "\344\277\256\346\224\271", 0));
        del_btn->setText(QApplication::translate("Information_course", "\345\210\240\351\231\244", 0));
        cancel_btn->setText(QApplication::translate("Information_course", "\345\217\226\346\266\210", 0));
        label_student->setText(QApplication::translate("Information_course", "\351\200\211\346\213\251\345\255\246\347\224\237", 0));
        label_teacher->setText(QApplication::translate("Information_course", "\351\200\211\346\213\251\346\225\231\345\270\210", 0));
        checkBox_start_course->setText(QApplication::translate("Information_course", "\351\200\211\344\277\256\350\257\276\345\274\200\345\220\257\351\200\211\350\257\276", 0));
        select_student_btn->setText(QString());
        cancel_student_btn->setText(QString());
        label_teacher_2->setText(QApplication::translate("Information_course", "\346\225\231\345\270\210\345\220\215\357\274\232", 0));
        label_teacher_name->setText(QString());
        label->setText(QApplication::translate("Information_course", "ID:", 0));
    } // retranslateUi

};

namespace Ui {
    class Information_course: public Ui_Information_course {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATION_COURSE_H
