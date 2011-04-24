# -------------------------------------------------
# Project created by QtCreator 2011-04-23T15:47:52
# -------------------------------------------------
QT += network
TARGET = Chat
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    tcpsocket.cpp \
    chatserver.cpp \
    chatclient.cpp \
    messageparser.cpp
HEADERS += mainwindow.h \
    tcpsocket.h \
    chatserver.h \
    chatclient.h \
    config.h \
    messageparser.h
FORMS += mainwindow.ui
