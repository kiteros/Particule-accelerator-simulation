CONFIG += c++11

TARGET = text_sim

LIBS += -L../general -lgeneral
PRE_TARGETDEPS += ../general/libgeneral.a

INCLUDEPATH = ../general

SOURCES += \
    main_text.cc \
    textViewer.cc

HEADERS += \
    ../general/accelerateur.h \
    ../general/particle.h \
    ../general/elements.h \
    ../general/vecteur3D.h \
    ../general/faisceaux.h \
    ../general/constantes.h \
    textViewer.h \
    ../general/dessinable.h \
    ../general/supportadessin.h

