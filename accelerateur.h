#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H

#include "elements.h"
#include "particle.h"
#include <vector>


class Accelerateur
{
    private:
        //On met un array dynamique pour tout les elements
        vector<Element> elements;
        vector<Particle> particules;

    public:

        Accelerateur();
        Accelerateur(vector<Element>, vector<Particle>);

        void add_element(Element);
        void remove_element(Element);

        void add_particles(Particle);
        void remove_particle(Particle);

};

#endif // ACCELERATEUR_H
