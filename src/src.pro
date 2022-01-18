QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gui/main.cpp \
    gui/difficulty_menu/difficultymenu.cpp \
    gui/main_menu/mainmenu.cpp \
    gui/settings_menu/settingsmenu.cpp \
    gui/preview_window/previewwindow.cpp \
    gui/endgame_window/endgamewindow.cpp \
    gui/statistics_window/statisticswindow.cpp \
    gui/about_window/aboutwindow.cpp \
    game_table/gametable.cpp


HEADERS += \
    gui/difficulty_menu/difficultymenu.h \
    gui/main_menu/mainmenu.h \
    gui/settings_menu/settingsmenu.h \
    gui/preview_window/previewwindow.h \
    gui/endgame_window/endgamewindow.h \
    gui/statistics_window/statisticswindow.h \
    gui/about_window/aboutwindow.h \
    game_table/gametable.h

FORMS += \
    gui/main_menu/mainmenu.ui \
    gui/difficulty_menu/difficultymenu.ui \
    gui/settings_menu/settingsmenu.ui \
    gui/preview_window/previewwindow.ui \
    gui/endgame_window/endgamewindow.ui \
    gui/statistics_window/statisticswindow.ui \
    gui/about_window/aboutwindow.ui \
    game_table/gametable.ui

RC_ICONS += ../matchmatch_icon.ico \

RESOURCES += resources.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
