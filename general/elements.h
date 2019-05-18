#ifndef ELEMENTS_H
#define ELEMENTS_H
#include "particle.h"
#include "vecteur3D.h"
#include "dessinable.h"
#include <iostream>
#include "constantes.h"


struct Couleur{
    double R;
    double G;
    double B;
};


class Element : public Dessinable
{
    protected:

        Vecteur3D in_pos;
        Vecteur3D out_pos;
        double rayon;
        double rayon_courbure;
        Element* element_suivant;
        Couleur c;

    public:

        Element(Vecteur3D, Vecteur3D, double,SupportADessin*,Element* = nullptr, double = 0.0);
        Vecteur3D get_in();
        Vecteur3D get_out();

        Element* get_element_suivant() {return element_suivant;}
        void set_element_suivant(Element* e) {element_suivant = e;}

        int get_index();
        double get_rayon() {return rayon;}
        double get_courbure(){return rayon_courbure;}
        virtual double getLongeur() = 0;

        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) = 0;
        virtual bool particle_out(Particle const&);
        virtual bool touch_border(Particle const&) = 0;
        virtual void update_force(Particle* p,double dt) = 0;
        virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) = 0;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position = Vecteur3D()) = 0;

        Couleur get_c(){return c;}

        virtual void affiche(ostream&) const;
        virtual void dessine() override { support->dessine(this); }

};


class Element_droit : public Element
{
    public:

        Element_droit(Vecteur3D, Vecteur3D, double,SupportADessin*,Element* = nullptr);

        double getLongeur() override;

        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) override;
        virtual bool touch_border(Particle const& p) override;
        virtual void affiche(ostream&) const override;
        virtual void update_force(Particle* p,double dt) override;
        virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;

};


class Element_courbe : public Element
{
    public:

        Element_courbe(Vecteur3D, Vecteur3D, double, double,SupportADessin*,Element* e = nullptr);

        double getLongeur() override;
        double get_courbure();
        Vecteur3D get_centre_circle();

        virtual bool touch_border(Particle const&) override;
        virtual void affiche(ostream&) const override;
        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
        virtual void update_force(Particle* p,double dt) override;
        virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) override;

};


class Dipole : public Element_courbe
{
    protected:

        double champ_magnetique;

    public:
        Dipole(Vecteur3D, Vecteur3D, double, double, double,SupportADessin*,Element* e= nullptr);

        double get_champ_magnetique(){return champ_magnetique;}

        virtual void update_force(Particle* p ,double dt) override;
        virtual void affiche(ostream&) const override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
        virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) override;

};


class Quadrupoles: public Element_droit
{
    protected:

        double intensite;

    public:

        Quadrupoles(Vecteur3D, Vecteur3D, double, double, SupportADessin*, Element* e= nullptr);

        double get_intensite(){return intensite;}

        virtual void update_force(Particle* p ,double dt) override;
        virtual void affiche(ostream&) const override;
        virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
        virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) override;

};

class FODO: public Element{
private:
    double L ;//longeur des elements droits
    double l;//longeur des Quadrupoles
    double intensite;
    Element_droit* ED1;
    Element_droit* ED2;

    Quadrupoles* Q1;
    Quadrupoles* Q2;
public:
    FODO(Vecteur3D, Vecteur3D, double,SupportADessin*,double L , double intensite ,Element* = nullptr );
    virtual void update_force(Particle* p ,double dt) override;
    virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) override;
    double getLongeur() override;
    virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s);
    virtual bool touch_border(Particle const&) override;
    virtual Vecteur3D get_vecteur_r(Vecteur3D position) override;
};

ostream& operator<<(ostream&, Element&);
ostream& operator<<(ostream&, Element_droit&);
ostream& operator<<(ostream&, Element_courbe&);
ostream& operator<<(ostream&, Dipole&);
#endif // ELEMENTS_H
