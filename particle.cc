#include "particle.h"
#include <iostream>
#include "vecteur3D.h"
#include <math.h>
#include "constantes.h"


Particle::Particle(){
    //Constructeur par défaut
    //mettre des valeurs de protons par exemple
}

Particle::~Particle(){

}

Particle::Particle(double mass, double charge){
    //Constructeur
    this->mass = mass;
    this->electric_charge = charge;
}

Particle::Particle(double mass, double charge, Vecteur3D speed, Vecteur3D position){
    //Constructeur
    this->mass = mass;
    this->electric_charge = charge;
    this->speed = speed;
    this->pos = position;
}

double Particle::energy(){
    return this->gamma_factor() * this->mass * pow(constantes::light_speed, 2);
}

double Particle::gamma_factor(){
    return 1 / sqrt(1 - pow(this->speed.norme() / constantes::light_speed, 2));
}

//On met la vitesse en attribut pour l'instant
/*double Particle::speed(){
    return this->momentum / sqrt(pow(this->mass, 2) + pow(this->momentum / light_speed, 2));
}*/

void Particle::move(double dt){
    Vecteur3D acceleration = (1/(this->gamma_factor() * this->mass)) * this->force;
    this->speed = this->speed + dt * acceleration;

    this->pos = this->pos + this->speed * dt;

    this->force = Vecteur3D(0,0,0);

}

//surcharge << afficher la particule
ostream& operator<<(ostream& os, Particle p)
{
    os << "position : " << p.getPosition() << "\n"
       << "speed : " << p.getSpeed() << "\n"
       << "gamma : " << p.gamma_factor() << "\n"
       << "energy (GeV) : " << p.energy() << "\n"
       << "mass (GeV/c²) : " << p.getMass() << "\n"
       << "charge : " << p.getElectricCharge() << "\n"
       << "force : " << p.getForce() << "\n";
    return os;
}

void Particle::ajouteForceMagnetique(Vecteur3D B, double dt){

    if(dt != 0){

        Vecteur3D current_speed;
        current_speed = this->speed;
        Vecteur3D F;
        F = this->electric_charge * (current_speed ^ B);
        this->force = this->force + B;

        //Rotation de force mtn

        Vecteur3D axeRotation = (current_speed ^F);
        double angle = asin((dt * F.norme())/(2 * this->gamma_factor() * this->mass * this->speed.norme()));

        this->force = this->force.rotation(axeRotation, angle);

    }
}

void Particle::set_element_inside(Element* el){
    this->element_inside = el;
}

Element* Particle::get_element_inside(){
    return element_inside;
}

Vecteur3D Particle::getPosition() const {
    return pos;
}

Vecteur3D Particle::getSpeed(){
    return speed;
}

double Particle::getMass(){
    return mass;
}

double Particle::getElectricCharge(){
    return electric_charge;
}

Vecteur3D Particle::getForce(){
    return force;
}
