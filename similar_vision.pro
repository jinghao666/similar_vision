#-------------------------------------------------
#
# Project created by QtCreator 2016-06-27T15:15:00
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

TARGET = similar_vision
TEMPLATE = app

INCLUDEPATH += ui
#INCLUDEPATH += ../

win32{
RC_FILE = pics/similar_vision.rc

include(../pri/boost.pri)
include(../pri/cv_dev.pri)

}

include(../pri/qwt.pri)

linux-g++{

LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs -lopencv_video -lopencv_videoio
LIBS += -L/usr/local/lib -lopencv_img_hash

}

SOURCES += main.cpp\
        mainwindow.cpp \
    ui/paint_custom_words.cpp \
    model/folder_model.cpp \
    core/scan_folder.cpp \
    core/pics_find_img_hash.cpp \
    model/duplicate_img_model.cpp \
    ui/basic_setting_dialog.cpp \
    ui/advance_setting_dialog.cpp \
    ui/single_bar_plot.cpp \
    ui/duplicate_img_table_view.cpp

HEADERS  += mainwindow.hpp \
    ui/paint_custom_words.hpp \
    model/folder_model.hpp \
    core/scan_folder.hpp \
    core/pics_find_img_hash.hpp \
    core/vp_tree.hpp \
    model/duplicate_img_model.hpp \
    ui/basic_setting_dialog.hpp \
    ui/advance_setting_dialog.hpp \
    ui/single_bar_plot.hpp \
    ui/duplicate_img_table_view.hpp

FORMS    += mainwindow.ui \
    ui/basic_setting_dialog.ui \
    ui/advance_setting_dialog.ui

RESOURCES += \
    pics.qrc
