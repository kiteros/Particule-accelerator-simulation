#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H
#include "dessinable.h"
#include "elements.h"
#include "particle.h"
#include "dessinable.h"
#include "faisceau.h"
#include <vector>
#include <iostream>

using namespace std;

class Accelerateur: public Dessinable
{
    private:

        //Dynamic arrays for all the objects inside
        vector<Element*> elements;
        vector<Particle*> particules;
        vector<Faisceau*> faisceaux;

        string name;

    public:

        vector<Faisceau*> getFaisceaux()const{return faisceaux;}
        vector<Element*> getElements()const {return elements;}
        vector<Particle*> getPartcules()const {return particules;}

        Accelerateur(SupportADessin*, string name="unnamed accelerator");
        Accelerateur(vector<Element*>, vector<Particle*>,SupportADessin*, string name="unnamed accelerator");

        //Accelerateur(Accelerateur const &) = delete ;
        Accelerateur operator=(Accelerateur const &) = delete;

        ~Accelerateur();

        void set_name(string name){this->name = name;}
        void add_elements(vector<Element*>);
        void add_faisceau(Faisceau*);
        void add_element(Element*);
        void remove_particle(Particle*);
        void remove_all_element();
        void add_particles(Particle*);
        void remove_all_particle();
        void evolue(double);
        void evolue_sans_faisceaux(std::ostream&, double dt);
        void start(ostream&);
        void start();
        double getLongeur();

        virtual void affiche(ostream&) const;
        virtual void dessine() override
        { support->dessine(*this); }

};

ostream& operator<<(ostream& os, Accelerateur const &a);
#endif // ACCELERATEUR_H
