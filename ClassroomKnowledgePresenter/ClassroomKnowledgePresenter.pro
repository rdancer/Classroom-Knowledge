# -------------------------------------------------
# Project created by QtCreator 2010-05-14T01:51:27
# -------------------------------------------------
QT += network \
    opengl \
    sql \
    script \
    scripttools \
    svg \
    webkit \
    xml \
    xmlpatterns \
    phonon \
    multimedia \
    testlib \
    #dbus

TARGET = ClassroomKnowledgePresenter
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    quiz.cpp \
    question.cpp
HEADERS += mainwindow.h \
    quiz.h \
    question.h
FORMS += mainwindow.ui
RESOURCES += classroomknowledgepresenter.qrc
CONFIG += release
