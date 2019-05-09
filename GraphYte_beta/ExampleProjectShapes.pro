#-------------------------------------------------
#
# Project created by QtCreator 2019-04-21T10:16:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ExampleProjectShapes
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    Shape.cpp \
    Line.cpp \
    Polyline.cpp \
    Polygon.cpp \
    Rectangle.cpp \
    Ellipse.cpp \
    RenderArea.cpp \
    Textbox.cpp \
    CreateShape.cpp

HEADERS += \
        mainwindow.h \
    Shape.h \
    Line.h \
    Polyline.h \
    Vector.h \
    Polygon.h \
    Rectangle.h \
    Ellipse.h \
    RenderArea.h \
    Textbox.h \
    createshape.h \
    shapeinfofunc.h

FORMS += \
        mainwindow.ui \
    CreateShape.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    shapes.txt \
    ShapeListing.txt \
    AreaShapeListing.txt \
    PerimeterShapeListing.txt
