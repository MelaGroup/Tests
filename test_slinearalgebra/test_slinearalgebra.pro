#-------------------------------------------------
#
# Project created by QtCreator 2017-11-30T19:20:27
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_test_slinearalgebra
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_test_slinearalgebra.cpp \
    ../../SLib/slinearalgebra.cpp \
    ../random_for_tests.cpp

DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../../SLib/slinearalgebra.h \
    ../random_for_tests.h
