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
        int get_index();
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

class Dipole : public Element_courbe
{
    protected:
        double champ_magnetique;
    public:
        Dipole(Vecteur3D, Vecteur3D, double, double, double);
        double get_courbure(){return champ_magnetique;}
};

ostream& operator<<(ostream&, Element_droit);
ostream& operator<<(ostream&, Element_courbe);
ostream& operator<<(ostream&, Dipole);
#endif // ELEMENTS_H
