#include "elements.h"
#include "vecteur3D.h"

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

Element_droit::Element_droit(Vecteur3D in_pos, Vecteur3D out_pos,
                             double rayon):Element(in_pos, out_pos, rayon)
{}

//surcharge << afficher l'element
ostream& operator<<(ostream& os, Element_droit el)
{
    os << "debut : " << el.get_in()
       << " fin : " << el.get_out()
       << " size : " << el.get_size() << endl;
    return os;
}

//surcharge << afficher l'element
ostream& operator<<(ostream& os, Element_courbe el)
{
    os << "debut : " << el.get_in()
       << " fin : " << el.get_out()
       << " size : " << el.get_size()
       << "courbure : " << el.get_courbure() << endl;
    return os;
}

bool Element_droit::touch_border(Particle p){
    //Check si la particule touche the bord
    Vecteur3D big_X = p.getPosition() - in_pos;
    Vecteur3D d = ~(out_pos - in_pos);

    return (big_X - (big_X * d) * d).norme() > rayon;
}

bool Element_courbe::touch_border(Particle p){
    double k = rayon_courbure;
    Vecteur3D Cc = 0.5*(in_pos + out_pos) + (1/k * sqrt(1-pow (k,2.0)((out_pos-in_pos).norme2())/4))(~(out_pos-in_pos)^constantes::e3);
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
