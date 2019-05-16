CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11, ou autre suivant vos préférences

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
# CXXFLAGS += -pg                 # pour profiler
# LDFLAGS  += -pg                 # pour profiler
# CXXFLAGS += -O2                 # pour optimiser la vitesse

all: testVecteur3D testParticle testElements testAccelerateur ex9 ex10

supportadessin.o: supportadessin.cc
dessinable.o: dessinable.h dessinable.cc
constantes.o: constantes.cc constantes.h
vecteur3D.o: vecteur3D.cc vecteur3D.h constantes.h
elements.o: elements.cc particle.h elements.h vecteur3D.h dessinable.h supportadessin.h constantes.h
particle.o: particle.cc vecteur3D.h particle.h constantes.h
accelerateur.o: accelerateur.h accelerateur.cc elements.h particle.h constantes.h dessinable.h textViewer.h supportadessin.h
textViewer.o: elements.h accelerateur.h textViewer.h textViewer.cc elements.cc accelerateur.cc supportadessin.h dessinable.h
testVecteur3D.o: testVecteur3D.cc vecteur3D.h supportadessin.h dessinable.h
testParticle.o: testParticle.cc particle.h vecteur3D.h supportadessin.h dessinable.h
testElements.o: testElements.cc elements.h vecteur3D.h textViewer.h supportadessin.h dessinable.h
testAccelerateur.o: testAccelerateur.cc particle.h elements.h accelerateur.h vecteur3D.h textViewer.h supportadessin.h dessinable.h
ex9.o: ex9.cc particle.h elements.h vecteur3D.h accelerateur.h textViewer.h constantes.h supportadessin.h dessinable.h
ex10.o: ex10.cc particle.h elements.h vecteur3D.h accelerateur.h textViewer.h constantes.h supportadessin.h dessinable.h

testVecteur3D: testVecteur3D.o vecteur3D.o particle.o constantes.o
testParticle: vecteur3D.o particle.o testParticle.o constantes.o
testElements: testElements.o particle.o vecteur3D.o constantes.o elements.o dessinable.o textViewer.o supportadessin.o
testAccelerateur: testAccelerateur.o particle.o elements.o constantes.o vecteur3D.o accelerateur.o dessinable.o textViewer.o supportadessin.o
ex9: ex9.o particle.o elements.o vecteur3D.o accelerateur.o textViewer.o constantes.o supportadessin.o dessinable.o
ex10: ex10.o particle.o elements.o vecteur3D.o accelerateur.o textViewer.o constantes.o supportadessin.o dessinable.o
