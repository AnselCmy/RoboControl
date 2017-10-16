#-------------------------------------------------
#
# Project created by QtCreator 2017-09-16T10:01:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoboControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ACT.cpp \
    Connection.cpp \
    controller.cpp \
    PIDController.cpp \
    MsgParse.cpp \
    math/RotationMatrix.cpp \
    math/RotationMatrix.cpp \
    math/MVTools.cpp

HEADERS  += mainwindow.h \
    controller.h \
    Connection.h \
    ACT.h \
    MsgParse.h \
    PIDController.h \
    Vector3.h \
    math/Pose3D.h \
    math/Matrix2x2.h \
    math/Matrix3x3.h \
    math/MVTools.h \
    math/Range.h \
    math/RobotDimensions.h \
    math/RotationMatrix.h \
    math/Vector2.h \
    math/Vector3.h

FORMS    += mainwindow.ui

RESOURCES += \
    robotpic.qrc
