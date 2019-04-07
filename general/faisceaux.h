#ifndef FAISCEAUX_H
#define FAISCEAUX_H
#include "particle.h"
#include "dessinable.h"
#include <vector>

class Faisceaux: public Dessinable
{
private:
    Particle* particule_typique;
    vector<Particle*> particules;
    int nombre_particules;
    int lambda;
    double energie_moyenne;
    double emittance_r;
    double emittance_z;
    double A11R;
    double A22R;
    double A12R;

    double A11Z;
    double A22Z;
    double A12Z;
    void Update_somme_attributs();
public:
    Faisceaux(int nombre_particules, int lambda, double charge, double mass,Vecteur3D vitesse, SupportADessin* support,Accelerateur* acc);
    void bouger();
    void remove_particle(Particle *);

};

#endif // FAISCEAUX_H
