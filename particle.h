#ifndef PARTICLE_H
#define PARTICLE_H

#include "vecteur3D.h"
#include <iostream>

class Particle
{
    private:
        //On définit la position comme un vecteur 3D depuis l'origine
        Vecteur3D pos = Vecteur3D();

        //Masse en KG
        double mass;

        //electric charge in coulomb (1A.s)
        double electric_charge;

        //Speed direction

        double momentum;
        Vecteur3D force = Vecteur3D();
        Vecteur3D speed = Vecteur3D();

    public:
        Vecteur3D getPosition();
        Vecteur3D getSpeed();
        double getMass();
        double getElectricCharge();
        Vecteur3D getForce();

        //constructors
        Particle();
        Particle(double, double);
        Particle(double, double, Vecteur3D, Vecteur3D);
        double energy();
        double gamma_factor();
        //double speed();
        void move(double);
        void ajouteForceMagnetique(Vecteur3D, double);

};

ostream& operator<<(ostream&, Particle);
#endif // PARTICLE_H
