QT += core
QT -= gui

TARGET = TNewYearTree
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

DESTDIR = ../bin

TEMPLATE = app

HEADERS += \
    event/tclose_event.h \
    event/thide_event.h \
    event/tkey_event.h \
    event/tmouse_click_event.h \
    event/tmouse_double_click_event.h \
    event/tmouse_event.h \
    event/tmouse_key_event.h \
    event/tmouse_move_event.h \
    event/tmouse_wheel_event.h \
    event/tmove_event.h \
    event/tresize_event.h \
    painter/tabstract_color.h \
    painter/tabstract_painter.h \
    painter/tabstract_painter_device.h \
    painter/tabstract_pen.h \
    painter/tcolor.h \
    painter/tcolor_private.h \
    painter/tobject_private.h \
    painter/tpainter.h \
    painter/tpainter_device.h \
    painter/tpainter_device_private.h \
    painter/tpainter_private.h \
    painter/tpen.h \
    painter/tpen_private.h \
    painter/ncurses_painter.h \
    painter/ncurses_painter_device.h \
    core/new_year_core.h \
    core/tree/new_year_tree.h \
    core/snow.h

SOURCES += main.cpp \
    event/tclose_event.cpp \
    event/thide_event.cpp \
    event/tkey_event.cpp \
    event/tmouse_click_event.cpp \
    event/tmouse_double_click_event.cpp \
    event/tmouse_event.cpp \
    event/tmouse_key_event.cpp \
    event/tmouse_move_event.cpp \
    event/tmouse_wheel_event.cpp \
    event/tmove_event.cpp \
    event/tresize_event.cpp \
    painter/tabstract_color.cpp \
    painter/tabstract_painter.cpp \
    painter/tabstract_painter_device.cpp \
    painter/tabstract_pen.cpp \
    painter/tcolor.cpp \
    painter/tcolor_private.cpp \
    painter/tobject_private.cpp \
    painter/tpainter.cpp \
    painter/tpainter_device.cpp \
    painter/tpainter_device_private.cpp \
    painter/tpainter_private.cpp \
    painter/tpen.cpp \
    painter/tpen_private.cpp \
    painter/ncurses_painter.cpp \
    painter/ncurses_painter_device.cpp \
    core/new_year_core.cpp \
    core/tree/new_year_tree.cpp \
    core/snow.cpp


LIBS += -lcurses
