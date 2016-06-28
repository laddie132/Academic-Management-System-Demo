/********************************************************************************
** Form generated from reading UI file 'mainwindow_student.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_STUDENT_H
#define UI_MAINWINDOW_STUDENT_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow_student
{
public:
    QAction *action_login;
    QAction *action_quit;
    QAction *action_course_o;
    QAction *action_course_e;
    QAction *action_course_start;
    QAction *action_password;
    QAction *action_about;
    QAction *action_help;
    QWidget *centralwidget;
    QTabWidget *tabWidget_student;
    QWidget *tab_course_o;
    QTableView *tableView_course_o;
    QWidget *tab_course_e;
    QTableView *tableView_course_e;
    QWidget *tab_student;
    QTableView *tableView_course_s;
    QLabel *label_title;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_class;
    QLabel *label_institude;
    QLabel *label_name;
    QLabel *label_id;
    QFrame *frame;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow_student)
    {
        if (MainWindow_student->objectName().isEmpty())
            MainWindow_student->setObjectName(QStringLiteral("MainWindow_student"));
        MainWindow_student->resize(800, 500);
        MainWindow_student->setStyleSheet(QString::fromUtf8("font: 25 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        action_login = new QAction(MainWindow_student);
        action_login->setObjectName(QStringLiteral("action_login"));
        action_quit = new QAction(MainWindow_student);
        action_quit->setObjectName(QStringLiteral("action_quit"));
        action_course_o = new QAction(MainWindow_student);
        action_course_o->setObjectName(QStringLiteral("action_course_o"));
        action_course_e = new QAction(MainWindow_student);
        action_course_e->setObjectName(QStringLiteral("action_course_e"));
        action_course_start = new QAction(MainWindow_student);
        action_course_start->setObjectName(QStringLiteral("action_course_start"));
        action_password = new QAction(MainWindow_student);
        action_password->setObjectName(QStringLiteral("action_password"));
        action_about = new QAction(MainWindow_student);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_help = new QAction(MainWindow_student);
        action_help->setObjectName(QStringLiteral("action_help"));
        centralwidget = new QWidget(MainWindow_student);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget_student = new QTabWidget(centralwidget);
        tabWidget_student->setObjectName(QStringLiteral("tabWidget_student"));
        tabWidget_student->setGeometry(QRect(160, 0, 651, 461));
        tab_course_o = new QWidget();
        tab_course_o->setObjectName(QStringLiteral("tab_course_o"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tab_course_o->sizePolicy().hasHeightForWidth());
        tab_course_o->setSizePolicy(sizePolicy);
        tableView_course_o = new QTableView(tab_course_o);
        tableView_course_o->setObjectName(QStringLiteral("tableView_course_o"));
        tableView_course_o->setGeometry(QRect(0, 0, 651, 431));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableView_course_o->sizePolicy().hasHeightForWidth());
        tableView_course_o->setSizePolicy(sizePolicy1);
        tableView_course_o->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_o->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_o->horizontalHeader()->setDefaultSectionSize(90);
        tableView_course_o->horizontalHeader()->setStretchLastSection(false);
        tableView_course_o->verticalHeader()->setVisible(false);
        tabWidget_student->addTab(tab_course_o, QString());
        tab_course_e = new QWidget();
        tab_course_e->setObjectName(QStringLiteral("tab_course_e"));
        sizePolicy.setHeightForWidth(tab_course_e->sizePolicy().hasHeightForWidth());
        tab_course_e->setSizePolicy(sizePolicy);
        tableView_course_e = new QTableView(tab_course_e);
        tableView_course_e->setObjectName(QStringLiteral("tableView_course_e"));
        tableView_course_e->setGeometry(QRect(0, 0, 651, 431));
        tableView_course_e->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_e->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_e->horizontalHeader()->setDefaultSectionSize(90);
        tableView_course_e->horizontalHeader()->setStretchLastSection(false);
        tableView_course_e->verticalHeader()->setVisible(false);
        tabWidget_student->addTab(tab_course_e, QString());
        tab_student = new QWidget();
        tab_student->setObjectName(QStringLiteral("tab_student"));
        tableView_course_s = new QTableView(tab_student);
        tableView_course_s->setObjectName(QStringLiteral("tableView_course_s"));
        tableView_course_s->setGeometry(QRect(0, 0, 651, 431));
        tableView_course_s->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView_course_s->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView_course_s->horizontalHeader()->setDefaultSectionSize(105);
        tableView_course_s->verticalHeader()->setVisible(false);
        tabWidget_student->addTab(tab_student, QString());
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setGeometry(QRect(30, 20, 111, 31));
        label_title->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 220, 141, 191));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 4, 1, 1, 1);

        label_class = new QLabel(gridLayoutWidget);
        label_class->setObjectName(QStringLiteral("label_class"));
        label_class->setStyleSheet(QString::fromUtf8("font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";"));

        gridLayout->addWidget(label_class, 3, 1, 1, 2);

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

        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, 80, 111, 101));
        frame->setStyleSheet(QStringLiteral("image: url(:/image/photo.png);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        MainWindow_student->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow_student);
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
        MainWindow_student->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow_student);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow_student->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(action_login);
        menu->addAction(action_quit);
        menu_2->addAction(action_course_o);
        menu_2->addAction(action_course_e);
        menu_3->addAction(action_course_start);
        menu_3->addAction(action_password);
        menu_4->addAction(action_about);
        menu_4->addAction(action_help);

        retranslateUi(MainWindow_student);

        tabWidget_student->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow_student);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow_student)
    {
        MainWindow_student->setWindowTitle(QApplication::translate("MainWindow_student", "\345\255\246\347\224\237\347\224\250\346\210\267", 0));
        action_login->setText(QApplication::translate("MainWindow_student", "\351\207\215\346\226\260\347\231\273\345\275\225", 0));
        action_quit->setText(QApplication::translate("MainWindow_student", "\351\200\200\345\207\272", 0));
        action_course_o->setText(QApplication::translate("MainWindow_student", "\346\237\245\347\234\213\345\277\205\344\277\256\350\257\276", 0));
        action_course_e->setText(QApplication::translate("MainWindow_student", "\346\237\245\347\234\213\345\267\262\351\200\211\350\257\276\347\250\213", 0));
        action_course_start->setText(QApplication::translate("MainWindow_student", "\351\200\211\350\257\276", 0));
        action_password->setText(QApplication::translate("MainWindow_student", "\344\277\256\346\224\271\345\257\206\347\240\201", 0));
        action_about->setText(QApplication::translate("MainWindow_student", "\345\205\263\344\272\216", 0));
        action_help->setText(QApplication::translate("MainWindow_student", "\345\270\256\345\212\251\346\226\207\346\241\243", 0));
        tabWidget_student->setTabText(tabWidget_student->indexOf(tab_course_o), QApplication::translate("MainWindow_student", "\345\277\205\344\277\256\350\257\276\347\250\213\345\210\227\350\241\250", 0));
        tabWidget_student->setTabText(tabWidget_student->indexOf(tab_course_e), QApplication::translate("MainWindow_student", "\345\267\262\351\200\211\350\257\276\347\250\213\345\210\227\350\241\250", 0));
        tabWidget_student->setTabText(tabWidget_student->indexOf(tab_student), QApplication::translate("MainWindow_student", "\351\200\211\350\257\276\345\210\227\350\241\250", 0));
        label_title->setText(QApplication::translate("MainWindow_student", "<html><head/><body><p><span style=\" font-size:12pt;\">\345\275\223\345\211\215\345\255\246\347\224\237\344\277\241\346\201\257</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("MainWindow_student", "\345\247\223\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("MainWindow_student", "\345\255\246\345\217\267\357\274\232", 0));
        label_4->setText(QApplication::translate("MainWindow_student", "\345\255\246\351\231\242\357\274\232", 0));
        label->setText(QApplication::translate("MainWindow_student", "\347\217\255\347\272\247\357\274\232", 0));
        label_class->setText(QString());
        label_institude->setText(QString());
        label_name->setText(QString());
        label_id->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow_student", "\350\217\234\345\215\225", 0));
        menu_2->setTitle(QApplication::translate("MainWindow_student", "\350\257\276\347\250\213", 0));
        menu_3->setTitle(QApplication::translate("MainWindow_student", "\345\212\237\350\203\275", 0));
        menu_4->setTitle(QApplication::translate("MainWindow_student", "\345\270\256\345\212\251", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_student: public Ui_MainWindow_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_STUDENT_H
