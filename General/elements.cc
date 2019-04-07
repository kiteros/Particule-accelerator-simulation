#include "elements.h"
#include "vecteur3D.h"
#include "particle.h"
#include <math.h>
#include "constantes.h"
#include "supportadessin.h"
#include "dessinable.h"
#include <fstream>

//First constructor
Element::Element(Vecteur3D in_pos, Vecteur3D out_pos, double rayon,SupportADessin* support,Element* s):Dessinable (support)
{
    this->in_pos = in_pos;
    this->out_pos = out_pos;
    this->rayon = rayon;
    this->element_suivant = s;

}

Element_courbe::Element_courbe(Vecteur3D in_pos,
                               Vecteur3D out_pos, double rayon,
                               double rayon_courbure,SupportADessin* support,Element* s):Element(in_pos, out_pos, rayon,support,s){
    this->rayon_courbure = rayon_courbure;
}

Dipole::Dipole(Vecteur3D in_pos, Vecteur3D out_pos, double rayon,
               double rayon_courbure,
               double champ_magnetique,SupportADessin* support,Element* s):Element_courbe(in_pos, out_pos, rayon, rayon_courbure,support,s){

    this->champ_magnetique = champ_magnetique;
}

Element_droit::Element_droit(Vecteur3D in_pos, Vecteur3D out_pos,
                             double rayon,SupportADessin* support,Element* s):Element(in_pos, out_pos, rayon,support,s)
{}


Quadrupoles::Quadrupoles(Vecteur3D in_pos,
                         Vecteur3D out_pos,
                         double rayon, double intensite,
                         SupportADessin* support,
                         Element* e):Element_droit(in_pos, out_pos, rayon, support, e)
{
     this->intensite = intensite;
}

bool Element::particle_out(Particle const& p){
    //Check si la particule sort
    return prod_mixte(constantes::e3, p.getPosition(), this->out_pos) > 0;
}

bool Element_droit::touch_border(Particle const& p){
    //Check si la particule touche the bord
    Vecteur3D big_X = p.getPosition() - in_pos;
    Vecteur3D d = ~(out_pos - in_pos);

    return (big_X - (big_X * d) * d).norme() > rayon;
}



bool Element_courbe::touch_border(Particle const& p){
    double k = rayon_courbure;
    Vecteur3D Cc = 0.5*(in_pos + out_pos) + ((1/k) * sqrt(1-pow (k,2.0)*((out_pos-in_pos).norme2())/4))*(~(out_pos-in_pos)^constantes::e3);
    Vecteur3D big_X = p.getPosition() - Cc;
    Vecteur3D u = ~(big_X - big_X.get_z()*constantes::e3);
    return (big_X- (1/abs(k))*u).norme() > rayon;
}

Vecteur3D Element_courbe::convertir_depuis_Abscisse_curviligne(double s) {
    double k = rayon_courbure;
    Vecteur3D Cc = 0.5*(in_pos + out_pos) + ((1/k) * sqrt(1-pow (k,2.0)*((out_pos-in_pos).norme2())/4))*(~(out_pos-in_pos)^constantes::e3);
    double alpha = s/abs(1/k);
    Vecteur3D R = in_pos - Cc;
    double x = R.get_x()*cos(alpha) + R.get_y()*sin(alpha);
    double y = -R.get_x()*sin(alpha) + R.get_y()*cos(alpha);
    return Cc + Vecteur3D(x,y,0);
};

Vecteur3D Element_droit::convertir_depuis_Abscisse_curviligne(double s) {
    Vecteur3D u = ~(this->get_out()-this->get_in());
    return in_pos + s *u;
};

Vecteur3D Element::get_in(){
    return in_pos;
}

Vecteur3D Element::get_out(){
    return out_pos;
}

double Element::get_size(){
    return rayon;
}

double Element_courbe::get_courbure(){
    return rayon_courbure;
}

double Element_courbe::getLongeur(){
    double longeur = 0;
    double l = (this->get_out()-this->get_out()).norme();
    double r = abs(1/this->get_courbure());
    longeur = asin(l/(2*r))*2*r;
    return longeur;
}

double Element_droit::getLongeur(){
    double longeur = 0;
    longeur = (this->get_out()-this->get_out()).norme();
    return longeur;
}
//virtual functions affiche

void Element::affiche(ofstream& f) const{

    f <<"in position: "<<in_pos<<endl
    <<"out position: "<<out_pos<<endl
    <<"rayon: "<<rayon<<endl;

    return;

}

void Element_droit::affiche(ofstream & f) const{
    Element::affiche(f);
    return;
}

void Element_courbe::affiche(ofstream & f) const{
    Element::affiche(f);
    f<<"rayon_courbure: "<<rayon_courbure<<endl;
    return;
}

void Dipole::affiche(ofstream &f)const{
    Element_courbe::affiche(f);
    f<<"champ_magnetique: "<<champ_magnetique<<endl;
    return;
}

void Quadrupoles::affiche(ofstream &f) const{
    Element_droit::affiche(f);
    f<<"intensite: "<<intensite<<endl;
    return;
}

ostream& operator<<(ofstream& os, Element& el){
    el.affiche(os);
    return os;
}

//surcharge << afficher l'element
ostream& operator<<(ofstream& os, Element_droit& el)
{
    el.affiche(os);
    return os;
}

//surcharge << afficher l'element
ostream& operator<<(ofstream& os, Element_courbe& el)
{
    el.affiche(os);
    return os;
}

//surcharge << afficher dipole
ostream& operator<<(ofstream& os, Dipole& el)
{
    el.affiche(os);
    return os;
}
