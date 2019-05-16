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
    faisceau.h \
    ../Textview/textViewer.h

SOURCES += \
    vecteur3D.cc \
    particle.cc \
    constantes.cc \
    elements.cc \
    accelerateur.cc \
    #testParticle.cc \
    #testAccelerateur.cc \
    #testVecteur3D.cc \
    #testElements.cc \
    #ex10.cc \
    #ex9.cc \
    dessinable.cc \
    #testParticle.cc \
    supportadessin.cc \
    faisceau.cc \
    exercice13.cc

DISTFILES += \
    Makefile_old \
    params.txt
