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

all:: testVecteur3D testParticle testElements testAccelerateur

constantes.o: constantes.cc constantes.h
Vecteur3D.o: vecteur3D.cc vecteur3D.h constantes.h
elements.o: elements.cc particle.h elements.h vecteur3D.h
particle.o: particle.cc vecteur3D.h particle.h constantes.h
testVecteur3D.o: testVecteur3D.cc vecteur3D.h
testParticle.o: testParticle.cc particle.h vecteur3D.h
testElements.o: testElements.cc elements.h vecteur3D.h
accelerateur.o: accelerateur.h accelerateur.cc elements.h particle.h constantes.h
testAccelerateur.o: testAccelerateur.cc particle.h elements.h accelerateur.h

testVecteur3D: testVecteur3D.o vecteur3D.o particle.o constantes.o
testParticle: vecteur3D.o particle.o testParticle.o constantes.o
testElements: testElements.o particle.o vecteur3D.o constantes.o elements.o
testAccelerateur: testAccelerateur.o particle.o elements.o constantes.o vecteur3D.o
