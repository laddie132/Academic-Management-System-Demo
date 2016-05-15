#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T19:10:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentsGradeManageSystem
TEMPLATE = app


SOURCES += main.cpp\
    course.cpp \
    user.cpp \
    environment.cpp \
    login.cpp \
    mainwindow_admin.cpp \
    mainwindow_student.cpp \
    mainwindow_teacher.cpp

HEADERS  += \
    course.h \
    user.h \
    environment.h \
    login.h \
    include.h \
    mainwindow_admin.h \
    mainwindow_student.h \
    mainwindow_teacher.h

FORMS    += \
    login.ui \
    mainwindow_admin.ui \
    mainwindow_student.ui \
    mainwindow_teacher.ui

CONFIG += c++11

DISTFILES +=

RESOURCES += \
    resourse.qrc