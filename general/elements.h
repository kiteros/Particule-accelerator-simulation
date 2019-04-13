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
        Element* get_element_suivant() {return element_suivant;}
        void set_element_suivant(Element* e) {element_suivant = e;}
        virtual double getLongeur() = 0;
        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) = 0;
        virtual bool particle_out(Particle const&);
        virtual bool touch_border(Particle const&) = 0;
        virtual void affiche(ofstream&) const;
        virtual void dessine() override
        { support->dessine(*this); }
        virtual void update_force(Particle* p,double dt) = 0 ;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) = 0;
};

class Element_droit : public Element
{
    public:
        Element_droit(Vecteur3D, Vecteur3D, double,SupportADessin*,Element* = nullptr);

        virtual bool touch_border(Particle const& p) override;
        virtual void affiche(ofstream&) const override;
        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) override;
        double getLongeur() override;
        void update_force(Particle* p,double dt) override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
};


class Element_courbe : public Element
{
    protected:
        double rayon_courbure;
    public:
        Element_courbe(Vecteur3D, Vecteur3D, double, double,SupportADessin*,Element* e = nullptr);

        virtual bool touch_border(Particle const&) override;
        double getLongeur() override;
        double get_courbure();
        virtual void affiche(ofstream&) const override;
        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) override;
        void update_force(Particle* p ,double dt) override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;

};

class Dipole : public Element_courbe
{
    protected:
        double champ_magnetique;
    public:
        Dipole(Vecteur3D, Vecteur3D, double, double, double,SupportADessin*,Element* e= nullptr);
        double get_champ_magnetique(){return champ_magnetique;}
        void update_force(Particle* p ,double dt) override;
        virtual void affiche(ofstream&) const override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
};


class Quadrupoles: public Element_droit
{   protected:
        double intensite;
    public:
        Quadrupoles(Vecteur3D, Vecteur3D, double, double, SupportADessin*, Element* e= nullptr);
        double get_intensite(){return intensite;}
        void update_force(Particle* p ,double dt) override;
        virtual void affiche(ofstream&) const override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
};

ostream& operator<<(ostream&, Element&);
ostream& operator<<(ostream&, Element_droit&);
ostream& operator<<(ostream&, Element_courbe&);
ostream& operator<<(ostream&, Dipole&);
#endif // ELEMENTS_H
