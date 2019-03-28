#include "accelerateur.h"
#include "particle.h"
#include "elements.h"
#include "textViewer.h"
#include <vector>
#include <iostream>

/*Accelerateur::Accelerateur():Dessinable (nullptr)
{
    elements = vector<Element*>();
    particules = vector<Particle*>();
}*/

Accelerateur::Accelerateur(SupportADessin* support):Dessinable (support) {}

Accelerateur::~Accelerateur(){
    remove_all_element();
    remove_all_particle();
}

Accelerateur::Accelerateur(vector<Element*> el, vector<Particle*> par,SupportADessin* support):Dessinable (support){
    this->elements = el;
    this->particules = par;
}

void Accelerateur::add_element(Element* el){
    this->elements.push_back(el);
}

void Accelerateur::remove_all_element(){
    //Parcourir avec le element
    /*for(auto ele: elements){
        delete ele;
    }*/
    elements.clear();
}

void Accelerateur::add_particles(Particle* p){
    this->particules.push_back(p);
}

void Accelerateur::remove_all_particle(){
    //Parcourir avec le element
    /*for(auto p: particules){
        delete p;
    }*/
    particules.clear();
}

void Accelerateur::evolue(){

}
void Accelerateur::affiche(ostream & os) const{
    os << "L'accélérateur est constitué des éléments suivant :"<<endl;
    for(auto ele:elements){
       os<<"***********************"<<endl;
       ele->dessine();
       //os << *(ele)<<endl;
    }
    os << "L'accélérateur contient les particules suivantes :"<<endl;
      for(auto ele:particules){
        os<<"***********************"<<endl;
        os << *ele<<endl;
      }
    return ;
}

std::ostream& operator<<(ostream& os, Accelerateur const & a)
{
    a.affiche(os);
    return os;
}
