QT += core
QT -= gui

CONFIG += c++11

TARGET = StudentGradeManageSystem_server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    config.cpp \
    course.cpp \
    environment.cpp \
    user.cpp

DISTFILES += \
    StudentGradeManageSystem_server.pro.user

HEADERS += \
    config.h \
    course.h \
    environment.h \
    user.h \
    include.h
