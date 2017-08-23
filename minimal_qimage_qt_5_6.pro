QT += core gui widgets
TARGET = minimal_qimage_qt_5_6
TEMPLATE = app

SOURCES += main.cpp \
           main_window.cpp \
           rendering_area.cpp

HEADERS  += main_window.h \
            rendering_area.h

FORMS    += main_window.ui \
            rendering_area.ui
