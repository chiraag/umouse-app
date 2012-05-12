TEMPLATE = app
TARGET = daedalus 

QT        += core gui 

HEADERS   += daedalus.h
SOURCES   += main.cpp \
    daedalus.cpp
FORMS     += daedalus.ui    
RESOURCES +=

include(../qextserialport-1.2beta1/src/qextserialport.pri)
