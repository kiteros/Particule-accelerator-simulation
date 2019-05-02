#ifndef Faisceau_H
#define Faisceau_H
#include "particle.h"
#include "dessinable.h"
#include <vector>

class Faisceau: public Dessinable
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
    Faisceau(int nombre_particules, int lambda, double charge, double mass,Vecteur3D vitesse, SupportADessin* support,Accelerateur* acc);
    void bouger();
    void remove_particle(Particle *);
    vector<Particle*> getParticules() {return particules;}
    virtual void dessine() override
    { support->dessine(*this); }
};

#endif // Faisceau_H
