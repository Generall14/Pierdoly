TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    src/Life.cpp \
    src/SimpleLife.cpp

HEADERS += \
    src/Life.hpp \
    src/SimpleLife.hpp

SUBDIRS += \
    Life.pro
