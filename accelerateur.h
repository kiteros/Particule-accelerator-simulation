#ifndef ACCELERATEUR_H
#define ACCELERATEUR_H
#include "particle.h"
#include "elements.h"
#include <vector>

class Accelerateur
{
private:
    vector<Particle> particles;
    //vector<Elements> elements;
public:
    Accelerateur(){
        particles = vector<Particle>();
        //elements = vector<Elements>();
    }

};

#endif // ACCELERATEUR_H
