TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

SUBDIRS += \
    f13-v14.pro

DISTFILES += \
    f13-v14.pro.user \
    f13-v14.pro.user.e230f08 \
    Graph.pro.user \
    .gitignore

HEADERS += \
    edge.h \
    graph.h \
    graphadt.h \
    node.h \
    priorityqueue.h
