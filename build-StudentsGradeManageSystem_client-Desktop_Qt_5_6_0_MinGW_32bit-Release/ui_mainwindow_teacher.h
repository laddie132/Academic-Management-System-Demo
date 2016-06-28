/********************************************************************************
** Form generated from reading UI file 'mainwindow_teacher.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_TEACHER_H
#define UI_MAINWINDOW_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_teacher
{
public:
    QAction *action_login;
    QAction *action_quit;
    QAction *action_course;
    QAction *action_course_e;
    QAction *action_password;
    QAction *action_about;
    QAction *action_help;
    QAction *action;
    QAction *action_set_grade;
    QWidget *centralwidget;
    QTabWidget *tabWidget_teacher;
    QWidget *tab_course;
    QTableView *tableView_course;
    QWidget *tab_student_grade;
    QComboBox *comboBox_course;
    QLabel *label_5;
    QTableView *tableView_student;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_course_id;
    QLabel *label_course_credit;
    QLabel *label_7;
    QLabel *label_course_name;
    QLabel *label_9;
    QLabel *label_course_type;
    QPushButton *confirm_btn;
    QPushButton *cancel_btn;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_institude;
    QLabel *label_name;
    QLabel *label_id;
    QPushButton *set_grade_btn;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_teacher)
    {
        if (MainWindow_teacher->objectName().isEmpty())
            MainWindow_teacher->setObjectName(QStringLiteral("MainWindow_teacher"));
        MainWindow_teacher->resize(800, 500);
        MainWindow_teacher->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        action_login = new QAction(MainWindow_teacher);
        action_login->setObjectName(QStringLiteral("action_login"));
        action_quit = new QAction(MainWindow_teacher);
        action_quit->setObjectName(QStringLiteral("action_quit"));
        action_course = new QAction(MainWindow_teacher);
        action_course->setObjectName(QStringLiteral("action_course"));
        action_course_e = new QAction(MainWindow_teacher);
        action_course_e->setObjectName(QStringLiteral("action_course_e"));
        action_password = new QAction(MainWindow_teacher);
        action_password->setObjectName(QStringLiteral("action_password"));
        action_about = new QAction(MainWindow_teacher);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_help = new QAction(MainWindow_teacher);
        action_help->setObjectName(QStringLiteral("action_help"));
        action = new QAction(MainWindow_teacher);
        action->setObjectName(QStringLiteral("action"));
        action_set_grade = new QAction(MainWindow_teacher);
        action_set_grade->setObjectName(QStringLiteral("action_set_grade"));
        centralwidget = new QWidget(MainWindow_teacher);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget_teacher = new QTabWidget(centralwidget);
        tabWidget_teacher->setObjectName(QStringLiteral("tabWidget_teacher"));
        tabWidget_teacher->setGeometry(QRect(140, 0, 651, 461));
        tabWidget_teacher->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        tab_course = new QWidget();
        tab_course->setObjectName(QStringLiteral("tab_course"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab_course->sizePolicy().hasHeightForWidth());
        tab_course->setSizePolicy(sizePolicy);
        tableView_course = new QTableView(tab_course);
        tableView_course->setObjectName(QStringLiteral("tableView_course"));
        tableView_course->setGeometry(QRect(0, 0, 661, 461));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView_course->sizePolicy().hasHeightForWidth());
        tableView_course->setSizePolicy(sizePolicy1);
        tableView_course->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course->horizontalHeader()->setDefaultSectionSize(105);
        tableView_course->verticalHeader()->setVisible(false);
        tabWidget_teacher->addTab(tab_course, QString());
        tab_student_grade = new QWidget();
        tab_student_grade->setObjectName(QStringLiteral("tab_student_grade"));
        comboBox_course = new QComboBox(tab_student_grade);
        comboBox_course->setObjectName(QStringLiteral("comboBox_course"));
        comboBox_course->setGeometry(QRect(110, 30, 101, 22));
        label_5 = new QLabel(tab_student_grade);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 30, 71, 21));
        tableView_student = new QTableView(tab_student_grade);
        tableView_student->setObjectName(QStringLiteral("tableView_student"));
        tableView_student->setGeometry(QRect(60, 120, 511, 211));
        tableView_student->verticalHeader()->setVisible(false);
        gridLayoutWidget_2 = new QWidget(tab_student_grade);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(310, 20, 221, 88));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(gridLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        label_course_id = new QLabel(gridLayoutWidget_2);
        label_course_id->setObjectName(QStringLiteral("label_course_id"));
        label_course_id->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_course_id, 0, 1, 1, 1);

        label_course_credit = new QLabel(gridLayoutWidget_2);
        label_course_credit->setObjectName(QStringLiteral("label_course_credit"));
        label_course_credit->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_course_credit, 2, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        label_course_name = new QLabel(gridLayoutWidget_2);
        label_course_name->setObjectName(QStringLiteral("label_course_name"));
        label_course_name->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_course_name, 0, 3, 1, 1);

        label_9 = new QLabel(gridLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_9, 2, 2, 1, 1);

        label_course_type = new QLabel(gridLayoutWidget_2);
        label_course_type->setObjectName(QStringLiteral("label_course_type"));
        label_course_type->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_2->addWidget(label_course_type, 2, 3, 1, 1);

        confirm_btn = new QPushButton(tab_student_grade);
        confirm_btn->setObjectName(QStringLiteral("confirm_btn"));
        confirm_btn->setGeometry(QRect(380, 360, 81, 31));
        confirm_btn->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        cancel_btn = new QPushButton(tab_student_grade);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        cancel_btn->setGeometry(QRect(480, 360, 81, 31));
        cancel_btn->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        tabWidget_teacher->addTab(tab_student_grade, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 71, 21));
        label->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 220, 131, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        label_institude = new QLabel(gridLayoutWidget);
        label_institude->setObjectName(QStringLiteral("label_institude"));
        label_institude->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_institude, 2, 1, 1, 2);

        label_name = new QLabel(gridLayoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_name, 1, 1, 1, 2);

        label_id = new QLabel(gridLayoutWidget);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_id, 0, 1, 1, 2);

        set_grade_btn = new QPushButton(centralwidget);
        set_grade_btn->setObjectName(QStringLiteral("set_grade_btn"));
        set_grade_btn->setGeometry(QRect(30, 380, 81, 31));
        set_grade_btn->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 100, 111, 91));
        frame->setStyleSheet(QStringLiteral("image: url(:/image/photo.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow_teacher->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_teacher);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        MainWindow_teacher->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_teacher);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_teacher->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(action_login);
        menu->addAction(action_quit);
        menu_2->addAction(action_course);
        menu_3->addAction(action_password);
        menu_3->addAction(action_set_grade);
        menu_4->addAction(action_about);
        menu_4->addAction(action_help);

        retranslateUi(MainWindow_teacher);

        tabWidget_teacher->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow_teacher);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_teacher)
    {
        MainWindow_teacher->setWindowTitle(QApplication::translate("MainWindow_teacher", "\346\225\231\345\270\210\347\224\250\346\210\267", 0));
        action_login->setText(QApplication::translate("MainWindow_teacher", "\351\207\215\346\226\260\347\231\273\345\275\225", 0));
        action_quit->setText(QApplication::translate("MainWindow_teacher", "\351\200\200\345\207\272", 0));
        action_course->setText(QApplication::translate("MainWindow_teacher", "\346\237\245\347\234\213\350\257\276\347\250\213", 0));
        action_course_e->setText(QApplication::translate("MainWindow_teacher", "\346\237\245\347\234\213\351\200\211\344\277\256\350\257\276\347\250\213", 0));
        action_password->setText(QApplication::translate("MainWindow_teacher", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        action_about->setText(QApplication::translate("MainWindow_teacher", "\345\205\263\344\272\216", 0));
        action_help->setText(QApplication::translate("MainWindow_teacher", "\345\270\256\345\212\251\346\226\207\346\241\243", 0));
        action->setText(QApplication::translate("MainWindow_teacher", "\346\237\245\347\234\213\351\200\211\350\257\276\345\210\227\350\241\250", 0));
        action_set_grade->setText(QApplication::translate("MainWindow_teacher", "\350\256\276\347\275\256\345\255\246\347\224\237\346\210\220\347\273\251", 0));
        tabWidget_teacher->setTabText(tabWidget_teacher->indexOf(tab_course), QApplication::translate("MainWindow_teacher", "\346\211\200\345\261\236\350\257\276\347\250\213\345\210\227\350\241\250", 0));
        label_5->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><span style=\" font-size:11pt;\">\351\200\211\346\213\251\350\257\276\347\250\213\357\274\232</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><span style=\" font-size:11pt;\">ID:</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\255\246\345\210\206:</span></p></body></html>", 0));
        label_course_id->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><br/></p></body></html>", 0));
        label_course_credit->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><br/></p></body></html>", 0));
        label_7->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><span style=\" font-size:11pt;\">\345\220\215\347\247\260:</span></p></body></html>", 0));
        label_course_name->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><br/></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><span style=\" font-size:11pt;\">\347\261\273\345\236\213:</span></p></body></html>", 0));
        label_course_type->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><br/></p></body></html>", 0));
        confirm_btn->setText(QApplication::translate("MainWindow_teacher", "\347\241\256\350\256\244\344\277\256\346\224\271", 0));
        cancel_btn->setText(QApplication::translate("MainWindow_teacher", "\345\217\226\346\266\210\344\277\256\346\224\271", 0));
        tabWidget_teacher->setTabText(tabWidget_teacher->indexOf(tab_student_grade), QApplication::translate("MainWindow_teacher", "\345\255\246\347\224\237\346\210\220\347\273\251", 0));
        label->setText(QApplication::translate("MainWindow_teacher", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\225\231\345\270\210\344\277\241\346\201\257</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow_teacher", "\345\247\223\345\220\215\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow_teacher", "\345\255\246\351\231\242\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow_teacher", "\345\267\245\345\217\267\357\274\232", 0));
        label_institude->setText(QString());
        label_name->setText(QString());
        label_id->setText(QString());
        set_grade_btn->setText(QApplication::translate("MainWindow_teacher", "\350\256\276\347\275\256\346\210\220\347\273\251", 0));
        menu->setTitle(QApplication::translate("MainWindow_teacher", "\350\217\234\345\215\225", 0));
        menu_2->setTitle(QApplication::translate("MainWindow_teacher", "\350\257\276\347\250\213", 0));
        menu_3->setTitle(QApplication::translate("MainWindow_teacher", "\345\212\237\350\203\275", 0));
        menu_4->setTitle(QApplication::translate("MainWindow_teacher", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_teacher: public Ui_MainWindow_teacher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_TEACHER_H
