#ifndef PARTICLE_H
#define PARTICLE_H

#include "vecteur3D.h"
#include <iostream>

class Element;

class Particle
{
    private:

        Vecteur3D pos = Vecteur3D();
        double mass;
        double electric_charge;
        double momentum;
        Vecteur3D force = Vecteur3D();
        Vecteur3D speed = Vecteur3D();
        Element* element_inside;

    public:

        Vecteur3D getPosition() const;
        Vecteur3D getSpeed();
        double getMass();
        double getElectricCharge();
        Vecteur3D getForce();

        void set_element_inside(Element* e);
        Element* get_element_inside();

        //constructors
        Particle();
        //Destructor
        ~Particle();
        Particle(double, double);
        Particle(double, double, Vecteur3D, Vecteur3D);
        double energy();
        double gamma_factor();
        void move(double);
        void ajouteForceMagnetique(Vecteur3D, double);

};

ostream& operator<<(ostream&, Particle);
#endif // PARTICLE_H
