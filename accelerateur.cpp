#include "accelerateur.h"
#include "particle.h"
#include "elements.h"
#include <vector>

Accelerateur::Accelerateur()
{
    //Initialiser avec des vectors vides

}

Accelerateur::~Accelerateur(){
    remove_all_element();
    remove_all_particle();
}

Accelerateur::Accelerateur(vector<Element*> el, vector<Particle*> par){
    this->elements = el;
    this->particules = par;
}

void Accelerateur::add_element(Element* el){
    this->elements.push_back(el);
}

void Accelerateur::remove_all_element(){
    //Parcourir avec le element
    for(auto ele: elements){
        delete ele;
    }
    elements.clear();
}

void Accelerateur::add_particles(Particle* p){
    this->particules.push_back(p);
}

void Accelerateur::remove_all_particle(){
    //Parcourir avec le element
    for(auto p: particules){
        delete p;
    }
    particules.clear();
}

void Accelerateur::evolue(){

}
