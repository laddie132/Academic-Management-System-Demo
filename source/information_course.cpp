#include "information_course.h"
#include "ui_information_course.h"

Information_course::Information_course(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Information_course)
{
    ui->setupUi(this);
}

Information_course::~Information_course()
{
    delete ui;
}
