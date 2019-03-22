#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H

#include "elements.h"
#include "particle.h"
#include <vector>
#include <iostream>
using namespace std;

class Accelerateur
{
    private:
        //On met un array dynamique pour tout les elements
        vector<Element*> elements;
        vector<Particle*> particules;

    public:
        vector<Element*> getElements() {return elements;}
        vector<Particle*> getPartcules() {return particules;}
        Accelerateur();
        Accelerateur(vector<Element*>, vector<Particle*>);
  
        //Accelerateur(Accelerateur const &) = delete ;
        Accelerateur operator=(Accelerateur const &) = delete;

        ~Accelerateur();


        void add_element(Element*);
        void remove_all_element();

        void add_particles(Particle*);
        void remove_all_particle();

        void evolue();

};

ostream& operator<<(ostream& os, Accelerateur a);
#endif // ACCELERATEUR_H
