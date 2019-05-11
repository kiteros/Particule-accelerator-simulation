#ifndef Faisceau_H
#define Faisceau_H
#include "particle.h"
#include "dessinable.h"
#include <vector>

class Faisceau: public Dessinable
{
protected:
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
    double A11Z;
    double A22Z;
    double A12Z;
    void Update_somme_attributs();
public:
    Faisceau(int nombre_particules, int lambda, double charge, double mass,double vitesse, SupportADessin* support,Accelerateur* acc);
    virtual void bouger(double dt);
    void remove_particle(Particle *);
    vector<Particle*> getParticules() {return particules;}
    void calcul_force_neighboor(void*);
    virtual void dessine() override
    { support->dessine(*this); }
};


class Faisceau_P13: public Faisceau
{
public:
    Faisceau_P13(int nombre_particules, int lambda, double charge, double mass,double vitesse, SupportADessin* support,Accelerateur* acc);
    virtual void bouger(double dt) override;
    void calcul_force_neighbour_P13(Particle *, vector<Particle*>);//A part
};


class Faisceau_P14: public Faisceau
{
public:
    Faisceau_P14(int nombre_particules, int lambda, double charge, double mass,double vitesse, SupportADessin* support,Accelerateur* acc);
    virtual void bouger(double dt) override;
    void calcul_force_neighbour_p14(Particle* p);
};

#endif // Faisceau_H
