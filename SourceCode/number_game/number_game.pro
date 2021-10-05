QT       += core gui
QT       += core gui multimedia
#添加了multimedia后才能找到QMediaPlayer头文件

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Game_2048.cpp \
    author_widget.cpp \
    dialog.cpp \
    dialog_bar.cpp \
    dialog_hammer.cpp \
    dialog_operationmode.cpp \
    dialog_stop.cpp \
    game_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    operation_widget.cpp \
    sort_widget.cpp

HEADERS += \
    Game_2048.h \
    author_widget.h \
    dialog.h \
    dialog_bar.h \
    dialog_hammer.h \
    dialog_operationmode.h \
    dialog_stop.h \
    game_widget.h \
    mainwindow.h \
    operation_widget.h \
    sort_widget.h

FORMS += \
    author_widget.ui \
    dialog.ui \
    dialog_bar.ui \
    dialog_hammer.ui \
    dialog_operationmode.ui \
    dialog_stop.ui \
    game_widget.ui \
    mainwindow.ui \
    operation_widget.ui \
    sort_widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES += \
    recourse.qrc
