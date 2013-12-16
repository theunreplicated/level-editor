#-------------------------------------------------
#
# Project created by QtCreator 2013-10-24T20:25:46
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sdk
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    gl_viewer_header_bar.cpp \
    gl_viewer_container.cpp \
    gl_viewer_resize_widget.cpp \
    gl_viewer_layout.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    gl_viewer_header_bar.h \
    gl_viewer_container.h \
    gl_viewer_resize_widget.h \
    gl_viewer_layout.h

RESOURCES += \
    icons.qrc
