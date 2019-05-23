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

        Vecteur3D in_pos; //position d'entree
        Vecteur3D out_pos;//position de sortie
        double rayon; //rayon de Coupe transversale(qui est un circle) de element
        double rayon_courbure;
        Element* element_suivant;
        Couleur c; // couleur de cet element quand affiche

    public:

        Element(Vecteur3D, Vecteur3D, double,SupportADessin*,Element* = nullptr, double = 0.0);
        Vecteur3D get_in(); //retourne position d'entree
        Vecteur3D get_out(); //retourne position de sortir

        Element* get_element_suivant() {return element_suivant;}
        void set_element_suivant(Element* e) {element_suivant = e;}

        double get_rayon() {return rayon;}
        double get_courbure(){return rayon_courbure;}
        virtual double getLongeur() = 0; // retourne la longeur de element
        virtual Vecteur3D convertir_depuis_Abscisse_curviligne(double s) = 0; // donner un Abscisse_curviligne(un double) d'un point on retourne le vecteur position de ce point
        virtual bool particle_out(Particle const&); // etant donne une particule, dire si cette particule sort cet element
        virtual bool touch_border(Particle const&) = 0;// etant donne une particule, dire si cette particule touche le bord de cet element
        virtual void update_force(Particle* p,double dt) = 0; // màj les force subie par cette particule
        virtual double convertir_a_Abscisse_curviligne(Vecteur3D v) = 0;// etant donne un vecteur position d'un point, retourner l'Abscisse_curviligne de ce point
        virtual Vecteur3D get_vecteur_r(Vecteur3D position = Vecteur3D()) = 0; // retourner le vecteur unitaire r comme dans le complement mathematique

        Couleur get_c(){return c;} // return the color of this element

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
        Vecteur3D get_centre_circle();// get the circle center of this Element_courbe

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
