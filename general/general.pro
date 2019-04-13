TEMPLATE = lib

CONFIG = staticlib c++11

HEADERS += \
    vecteur3D.h \
    particle.h \
    constantes.h \
    elements.h \
    accelerateur.h \
    dessinable.h \
    supportadessin.h \
    textViewer.h \
    faisceaux.h \
    ../Textview/textViewer.h

SOURCES += \
    vecteur3D.cc \
    particle.cc \
    constantes.cc \
    elements.cc \
    accelerateur.cc \
    #testAccelerateur.cc \
    #testVecteur3D.cc \
    #testElements.cc \
    #ex10.cc \
    #ex9.cc \
    dessinable.cc \
    testParticle.cc \
    supportadessin.cc \
    faisceaux.cc

DISTFILES += \
    Makefile_old