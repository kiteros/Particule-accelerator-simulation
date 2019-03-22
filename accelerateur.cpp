#include "accelerateur.h"
#include "particle.h"
#include "elements.h"
#include <vector>

Accelerateur::Accelerateur()
{
    //Initialiser avec des vectors vides

}

Accelerateur::Accelerateur(vector<Element> el, vector<Particle> par){
    this->elements = el;
    this->particules = par;
}

Accelerateur::add_element(Element el){
    this->elements.push_back(el);
}

Accelerateur::remove_element(Element el){
    //Parcourir avec le element
    //for(int i = 0; i < this->elements.size())
}
