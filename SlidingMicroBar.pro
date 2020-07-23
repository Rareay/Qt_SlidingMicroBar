CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(slidingmicrobarplugin)
TEMPLATE    = lib

HEADERS     = slidingmicrobarplugin.h \
    slidingmicrobar.h
SOURCES     = slidingmicrobarplugin.cpp \
    slidingmicrobar.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(slidingmicrobar.pri)

FORMS += \
    slidingmicrobar.ui
