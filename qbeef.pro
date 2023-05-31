QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    detailedreportdockwidget.cpp \
    domitem.cpp \
    dommodel.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    detailedreportdockwidget.h \
    domitem.h \
    dommodel.h \
    mainwindow.h

FORMS += \
    detailedreportdockwidget.ui \
    mainwindow.ui

TRANSLATIONS += \
    qbeef_en_US.ts \
    qbeef_la.ts

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    qbeef_la.ts
