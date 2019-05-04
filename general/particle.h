#ifndef PARTICLE_H
#define PARTICLE_H

#include "vecteur3D.h"
#include <iostream>

class Accelerateur;

class Element;

class Particle
{
    private:

        Vecteur3D pos = Vecteur3D();
        Vecteur3D force = Vecteur3D();
        Vecteur3D speed = Vecteur3D();

        double mass;
        double electric_charge;
        double momentum;

        Element* element_inside;

    public:

        Particle();
        Particle(double, double);
        Particle(double mass, double charge, Vecteur3D speed, Vecteur3D position);
        ~Particle();

        void update_pos(Vecteur3D v){pos = v;}
        Vecteur3D getPosition() const;
        Vecteur3D getSpeed();
        double getMass();
        double getElectricCharge();
        Vecteur3D getForce();

        void set_element_inside(Element* e);
        Element* get_element_inside();

        //constructors

        //Destructor



        double energy();
        double gamma_factor();
        void move(double);
        void ajouteForceMagnetique(Vecteur3D, double);

        void ajouteForceMagnetique(Vecteur3D);

        double get_abscisse_curviligne(Accelerateur *);

};

ostream& operator<<(ostream&, Particle);
#endif // PARTICLE_H
