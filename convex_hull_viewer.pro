QT += core gui widgets
TARGET = minimal_qimage_qt_5_6
TEMPLATE = app

CONFIG += c++14

SOURCES += main.cpp \
           main_window.cpp \
           rendering_area.cpp \
    coordinate_system_painter.cpp

HEADERS  += main_window.h \
            rendering_area.h \
    qpoint_generator.h \
    coordinate_system_painter.h

FORMS    += main_window.ui \
            rendering_area.ui
