/********************************************************************************
** Form generated from reading UI file 'mainwindow_admin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_ADMIN_H
#define UI_MAINWINDOW_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_MainWindow_admin
{
public:
    QAction *action_quit;
    QAction *action_login;
    QAction *action_course_o;
    QAction *action_course_e;
    QAction *action_student_d;
    QAction *action_teachet_d;
    QAction *action_admin_d;
    QAction *action_course_add;
    QAction *action_student_add;
    QAction *action_teacher_add;
    QAction *action_user_add;
    QAction *action_about;
    QAction *action_help;
    QAction *action_start_course;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_admin;
    QWidget *tab_course_o;
    QTableView *tableView_course_o;
    QWidget *tab_course_e;
    QTableView *tableView_course_e;
    QWidget *tab_student;
    QTableView *tableView_student;
    QWidget *tab_teacher;
    QTableView *tableView_teacher;
    QWidget *tab_admin;
    QTableView *tableView_admin;
    QLabel *label;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_id;
    QLabel *label_name;
    QLabel *label_institude;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_user_btn;
    QPushButton *add_course_btn;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menu_main;
    QMenu *menu_course;
    QMenu *menu_user;
    QMenu *menu_help;
    QMenu *menu_function;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_admin)
    {
        if (MainWindow_admin->objectName().isEmpty())
            MainWindow_admin->setObjectName(QStringLiteral("MainWindow_admin"));
        MainWindow_admin->resize(800, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow_admin->sizePolicy().hasHeightForWidth());
        MainWindow_admin->setSizePolicy(sizePolicy);
        MainWindow_admin->setMouseTracking(false);
        MainWindow_admin->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        action_quit = new QAction(MainWindow_admin);
        action_quit->setObjectName(QStringLiteral("action_quit"));
        action_login = new QAction(MainWindow_admin);
        action_login->setObjectName(QStringLiteral("action_login"));
        action_course_o = new QAction(MainWindow_admin);
        action_course_o->setObjectName(QStringLiteral("action_course_o"));
        action_course_e = new QAction(MainWindow_admin);
        action_course_e->setObjectName(QStringLiteral("action_course_e"));
        action_student_d = new QAction(MainWindow_admin);
        action_student_d->setObjectName(QStringLiteral("action_student_d"));
        action_teachet_d = new QAction(MainWindow_admin);
        action_teachet_d->setObjectName(QStringLiteral("action_teachet_d"));
        action_admin_d = new QAction(MainWindow_admin);
        action_admin_d->setObjectName(QStringLiteral("action_admin_d"));
        action_course_add = new QAction(MainWindow_admin);
        action_course_add->setObjectName(QStringLiteral("action_course_add"));
        action_student_add = new QAction(MainWindow_admin);
        action_student_add->setObjectName(QStringLiteral("action_student_add"));
        action_teacher_add = new QAction(MainWindow_admin);
        action_teacher_add->setObjectName(QStringLiteral("action_teacher_add"));
        action_user_add = new QAction(MainWindow_admin);
        action_user_add->setObjectName(QStringLiteral("action_user_add"));
        action_about = new QAction(MainWindow_admin);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_help = new QAction(MainWindow_admin);
        action_help->setObjectName(QStringLiteral("action_help"));
        action_start_course = new QAction(MainWindow_admin);
        action_start_course->setObjectName(QStringLiteral("action_start_course"));
        centralwidget = new QWidget(MainWindow_admin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(150, 0, 651, 461));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget_admin = new QTabWidget(gridLayoutWidget);
        tabWidget_admin->setObjectName(QStringLiteral("tabWidget_admin"));
        tabWidget_admin->setUsesScrollButtons(false);
        tab_course_o = new QWidget();
        tab_course_o->setObjectName(QStringLiteral("tab_course_o"));
        sizePolicy1.setHeightForWidth(tab_course_o->sizePolicy().hasHeightForWidth());
        tab_course_o->setSizePolicy(sizePolicy1);
        tableView_course_o = new QTableView(tab_course_o);
        tableView_course_o->setObjectName(QStringLiteral("tableView_course_o"));
        tableView_course_o->setGeometry(QRect(0, 0, 651, 431));
        sizePolicy.setHeightForWidth(tableView_course_o->sizePolicy().hasHeightForWidth());
        tableView_course_o->setSizePolicy(sizePolicy);
        tableView_course_o->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_o->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_o->horizontalHeader()->setDefaultSectionSize(105);
        tableView_course_o->verticalHeader()->setVisible(false);
        tabWidget_admin->addTab(tab_course_o, QString());
        tab_course_e = new QWidget();
        tab_course_e->setObjectName(QStringLiteral("tab_course_e"));
        sizePolicy1.setHeightForWidth(tab_course_e->sizePolicy().hasHeightForWidth());
        tab_course_e->setSizePolicy(sizePolicy1);
        tableView_course_e = new QTableView(tab_course_e);
        tableView_course_e->setObjectName(QStringLiteral("tableView_course_e"));
        tableView_course_e->setGeometry(QRect(0, 0, 651, 431));
        tableView_course_e->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_e->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_e->horizontalHeader()->setDefaultSectionSize(105);
        tableView_course_e->verticalHeader()->setVisible(false);
        tabWidget_admin->addTab(tab_course_e, QString());
        tab_student = new QWidget();
        tab_student->setObjectName(QStringLiteral("tab_student"));
        tableView_student = new QTableView(tab_student);
        tableView_student->setObjectName(QStringLiteral("tableView_student"));
        tableView_student->setGeometry(QRect(0, 0, 651, 431));
        tableView_student->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_student->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_student->horizontalHeader()->setDefaultSectionSize(105);
        tableView_student->horizontalHeader()->setStretchLastSection(false);
        tableView_student->verticalHeader()->setVisible(false);
        tabWidget_admin->addTab(tab_student, QString());
        tab_teacher = new QWidget();
        tab_teacher->setObjectName(QStringLiteral("tab_teacher"));
        tableView_teacher = new QTableView(tab_teacher);
        tableView_teacher->setObjectName(QStringLiteral("tableView_teacher"));
        tableView_teacher->setGeometry(QRect(0, 0, 651, 431));
        tableView_teacher->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_teacher->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_teacher->horizontalHeader()->setDefaultSectionSize(105);
        tableView_teacher->horizontalHeader()->setStretchLastSection(false);
        tableView_teacher->verticalHeader()->setVisible(false);
        tabWidget_admin->addTab(tab_teacher, QString());
        tab_admin = new QWidget();
        tab_admin->setObjectName(QStringLiteral("tab_admin"));
        tableView_admin = new QTableView(tab_admin);
        tableView_admin->setObjectName(QStringLiteral("tableView_admin"));
        tableView_admin->setGeometry(QRect(0, 0, 651, 431));
        tableView_admin->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_admin->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_admin->horizontalHeader()->setDefaultSectionSize(105);
        tableView_admin->horizontalHeader()->setStretchLastSection(false);
        tableView_admin->verticalHeader()->setVisible(false);
        tabWidget_admin->addTab(tab_admin, QString());

        gridLayout->addWidget(tabWidget_admin, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 81, 31));
        label->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 200, 141, 131));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_3->addWidget(label_4, 2, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_id = new QLabel(gridLayoutWidget_3);
        label_id->setObjectName(QStringLiteral("label_id"));
        label_id->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_3->addWidget(label_id, 0, 1, 1, 2);

        label_name = new QLabel(gridLayoutWidget_3);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_3->addWidget(label_name, 1, 1, 1, 2);

        label_institude = new QLabel(gridLayoutWidget_3);
        label_institude->setObjectName(QStringLiteral("label_institude"));
        label_institude->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout_3->addWidget(label_institude, 2, 1, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 1, 1, 1);

        add_user_btn = new QPushButton(centralwidget);
        add_user_btn->setObjectName(QStringLiteral("add_user_btn"));
        add_user_btn->setGeometry(QRect(30, 340, 81, 31));
        add_user_btn->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        add_course_btn = new QPushButton(centralwidget);
        add_course_btn->setObjectName(QStringLiteral("add_course_btn"));
        add_course_btn->setGeometry(QRect(30, 390, 81, 31));
        add_course_btn->setStyleSheet(QStringLiteral("border:2px groove gray;border-radius:10px;padding:2px 4px;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 80, 111, 91));
        frame->setStyleSheet(QStringLiteral("image: url(:/image/photo.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow_admin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_admin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menu_main = new QMenu(menubar);
        menu_main->setObjectName(QStringLiteral("menu_main"));
        menu_course = new QMenu(menubar);
        menu_course->setObjectName(QStringLiteral("menu_course"));
        menu_user = new QMenu(menubar);
        menu_user->setObjectName(QStringLiteral("menu_user"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QStringLiteral("menu_help"));
        menu_function = new QMenu(menubar);
        menu_function->setObjectName(QStringLiteral("menu_function"));
        MainWindow_admin->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_admin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_admin->setStatusBar(statusbar);

        menubar->addAction(menu_main->menuAction());
        menubar->addAction(menu_course->menuAction());
        menubar->addAction(menu_user->menuAction());
        menubar->addAction(menu_function->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_main->addAction(action_login);
        menu_main->addAction(action_quit);
        menu_main->addSeparator();
        menu_course->addAction(action_course_o);
        menu_course->addAction(action_course_e);
        menu_course->addSeparator();
        menu_course->addAction(action_course_add);
        menu_user->addAction(action_student_d);
        menu_user->addAction(action_teachet_d);
        menu_user->addAction(action_admin_d);
        menu_user->addSeparator();
        menu_user->addAction(action_user_add);
        menu_help->addAction(action_about);
        menu_help->addAction(action_help);
        menu_function->addAction(action_start_course);

        retranslateUi(MainWindow_admin);

        tabWidget_admin->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow_admin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_admin)
    {
        MainWindow_admin->setWindowTitle(QApplication::translate("MainWindow_admin", "\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267", 0));
        action_quit->setText(QApplication::translate("MainWindow_admin", "\351\200\200\345\207\272", 0));
        action_login->setText(QApplication::translate("MainWindow_admin", "\351\207\215\346\226\260\347\231\273\345\275\225", 0));
        action_course_o->setText(QApplication::translate("MainWindow_admin", "\346\237\245\347\234\213\345\277\205\344\277\256\350\257\276\347\250\213", 0));
        action_course_e->setText(QApplication::translate("MainWindow_admin", "\346\237\245\347\234\213\351\200\211\344\277\256\350\257\276\347\250\213", 0));
        action_student_d->setText(QApplication::translate("MainWindow_admin", "\346\237\245\347\234\213\345\255\246\347\224\237\347\224\250\346\210\267", 0));
        action_teachet_d->setText(QApplication::translate("MainWindow_admin", "\346\237\245\347\234\213\346\225\231\345\270\210\347\224\250\346\210\267", 0));
        action_admin_d->setText(QApplication::translate("MainWindow_admin", "\346\237\245\347\234\213\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267", 0));
        action_course_add->setText(QApplication::translate("MainWindow_admin", "\346\267\273\345\212\240\350\257\276\347\250\213", 0));
        action_student_add->setText(QApplication::translate("MainWindow_admin", "\346\267\273\345\212\240\345\255\246\347\224\237\347\224\250\346\210\267", 0));
        action_teacher_add->setText(QApplication::translate("MainWindow_admin", "\346\267\273\345\212\240\346\225\231\345\270\210\347\224\250\346\210\267", 0));
        action_user_add->setText(QApplication::translate("MainWindow_admin", "\346\267\273\345\212\240\347\224\250\346\210\267", 0));
        action_about->setText(QApplication::translate("MainWindow_admin", "\345\205\263\344\272\216", 0));
        action_help->setText(QApplication::translate("MainWindow_admin", "\345\270\256\345\212\251\346\226\207\346\241\243", 0));
        action_start_course->setText(QApplication::translate("MainWindow_admin", "\345\274\200\346\224\276\351\200\211\350\257\276", 0));
        tabWidget_admin->setTabText(tabWidget_admin->indexOf(tab_course_o), QApplication::translate("MainWindow_admin", "\345\277\205\344\277\256\350\257\276\345\210\227\350\241\250", 0));
        tabWidget_admin->setTabText(tabWidget_admin->indexOf(tab_course_e), QApplication::translate("MainWindow_admin", "\351\200\211\344\277\256\350\257\276\345\210\227\350\241\250", 0));
        tabWidget_admin->setTabText(tabWidget_admin->indexOf(tab_student), QApplication::translate("MainWindow_admin", "\345\255\246\347\224\237\345\210\227\350\241\250", 0));
        tabWidget_admin->setTabText(tabWidget_admin->indexOf(tab_teacher), QApplication::translate("MainWindow_admin", "\346\225\231\345\270\210\345\210\227\350\241\250", 0));
        tabWidget_admin->setTabText(tabWidget_admin->indexOf(tab_admin), QApplication::translate("MainWindow_admin", "\347\256\241\347\220\206\345\221\230\345\210\227\350\241\250", 0));
        label->setText(QApplication::translate("MainWindow_admin", "<html><head/><body><p><span style=\" font-size:12pt;\">\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("MainWindow_admin", "\345\255\246\351\231\242\357\274\232", 0));
        label_3->setText(QApplication::translate("MainWindow_admin", "\345\247\223\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow_admin", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_id->setText(QString());
        label_name->setText(QString());
        label_institude->setText(QString());
        add_user_btn->setText(QApplication::translate("MainWindow_admin", "\346\267\273\345\212\240\347\224\250\346\210\267", 0));
        add_course_btn->setText(QApplication::translate("MainWindow_admin", "\346\267\273\345\212\240\350\257\276\347\250\213", 0));
        menu_main->setTitle(QApplication::translate("MainWindow_admin", "\350\217\234\345\215\225", 0));
        menu_course->setTitle(QApplication::translate("MainWindow_admin", "\350\257\276\347\250\213", 0));
        menu_user->setTitle(QApplication::translate("MainWindow_admin", "\347\224\250\346\210\267", 0));
        menu_help->setTitle(QApplication::translate("MainWindow_admin", "\345\270\256\345\212\251", 0));
        menu_function->setTitle(QApplication::translate("MainWindow_admin", "\345\212\237\350\203\275", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_admin: public Ui_MainWindow_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_ADMIN_H
