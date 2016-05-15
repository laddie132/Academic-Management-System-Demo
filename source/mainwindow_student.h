#ifndef MAINWINDOW_STUDENT_H
#define MAINWINDOW_STUDENT_H

#include <QMainWindow>

namespace Ui {
class MainWindow_student;
}

class MainWindow_student : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_student(QWidget *parent = 0);
    ~MainWindow_student();

private:
    Ui::MainWindow_student *ui;
};

#endif // MAINWINDOW_STUDENT_H
