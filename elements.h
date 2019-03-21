#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "particle.h"
#include "vecteur3D.h"
#include <iostream>

class Element
{
    protected:
        Vecteur3D in_pos;
        Vecteur3D out_pos;
        double rayon;

    public:
        Element(Vecteur3D, Vecteur3D, double);
        Vecteur3D get_in();
        Vecteur3D get_out();
        double get_size();

};

class Element_droit : public Element
{
    public:
        Element_droit(Vecteur3D, Vecteur3D, double);
        bool touch_border(Particle);

};


class Element_courbe : public Element
{
    protected:
        double rayon_courbure;
    public:
        Element_courbe(Vecteur3D, Vecteur3D, double, double);
        bool touch_border(Particle);
        double get_courbure();
};


ostream& operator<<(ostream&, Element_droit);
ostream& operator<<(ostream&, Element_courbe);

#endif // ELEMENTS_H
