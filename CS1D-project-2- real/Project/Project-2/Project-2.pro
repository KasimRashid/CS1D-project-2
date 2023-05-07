QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    adminmaintence.cpp \
    adminpage.cpp \
    americanteamssortedbyteamname.cpp \
    dateopenedsorted.cpp \
    displaywindow.cpp \
    greatestdistancecenter.cpp \
    main.cpp \
    mainwindow.cpp \
    menuselectwindow.cpp \
    nationalteamsortdbystadiumname.cpp \
    parktypologysorted.cpp \
    rooftypesorted.cpp \
    seatingcapacitysorted.cpp \
    smallestdistancecenter.cpp \
    teaminfowindow.cpp \
    teamnamesortedbystadium.cpp \
    teamnamesortedbyteamname.cpp \

HEADERS += \
    adminlogin.h \
    adminmaintence.h \
    adminpage.h \
    americanteamssortedbyteamname.h \
    dateopenedsorted.h \
    displaywindow.h \
    greatestdistancecenter.h \
    mainwindow.h \
    menuselectwindow.h \
    nationalteamsortdbystadiumname.h \
    parktypologysorted.h \
    rooftypesorted.h \
    seatingcapacitysorted.h \
    smallestdistancecenter.h \
    teaminfowindow.h \
    teamnamesortedbystadium.h \
    teamnamesortedbyteamname.h \

FORMS += \
    adminlogin.ui \
    adminmaintence.ui \
    adminpage.ui \
    americanteamssortedbyteamname.ui \
    dateopenedsorted.ui \
    displaywindow.ui \
    greatestdistancecenter.ui \
    mainwindow.ui \
    menuselectwindow.ui \
    nationalteamsortdbystadiumname.ui \
    parktypologysorted.ui \
    rooftypesorted.ui \
    seatingcapacitysorted.ui \
    smallestdistancecenter.ui \
    teaminfowindow.ui \
    teamnamesortedbystadium.ui \
    teamnamesortedbyteamname.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
