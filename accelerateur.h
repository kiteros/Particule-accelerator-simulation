#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H
#include "dessinable.h"
#include "elements.h"
#include "particle.h"
#include "dessinable.h"
#include <vector>
#include <iostream>
using namespace std;

class Accelerateur: public Dessinable
{
    private:
        //On met un array dynamique pour tout les elements
        vector<Element*> elements;
        vector<Particle*> particules;

        string name;

    public:

        vector<Element*> getElements()const {return elements;}
        vector<Particle*> getPartcules()const {return particules;}

        Accelerateur(SupportADessin*, string name="unnamed accelerator");

        Accelerateur(vector<Element*>, vector<Particle*>,SupportADessin*, string name="unnamed accelerator");
  
        //Accelerateur(Accelerateur const &) = delete ;
        Accelerateur operator=(Accelerateur const &) = delete;

        ~Accelerateur();


        void add_element(Element*);
        void remove_all_element();

        void add_particles(Particle*);
        void remove_all_particle();

        void evolue();
        virtual void start(ostream&) const;
        virtual void affiche(ostream&) const;
        virtual void dessine() override
        { support->dessine(*this); }

};

ostream& operator<<(ostream& os, Accelerateur const &a);
#endif // ACCELERATEUR_H
