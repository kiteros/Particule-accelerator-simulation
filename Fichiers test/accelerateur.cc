#include "accelerateur.h"
#include "particle.h"
#include "elements.h"
#include "constantes.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

Accelerateur::Accelerateur(SupportADessin* support, string name):Dessinable (support)
{
    elements = vector<Element*>();
    particules = vector<Particle*>();
    this->name = name;
}

Accelerateur::~Accelerateur(){
    remove_all_element();
    remove_all_particle();
}

Accelerateur::Accelerateur(vector<Element*> el,
                           vector<Particle*> par,
                           SupportADessin* support,
                           string name):Dessinable (support){
    this->elements = el;
    this->particules = par;
    this->name = name;
}

void Accelerateur::add_elements(vector<Element*> els)
{
    for(auto ele:els){
        elements.push_back(ele);
    }
}

void Accelerateur::add_element(Element* el){
    this->elements.push_back(el);
}

void Accelerateur::remove_all_element(){
    elements.clear();
}

void Accelerateur::add_particles(Particle* p){
    this->particules.push_back(p);
}

void Accelerateur::remove_all_particle(){
    particules.clear();
}

void Accelerateur::remove_particle(Particle * p) {
    unsigned long size = particules.size();
    for (unsigned long i=0; i< size; i++) {
        if(particules[i] == p) {
            if(i == size - 1) {
                particules.pop_back();
            }
         }
         else{
            for (unsigned long j=i+1; j < size; j++) {
                 particules[j-1] = particules[j];
                 particules.pop_back();
            }
         }
    }
}

void Accelerateur::evolue(double dt){

    getFaisceaux().front()->bouger(dt);

}

void Accelerateur::evolue_sans_faisceaux(std::ostream& f, double dt){
    for(auto p:particules){
        Element* current_element = p->get_element_inside();
        current_element->update_force(p,dt);
        //Update la position des particules
        p->move(dt);

        while(current_element->particle_out(*p)){
            p->set_element_inside(current_element->get_element_suivant());
            current_element = p ->get_element_inside();
        }

        //Check si elles touchent le bord et les supprimer en concécences
        if(current_element->touch_border(*p)){
            remove_particle(p);
            continue;
        }
    }
    for (auto p:particules) {
        f << *p << endl;
    }
}

void Accelerateur::start(ostream & os){

    int number_elements = elements.size();
    int number_particles = particules.size();

    os << "Accelerator : " << name << endl;
    os << "--Number of elements : " << number_elements << endl;
    os << "--Number of particule : " << number_particles << endl;
    os << "L'accélérateur est constitué des éléments suivant :"<<endl;


     os << "Starting the accelerator " << name << " ..." << endl << endl;
     os << "*****************" << endl << endl;

    //Parcourir toutes les particules et déterminer dans quel element elle sont.
    //Si pas d'element, détruire la particule

    for(auto p:particules){
        int i = -1;
        for(auto el: elements){

            i++;
            //Si la particule touche pas le bord et est pas sortie
            if(!el->touch_border(*p) && ! el->particle_out(*p)){
                //p is in there
                p->set_element_inside(el);
            }else if(i == elements.size()){
                this->remove_particle(p);
            }
        }
    }
}

void Accelerateur::start(){

    for(auto p:particules){
        int i = -1;
        for(auto el: elements){

            i++;
            //Si la particule touche pas le bord et est pas sortie
            if(!el->touch_border(*p) && !el->particle_out(*p)){
                //p is in there
                p->set_element_inside(el);
            }else if(i == elements.size()){
                this->remove_particle(p);
            }

        }
    }

}

void Accelerateur::affiche(ostream & os) const{

    os << "L'accélérateur contient les particules suivantes :"<<endl;

    for(auto ele:particules){
        os<<"***********************"<<endl;
        os << *ele<<endl;
    }
    os << "L'accélérateur contient les elements suivantes :"<<endl;
    for(auto ele:elements){
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

double Accelerateur::getLongeur(){
    double longeur = 0;
    for(auto ele:elements){
        longeur = longeur + ele->getLongeur();
    }
    return longeur;
}

//Faisceau
void Accelerateur::add_faisceau(Faisceau * f){
    faisceaux.push_back(f);
}
