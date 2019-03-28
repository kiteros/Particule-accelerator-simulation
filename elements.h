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
        Element* element_suivant;

    public:
        Element(Vecteur3D, Vecteur3D, double,Element* = nullptr);
        Vecteur3D get_in();
        Vecteur3D get_out();
        double get_size();
        int get_index();
        virtual bool touch_border(Particle const&) = 0;
        virtual void affiche(ostream&);
};

class Element_droit : public Element
{
    public:
        Element_droit(Vecteur3D, Vecteur3D, double,Element* = nullptr);
        virtual bool touch_border(Particle const& p);
        virtual void affiche(ostream&);
};


class Element_courbe : public Element
{
    protected:
        double rayon_courbure;
    public:
        Element_courbe(Vecteur3D, Vecteur3D, double, double,Element* e = nullptr);
        virtual bool touch_border(Particle const&);
        double get_courbure();
        virtual void affiche(ostream&);
};

class Dipole : public Element_courbe
{
    protected:
        double champ_magnetique;
    public:
        Dipole(Vecteur3D, Vecteur3D, double, double, double,Element* e= nullptr);
        double get_champ_magnetique(){return champ_magnetique;}
        virtual void affiche(ostream&);
};


class Quadrupoles: public Element_droit
{   protected:
    double intensite;

};

ostream& operator<<(ostream&, Element&);
ostream& operator<<(ostream&, Element_droit&);
ostream& operator<<(ostream&, Element_courbe&);
ostream& operator<<(ostream&, Dipole&);
#endif // ELEMENTS_H
