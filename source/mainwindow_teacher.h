#ifndef MAINWINDOW_TEACHER_H
#define MAINWINDOW_TEACHER_H

#include <QMainWindow>

namespace Ui {
class MainWindow_teacher;
}

class MainWindow_teacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_teacher(QWidget *parent = 0);
    ~MainWindow_teacher();

private:
    Ui::MainWindow_teacher *ui;
};

#endif // MAINWINDOW_TEACHER_H
