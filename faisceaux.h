#ifndef FAISCEAUX_H
#define FAISCEAUX_H
#include "particle.h"
#include "dessinable.h"

class Faisceaux: public Dessinable
{
private:
    Particle* particule_typique;
    int nombre_particules;
    double lambda;
    double energie_moyenne;
    double emittance;
    double A11;
    double A22;
    double A12;

public:
    Faisceaux();
    void bouger();

};

#endif // FAISCEAUX_H
