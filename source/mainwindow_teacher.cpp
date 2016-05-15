#include "mainwindow_teacher.h"
#include "ui_mainwindow_teacher.h"

MainWindow_teacher::MainWindow_teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_teacher)
{
    ui->setupUi(this);
}

MainWindow_teacher::~MainWindow_teacher()
{
    delete ui;
}
