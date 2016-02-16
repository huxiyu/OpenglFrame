TEMPLATE = app

QT += qml quick quickwidgets

SOURCES += main.cpp \
    cpp/OglContainer.cpp \
    cpp/OglRenderer.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    cpp/OglContainer.h \
    cpp/OglRenderer.h
