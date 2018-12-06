#-------------------------------------------------
#
# Project created by QtCreator 2018-12-06T10:32:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = edgeFocusing
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
           mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:/install/opencv-3.4.1/include
INCLUDEPATH += C:/install/opencv-3.4.1/include/opencv2

DEPENDPATH  += C:/install/opencv-3.4.1/x64/vc14/lib

LIBS += -LC:/install/opencv-3.4.1/x64/vc14/lib

win32:CONFIG(release, debug|release):    LIBS += -lopencv_highgui341    -lopencv_imgproc341     -lopencv_ximgproc341    -lopencv_imgcodecs341       -lopencv_core341
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_highgui341d   -lopencv_imgproc341d    -lopencv_ximgproc341d   -lopencv_imgcodecs341d      -lopencv_core341d
win32:CONFIG(release, debug|release):    LIBS += -lopencv_calib3d341    -lopencv_ccalib341      -lopencv_features2d341  -lopencv_xfeatures2d341
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_calib3d341d   -lopencv_ccalib341d     -lopencv_features2d341d -lopencv_xfeatures2d341d
win32:CONFIG(release, debug|release):    LIBS += -lopencv_flann341      -lopencv_videoio341     -lopencv_video341       -lopencv_optflow341
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_flann341d     -lopencv_videoio341d    -lopencv_video341d      -lopencv_optflow341d
win32:CONFIG(release, debug|release):    LIBS += -lopencv_viz341        -lopencv_superres341    -lopencv_aruco341
else:win32:CONFIG(debug, debug|release): LIBS += -lopencv_viz341d       -lopencv_superres341d   -lopencv_aruco341d
