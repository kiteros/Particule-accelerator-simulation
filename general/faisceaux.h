#ifndef FAISCEAUX_H
#define FAISCEAUX_H
#include "particle.h"
#include "dessinable.h"
#include <vector>

class Faisceaux: public Dessinable
{
private:
    Particle* particule_typique;
    vector<Particle*> particlues;
    int nombre_particules;
    int lambda;
    double energie_moyenne;
    double emittance;
    double A11;
    double A22;
    double A12;

public:
    Faisceaux(int nombre_particules, int lambda, double charge, double mass,Vecteur3D vitesse, SupportADessin* support,Accelerateur* acc);
    void bouger();

};

#endif // FAISCEAUX_H
