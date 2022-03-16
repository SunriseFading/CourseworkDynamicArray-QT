QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddirector.cpp \
    addguard.cpp \
    addteacher.cpp \
    delemployee.cpp \
    editdirector.cpp \
    editguard.cpp \
    editteacher.cpp \
    main.cpp \
    mainwindow.cpp \
    mycode.cpp \
    search_employee.cpp \
    tabshow.cpp \
    takeput.cpp

HEADERS += \
    adddirector.h \
    addguard.h \
    addteacher.h \
    delemployee.h \
    editdirector.h \
    editguard.h \
    editteacher.h \
    mainwindow.h \
    mycode.h \
    search_employee.h \
    tabshow.h \
    takeput.h

FORMS += \
    adddirector.ui \
    addguard.ui \
    addteacher.ui \
    delemployee.ui \
    editdirector.ui \
    editguard.ui \
    editteacher.ui \
    mainwindow.ui \
    search_employee.ui \
    tabshow.ui \
    takeput.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
