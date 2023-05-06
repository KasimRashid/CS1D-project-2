QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    adminpage.cpp \
    americanteamssortedbyteamname.cpp \
    displaywindow.cpp \
    main.cpp \
    mainwindow.cpp \
    menuselectwindow.cpp \
    nationalteamsortdbystadiumname.cpp \
    parktypologysorted.cpp \
    teaminfowindow.cpp \
    teamnamesortedbystadium.cpp \
    teamnamesortedbyteamname.cpp \

HEADERS += \
    adminlogin.h \
    adminpage.h \
    americanteamssortedbyteamname.h \
    displaywindow.h \
    mainwindow.h \
    menuselectwindow.h \
    nationalteamsortdbystadiumname.h \
    parktypologysorted.h \
    teaminfowindow.h \
    teamnamesortedbystadium.h \
    teamnamesortedbyteamname.h \

FORMS += \
    adminlogin.ui \
    adminpage.ui \
    americanteamssortedbyteamname.ui \
    displaywindow.ui \
    mainwindow.ui \
    menuselectwindow.ui \
    nationalteamsortdbystadiumname.ui \
    parktypologysorted.ui \
    teaminfowindow.ui \
    teamnamesortedbystadium.ui \
    teamnamesortedbyteamname.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
