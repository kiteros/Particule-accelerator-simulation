#include "elements.h"
#include "vecteur3D.h"
#include <math.h>
#include "constantes.h"

//First constructor
Element::Element(Vecteur3D in_pos, Vecteur3D out_pos, double rayon)
{
    this->in_pos = in_pos;
    this->out_pos = out_pos;
    this->rayon = rayon;

}

Element_courbe::Element_courbe(Vecteur3D in_pos,
                               Vecteur3D out_pos, double rayon,
                               double rayon_courbure):Element(in_pos, out_pos, rayon){
    this->rayon_courbure = rayon_courbure;
}

Dipole::Dipole(Vecteur3D in_pos, Vecteur3D out_pos, double rayon,
               double rayon_courbure,
               double champ_magnetique):Element_courbe(in_pos, out_pos, rayon, rayon_courbure){

    this->champ_magnetique = champ_magnetique;
}

Element_droit::Element_droit(Vecteur3D in_pos, Vecteur3D out_pos,
                             double rayon):Element(in_pos, out_pos, rayon)
{}








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
    return (big_X- 1/abs(k)*u).norme() > rayon;
}

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







//virtual functions affiche

void Element::affiche(ostream& f){
        f<<"in position: "<<in_pos<<endl
        <<"out position: "<<out_pos<<endl
        <<"rayon: "<<rayon<<endl;
        return;
}

void Element_droit::affiche(ostream & f){
    Element::affiche(f);
    return;
}

void Element_courbe::affiche(ostream & f){
    Element::affiche(f);
    f<<"rayon_courbure: "<<rayon_courbure;
    return;
}

void Dipole::affiche(ostream &f){
    Element_courbe::affiche(f);
    f<<"champ_magnetique: "<<champ_magnetique;
    return;
}

ostream& operator<<(ostream& os, Element& el){
    el.affiche(os);
    return os;
}

//surcharge << afficher l'element
ostream& operator<<(ostream& os, Element_droit& el)
{
    el.affiche(os);
    return os;
}

//surcharge << afficher l'element
ostream& operator<<(ostream& os, Element_courbe& el)
{
    el.affiche(os);
    return os;
}

//surcharge << afficher dipole
ostream& operator<<(ostream& os, Dipole& el)
{
    el.affiche(os);
    return os;
}
