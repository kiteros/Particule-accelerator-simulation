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
        vector<Element*> elements; //les elements que contient l'accelerateur
        vector<Particle*> particules; //les particules que contient l'accelerateur
        vector<Faisceau*> faisceaux; //les faisceaux que contient l'accelerateur

        string name; //le nom de l'accelerateur

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
        void evolue(double); // evolue avec les faisceaux, faire bouger les faisceaux

        //evolue sans faisceaux càd faire bouger les particules dans element.
        void evolue_sans_faisceaux(std::ostream&, double dt = constantes::time_step);

        //determiner chaque particule est dans quel element avant evolue_sans_faisceaux()
        void start(ostream&);
        void start();

        //retourner la longeur de l'accelerateur
        double getLongeur();
        double convertir_a_abscisse_curviligne_d_entre_dun_element(Element* e);

        virtual void affiche(ostream&) const;
        virtual void dessine() override
        { support->dessine(*this); }

};

ostream& operator<<(ostream& os, Accelerateur const &a);
#endif // ACCELERATEUR_H
