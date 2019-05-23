#ifndef PARTICLE_H
#define PARTICLE_H

#include "vecteur3D.h"
#include <iostream>

class Accelerateur;

class Element;

class Particle
{
    private:

        Vecteur3D pos = Vecteur3D(); //positoin de particule
        Vecteur3D force = Vecteur3D(); //force subie par la particule
        Vecteur3D speed = Vecteur3D(); // la vitesse de la particule

        double mass;
        double electric_charge;

        Element* element_inside; // pour sauvegarder l'information dans quel element se trouve cette particule

    public:

        Particle();
        Particle(double mass, double charge);
        Particle(double mass = 0.938272, double charge = 1.60217653e-19, Vecteur3D speed = Vecteur3D(0,0,0), Vecteur3D position = Vecteur3D(0,0,0));
        ~Particle();

        double getMass();
        double getElectricCharge();
        double energy();
        double gamma_factor();
        double get_abscisse_curviligne(Accelerateur *); //obtenir l'abscisse_curviligne de cette particule. le point d'abscisse_curviligne 0 est le point entree de premier element(premier element dans l'attribut vector<Element*> elements) de l'accelerateur

        Vecteur3D getPosition() const;
        Vecteur3D getSpeed();
        Vecteur3D getForce();

        void update_pos(Vecteur3D v){pos = v;}
        void set_element_inside(Element* e);
        void move(double);
        void ajouteForceMagnetique(Vecteur3D, double);
        void ajouteForceMagnetique(Vecteur3D);

        Element* get_element_inside();

};

ostream& operator<<(ostream&, Particle);
#endif // PARTICLE_H
