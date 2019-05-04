#ifndef Faisceau_H
#define Faisceau_H
#include "particle.h"
#include "dessinable.h"
#include <vector>

class Faisceau: public Dessinable
{
private:
    Accelerateur* acc;
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
    int nombre_case_simulation;
    double A11Z;
    double A22Z;
    double A12Z;
    void Update_somme_attributs();
public:
    Faisceau(int nombre_particules, int lambda, double charge, double mass,double vitesse, SupportADessin* support,Accelerateur* acc);
    void bouger(double dt);
    void remove_particle(Particle *);
    vector<Particle*> getParticules() {return particules;}
    virtual void dessine() override
    { support->dessine(*this); }
    void calcul_force_neighbour_p14(Particle * p);
};

#endif // Faisceau_H
