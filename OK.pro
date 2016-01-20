#-------------------------------------------------
#
# Project created by Abdullah EMİROĞLU 2016-01-03T13:37:02
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OK
TEMPLATE = app


SOURCES += main.cpp\
        giris.cpp \
    anasayfa.cpp \
    okumakayit.cpp \
    kisikayit.cpp \
    kayitduzenle.cpp

HEADERS  += giris.h \
    anasayfa.h \
    okumakayit.h \
    kisikayit.h \
    kayitduzenle.h

FORMS    += giris.ui \
    anasayfa.ui \
    okumakayit.ui \
    kisikayit.ui \
    kayitduzenle.ui
