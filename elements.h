#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "particle.h"
#include "vecteur3D.h"
#include "dessinable.h"
#include <iostream>



class Element : public Dessinable

{
    protected:
        Vecteur3D in_pos;
        Vecteur3D out_pos;
        double rayon;
        Element* element_suivant;

    public:
        Element(Vecteur3D, Vecteur3D, double,SupportADessin*,Element* = nullptr);
        Vecteur3D get_in();
        Vecteur3D get_out();
        double get_size();
        int get_index();
        virtual bool particle_out(Particle const&);
        virtual bool touch_border(Particle const&) = 0;
        virtual void affiche(ostream&) const;
        virtual string get_type() {return "element";}
        virtual void dessine() override
        { support->dessine(*this); }
};

class Element_droit : public Element
{
    public:
        Element_droit(Vecteur3D, Vecteur3D, double,SupportADessin*,Element* = nullptr);

        virtual bool touch_border(Particle const& p);
        virtual string get_type() override {return "element_droit";}
        virtual void affiche(ostream&) const;
};


class Element_courbe : public Element
{
    protected:
        double rayon_courbure;
    public:
        Element_courbe(Vecteur3D, Vecteur3D, double, double,SupportADessin*,Element* e = nullptr);

        virtual bool touch_border(Particle const&);
        virtual string get_type() override {return "element_courbe";}
        double get_courbure();
        virtual void affiche(ostream&) const;
};

class Dipole : public Element_courbe
{
    protected:
        double champ_magnetique;
    public:
        Dipole(Vecteur3D, Vecteur3D, double, double, double,SupportADessin*,Element* e= nullptr);
        double get_champ_magnetique(){return champ_magnetique;}
        virtual string get_type() override {return "dipole";}

        virtual void affiche(ostream&) const;
};


class Quadrupoles: public Element_droit
{   protected:
        double intensite;
    public:
        Quadrupoles(Vecteur3D, Vecteur3D, double, double, SupportADessin*, Element* e= nullptr);
        double get_intensite(){return intensite;}
        virtual string get_type() override {return "quadrupole";}
        virtual void affiche(ostream&) const;

};

ostream& operator<<(ostream&, Element&);
ostream& operator<<(ostream&, Element_droit&);
ostream& operator<<(ostream&, Element_courbe&);
ostream& operator<<(ostream&, Dipole&);
#endif // ELEMENTS_H
