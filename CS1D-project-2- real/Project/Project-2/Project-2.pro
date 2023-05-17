QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    adminmaintence.cpp \
    americanteamssortedbyteamname.cpp \
    custominput.cpp \
    customtripwindow.cpp \
    dateopenedsorted.cpp \
    dfs.cpp \
    displaywindow.cpp \
    greatestdistancecenter.cpp \
    main.cpp \
    mainwindow.cpp \
    marlinspark.cpp \
    menuselectwindow.cpp \
    mst.cpp \
    nationalteamsortdbystadiumname.cpp \
    parktypologysorted.cpp \
    rooftypesorted.cpp \
    seatingcapacitysorted.cpp \
    smallestdistancecenter.cpp \
    summarypage.cpp \
    teaminfowindow.cpp \
    teamnamesortedbystadium.cpp \
    teamnamesortedbyteamname.cpp \
    travelplan.cpp

HEADERS += \
    adminlogin.h \
    adminmaintence.h \
    americanteamssortedbyteamname.h \
    custominput.h \
    customtripwindow.h \
    dateopenedsorted.h \
    dfs.h \
    displaywindow.h \
    greatestdistancecenter.h \
    mainwindow.h \
    marlinspark.h \
    menuselectwindow.h \
    mst.h \
    nationalteamsortdbystadiumname.h \
    parktypologysorted.h \
    rooftypesorted.h \
    seatingcapacitysorted.h \
    smallestdistancecenter.h \
    summarypage.h \
    teaminfowindow.h \
    teamnamesortedbystadium.h \
    teamnamesortedbyteamname.h \
    travelplan.h

FORMS += \
    adminlogin.ui \
    adminmaintence.ui \
    americanteamssortedbyteamname.ui \
    custominput.ui \
    customtripwindow.ui \
    dateopenedsorted.ui \
    dfs.ui \
    displaywindow.ui \
    greatestdistancecenter.ui \
    mainwindow.ui \
    marlinspark.ui \
    menuselectwindow.ui \
    mst.ui \
    nationalteamsortdbystadiumname.ui \
    parktypologysorted.ui \
    rooftypesorted.ui \
    seatingcapacitysorted.ui \
    smallestdistancecenter.ui \
    summarypage.ui \
    teaminfowindow.ui \
    teamnamesortedbystadium.ui \
    teamnamesortedbyteamname.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
