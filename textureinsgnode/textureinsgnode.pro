QT += qml quick

HEADERS += fboinsgrenderer.h \
    logorenderer.h
SOURCES += fboinsgrenderer.cpp main.cpp \
    logorenderer.cpp


RESOURCES += textureinsgnode.qrc \
    images.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/scenegraph/textureinsgnode
INSTALLS += target

OTHER_FILES += \
    main.qml
