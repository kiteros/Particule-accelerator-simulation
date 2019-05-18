#include "elements.h"
#include "vecteur3D.h"
#include "particle.h"
#include <math.h>
#include "constantes.h"
#include "supportadessin.h"
#include "dessinable.h"
#include <fstream>


Element::Element(Vecteur3D in_pos, Vecteur3D out_pos, double rayon, SupportADessin* support,Element* s, double rayon_courbure):Dessinable (support)
{

    this->in_pos = in_pos;
    this->out_pos = out_pos;
    this->rayon = rayon;
    this->element_suivant = s;
    this->rayon_courbure = rayon_courbure;

}

Element_courbe::Element_courbe(Vecteur3D in_pos,
                               Vecteur3D out_pos, double rayon,
                               double rayon_courbure,SupportADessin* support,Element* s):Element(in_pos, out_pos, rayon, support,s, rayon_courbure){

    Couleur c;
    c.R = 1.0;
    c.G = 0.5;
    c.B = 0.0;
    this->c = c;

}

Dipole::Dipole(Vecteur3D in_pos, Vecteur3D out_pos, double rayon,
               double rayon_courbure,
               double champ_magnetique,SupportADessin* support,Element* s):Element_courbe(in_pos, out_pos, rayon, rayon_courbure,support,s){

    this->champ_magnetique = champ_magnetique;
    Couleur c;
    c.R = 1.0;
    c.G = 1.0;
    c.B = 0.0;
    this->c = c;

}

Element_droit::Element_droit(Vecteur3D in_pos, Vecteur3D out_pos,
                             double rayon,SupportADessin* support,Element* s):Element(in_pos, out_pos, rayon,support,s)
{

    Couleur c;
    c.R = 1.0;
    c.G = 0.5;
    c.B = 0.5;
    this->c = c;

}

Quadrupoles::Quadrupoles(Vecteur3D in_pos,
                         Vecteur3D out_pos,
                         double rayon, double intensite,
                         SupportADessin* support,
                         Element* e):Element_droit(in_pos, out_pos, rayon, support, e)
{
    this->intensite = intensite;
    Couleur c;
    c.R = 0.0;
    c.G = 0.5;
    c.B = 1.0;
    this->c = c;

}

bool Element::particle_out(Particle const& p){
    //Check si la particule sort
    return (prod_mixte(constantes::e3, p.getPosition(), this->out_pos) > 0)||(prod_mixte(constantes::e3, p.getPosition(), this->in_pos) < 0);
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
    return (big_X- (1/fabs(k))*u).norme() > rayon;

}

Vecteur3D Element_courbe::convertir_depuis_Abscisse_curviligne(double s) {

    double k = rayon_courbure;
    Vecteur3D Cc = 0.5*(in_pos + out_pos) + ((1/k) * sqrt(1-pow (k,2.0)*((out_pos-in_pos).norme2())/4))*(~(out_pos-in_pos)^constantes::e3);
    double alpha = s/fabs(1/k);
    Vecteur3D R = in_pos - Cc;
    double x = R.get_x()*cos(alpha) + R.get_y()*sin(alpha);
    double y = -R.get_x()*sin(alpha) + R.get_y()*cos(alpha);
    return Cc + Vecteur3D(x,y,0);

}

Vecteur3D Element_droit::convertir_depuis_Abscisse_curviligne(double s) {

    Vecteur3D u = ~(this->get_out()-this->get_in());
    return in_pos + s *u;

}

Vecteur3D Element::get_in(){
    return in_pos;
}

Vecteur3D Element::get_out(){
    return out_pos;
}

double Element_courbe::get_courbure(){
    return rayon_courbure;
}

double Element_courbe::getLongeur(){
    double longeur = 0;
    double l = (this->get_in()-this->get_out()).norme();
    double r = fabs(1/this->get_courbure());
    longeur = asin(l/(2*r))*2*r;
    return longeur;
}

double Element_droit::getLongeur(){
    return (this->get_in()-this->get_out()).norme();
}


//virtual functions affiche

void Element::affiche(ostream& f) const{

    f <<"in position: "<<in_pos<<endl
    <<"out position: "<<out_pos<<endl
    <<"rayon: "<<rayon<<endl;

    return;

}

void Element_droit::affiche(ostream & f) const{
    Element::affiche(f);
    return;
}

void Element_courbe::affiche(ostream & f) const{
    Element::affiche(f);
    f<<"rayon_courbure: "<<rayon_courbure<<endl;
    return;
}

void Dipole::affiche(ostream &f)const{
    Element_courbe::affiche(f);
    f<<"champ_magnetique: "<<champ_magnetique<<endl;
    return;
}

void Quadrupoles::affiche(ostream &f) const{
    Element_droit::affiche(f);
    f<<"intensite: "<<intensite<<endl;
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


//UPDATE FORCE
void Dipole::update_force(Particle * p, double dt)  {
    Vecteur3D champ_magnetique = this->get_champ_magnetique() * constantes::e3;
    p->ajouteForceMagnetique(champ_magnetique, dt);
    return;
}

void Quadrupoles::update_force(Particle *p, double dt) {

    Vecteur3D d = ~(this->get_out() - this->get_in());
    Vecteur3D X = p->getPosition()-this->get_in();
    Vecteur3D y = X - (X*d)*d;
    Vecteur3D u = constantes::e3^d;
    Vecteur3D champ_magnetique = this->get_intensite()*((y*u)*constantes::e3+X.get_z()*u);
    std::cout<<"champ_magnetique Quadrupoles: "<<champ_magnetique<<endl;
    p->ajouteForceMagnetique(champ_magnetique, dt);
    return;

}

void Element_courbe::update_force(Particle *p, double dt) {
    return;
}

void Element_droit::update_force(Particle *p, double dt) {
    return;
}

//GET VECREUR r
Vecteur3D Element_droit::get_vecteur_r(Vecteur3D v){
    return constantes::e3 ^ ~(this->get_out()-this->get_in());
}

Vecteur3D Element_courbe::get_vecteur_r(Vecteur3D  position){
    double k = (this)->get_courbure();
    Vecteur3D Cc = 0.5*(this->get_in() + this->get_out()) + ((1/k) * sqrt(1-pow (k,2.0)*((this->get_out()-this->get_in()).norme2())/4))*(~(this->get_out()-this->get_in())^constantes::e3);
    Vecteur3D big_X = position - Cc;
    return  ~(big_X - big_X.get_z()*constantes::e3);
}

Vecteur3D Dipole::get_vecteur_r(Vecteur3D position){
   return Element_courbe::get_vecteur_r(position);
}

Vecteur3D Quadrupoles::get_vecteur_r(Vecteur3D position)
{
    return Element_droit::get_vecteur_r(position);
}

Vecteur3D Element_courbe::get_centre_circle(){
    double k = (this)->get_courbure();
    Vecteur3D Cc = 0.5*(this->get_in() + this->get_out()) + ((1/k) * sqrt(1-pow (k,2.0)*((this->get_out()-this->get_in()).norme2())/4))*(~(this->get_out()-this->get_in())^constantes::e3);
    return Cc;
}

double Element_droit::convertir_a_Abscisse_curviligne(Vecteur3D v){
    Vecteur3D u = ~(this->out_pos - this->in_pos);
    return (v-this->in_pos)*u;
}

double Element_courbe::convertir_a_Abscisse_curviligne(Vecteur3D v){

    Vecteur3D Cc = this->get_centre_circle();
    double R = 1/abs(this->get_courbure());
    Vecteur3D u = ~(this->in_pos - Cc);
    Vecteur3D x = ~(v - Cc);
    double angle = acos(u*x);
    return R*angle;

}

double Dipole::convertir_a_Abscisse_curviligne(Vecteur3D v){
    return  Element_courbe::convertir_a_Abscisse_curviligne(v);
}

double Quadrupoles::convertir_a_Abscisse_curviligne(Vecteur3D v){
    return Element_droit::convertir_a_Abscisse_curviligne(v);
}

FODO::FODO(Vecteur3D in_pos, Vecteur3D out_pos, double rayon,SupportADessin* support ,double L , double intensite ,Element* s )
:Element(in_pos, out_pos, rayon,support,s),L(L),intensite(intensite)
{
    double Longeur = (out_pos - in_pos).norme();
    Vecteur3D u = ~(out_pos - in_pos);
    l = Longeur/2 - L;
    Q1 = new Quadrupoles (in_pos,
                          in_pos + l*u,
                          rayon, intensite,
                          support,
                          s);
    ED1 = new Element_droit(in_pos + l*u,in_pos + l*u + L*u,rayon,support,s);
    Q2 =  new Quadrupoles(in_pos + l*u + L*u , in_pos + l*u + L*u + l*u,rayon,-intensite,support,s);
    ED2 = new Element_droit (in_pos + l*u + L*u + l*u,in_pos + l*u + L*u + l*u + L*u,rayon,support,s);
}

double FODO::convertir_a_Abscisse_curviligne(Vecteur3D v){
    Vecteur3D u = ~(this->out_pos - this->in_pos);
    return (v-this->in_pos)*u;
}

void FODO::update_force(Particle *p, double dt){
    double m = this->convertir_a_Abscisse_curviligne(p->getPosition());
    if(m>=0 && m<l) { Q1->update_force(p,dt);}
    else if (m>=l && m < l+L) {ED1->update_force(p,dt);}
    else if (m>= l+L && m<l+L+l) {Q2->update_force(p,dt);}
    else {ED2->update_force(p,dt);}
}

double FODO::getLongeur()
{
    return (this->get_in()-this->get_out()).norme();
}

Vecteur3D FODO::convertir_depuis_Abscisse_curviligne(double s){
    Vecteur3D u = ~(this->get_out()-this->get_in());
    return in_pos + s *u;
}

bool FODO::touch_border(const Particle & p){
    double m = this->convertir_a_Abscisse_curviligne(p.getPosition());
    if(m>=0 && m<l) { Q1->touch_border(p);}
    else if (m>=l && m < l+L) {ED1->touch_border(p);}
    else if (m>= l+L && m<l+L+l) {Q2->touch_border(p);}
    else {ED2->touch_border(p);}
}

Vecteur3D FODO::get_vecteur_r(Vecteur3D posotion){
    return constantes::e3 ^ ~(this->get_out()-this->get_in());
}
