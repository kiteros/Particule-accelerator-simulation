#include "accelerateur.h"
#include "particle.h"
#include "elements.h"
#include "textViewer.h"
#include "constantes.h"
#include <vector>
#include <iostream>

/*Accelerateur::Accelerateur():Dessinable (nullptr)
{
    elements = vector<Element*>();
    particules = vector<Particle*>();
}*/

Accelerateur::Accelerateur(SupportADessin* support, string name):Dessinable (support)
{
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
            for (unsigned long j=i+1;j < size;j++) {
                 particules[j-1] = particules[j];
                 particules.pop_back();
            }
         }
    }
}

void Accelerateur::evolue(){
    //Okay donc on utilise l'algorithme avec sauvegarde...
    //On doit donc update toutes les particles (leurs forces)

    //Onc commence par parcourir toutes les particules
    for(auto p:particules){

        Element* this_element = p->get_element_inside();
        if(this_element->get_type() == "dipole"){

            Dipole* dip = this_element;
            Vecteur3D champ_magnetique = dip->get_champ_magnetique() * constantes::e3;
            p->ajouteForceMagnetique(champ_magnetique, constantes::time_step);

        }else if(this_element->get_type() == "quadrupole"){


            Quadrupoles* quad = this_element;
            Vecteur3D champ_magnetique = quad->get_intensite()*constantes::e3 +
               quad->get_intensite() * (constantes::e3 ^ ~(quad->get_out() - quad->get_in()));
            p->ajouteForceMagnetique(champ_magnetique, constantes::time_step);

        }


        //Update la position des particules
        p->move();

        //Check si elles touchent le bord et les supprimer en concécences
        if(this_element->touch_border(*p)){
            this->remove_particle(p);
        }

    }
}

void Accelerateur::start(ostream & os) const{

    int number_elements = elements.size();
    int number_particles = particules.size();
    os << "Accelerator : " << name << endl;
    os << "--Number of elements : " << number_elements << endl;
    os << "--Number of particule : " << number_particles << endl;
    os << "Starting the accelerator " << name << " ..." << endl << endl;
    os << "*****************" << endl << endl;

    //Extremely important :
    //Parcourir toutes les particules et déterminer dans quel element elle sont.
    //Si pas d'element, détruire la particule

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
