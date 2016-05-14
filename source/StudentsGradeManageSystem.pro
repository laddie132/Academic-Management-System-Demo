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
        mainwindow.cpp \
    course.cpp \
    user.cpp \
    environment.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    course.h \
    user.h \
    environment.h \
    login.h \
    include.h

FORMS    += mainwindow.ui \
    login.ui

CONFIG += c++11

DISTFILES +=
