QT += core gui opengl widgets
CONFIG += c++11

win32:LIBS += -lopengl32


TARGET = gl_sim

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_qt_gl.cc \
    glwidget.cc \
    vue_opengl.cc \
    glcylindre.cc \
    glsphere.cc
    

HEADERS += \
    glwidget.h \
    vue_opengl.h \
    vertex_shader.h \
    ../general/dessinable.h \
    ../general/supportadessin.h \
    ../general/accelerateur.h \
    glcylindre.h \
    glsphere.h
    ../general/elements.h

RESOURCES += \
    resource.qrc

DISTFILES +=
