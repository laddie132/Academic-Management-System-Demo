#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T19:10:41
#
#-------------------------------------------------

QT  += core gui\
    network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentsGradeManageSystem
TEMPLATE = app


SOURCES += main.cpp\
    course.cpp \
    user.cpp \
    environment.cpp \
    login.cpp \
    mainwindow_student.cpp \
    mainwindow_teacher.cpp \
    envir_widget.cpp \
    config.cpp \
    fun.cpp \
    convey.cpp

HEADERS  += \
    environment.h \
    login.h \
    include.h \
    mainwindow_student.h \
    mainwindow_teacher.h \
    envir_widget.h \
    fun.h \
    convey.h \
    model_struct.h

FORMS    += \
    login.ui \
    mainwindow_student.ui \
    mainwindow_teacher.ui

CONFIG += c++11

DISTFILES +=

RESOURCES += \
    resourse.qrc

RC_FILE = icon.rc 
