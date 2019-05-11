#include <iostream>
#include "vecteur3D.h"
#include <math.h>
#include <fstream>

using namespace std;

double Vecteur3D::get_x(){return x;}

double Vecteur3D::get_y(){return y;}

double Vecteur3D::get_z(){return z;}

Vecteur3D::Vecteur3D(){
    this->x=0;
    this->y=0;
    this->z=0;
}

//Cartesian constructor
Vecteur3D::Vecteur3D(double x, double y, double z){

    this->x=x;
    this->y=y;
    this->z=z;
}


void Vecteur3D::set(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
    return;
}

void Vecteur3D::affiche(){
  cout << x << " " << y << " " << z;
}

bool equalFloat(double a, double b){
    return fabs(a-b)<1E-32;
}

bool Vecteur3D::compare(Vecteur3D v){
    return (equalFloat(v.x,this->x) and equalFloat(v.y,this->y) and equalFloat(v.z,this->z));
}

//Meme classe en surcharge d'opérator (+ : addition)
Vecteur3D Vecteur3D::operator+(Vecteur3D const& v1){
    Vecteur3D v_n;
    v_n.set(this->x + v1.x, this->y + v1.y, this->z + v1.z);
    return v_n;
}

//Meme classe en surcharge d'opérator (- : soustraction)
Vecteur3D Vecteur3D::operator-(Vecteur3D const& v1){
    Vecteur3D v_n;
    v_n.set(this->x - v1.x, this->y - v1.y, this->z - v1.z);
    return v_n;
}

//Meme classe en surcharge d'opérator (- : inverse)
Vecteur3D Vecteur3D::operator-(){
    Vecteur3D v_n;
    v_n.set(-this->x, -this->y, -this->z);
    return v_n;
}

//Meme classe en surcharge d'opérator (* : multiplication)
Vecteur3D Vecteur3D::operator*(double scal){
    Vecteur3D v_n;
    v_n.set(scal * this->x, scal * this->y, scal * this->z);
    return v_n;
}

//Meme classe en surcharge d'opérator (* : multiplication) mais differente ordre
Vecteur3D  operator* (double scal, Vecteur3D v){
    Vecteur3D v_n;
    v_n.set(scal * v.get_x(), scal * v.get_y(), scal * v.get_z());
    return v_n;
}

//Meme classe en surcharge d'opérator (* : dot product)
double Vecteur3D::operator*(Vecteur3D const& v1){
    double dot_prod;
    dot_prod = this->x * v1.x + this->y * v1.y + this->z * v1.z;
    return dot_prod;
}

//Meme classe en surcharge d'opérator (^ : vector product)
Vecteur3D Vecteur3D::operator^(Vecteur3D const& v1){
    Vecteur3D v_n;
    v_n.set(this->y * v1.z - this->z * v1.y,
            this->z * v1.x - this->x * v1.z,
            this->x * v1.y - this->y * v1.x);
    return v_n;
}

double Vecteur3D::norme(){

    double norme;
    norme = sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
    return norme;

}

double Vecteur3D::norme2(){
    double norme2;
    norme2 = this->x*this->x + this->y*this->y + this->z*this->z;
    return norme2;
}

//Meme classe en surcharge d'opérator (~ : unitaire)
Vecteur3D Vecteur3D::operator~(){
    Vecteur3D v_u;
    double norme = this->norme();
    v_u.set(this->x/norme, this->y/norme, this->z/norme);
    return v_u;
}

double prod_mixte(Vecteur3D v1, Vecteur3D v2, Vecteur3D v3){
    double produit;
    produit = v1 * (v2 ^ v3);
    return produit;
}

//classe surcharge d'operator == egalite
bool Vecteur3D::operator==(Vecteur3D const& v){
    return (equalFloat(x,v.x) && equalFloat(y,v.y) && equalFloat(z,v.z));
}

//surcharge << afficher vecteur
ostream& operator<<(ostream& os, Vecteur3D v)
{
    os << v.get_x() << " " << v.get_y() << " " << v.get_z();
    return os;
}

//surcharge << afficher vecteur
ostream& operator<<(ofstream& os, Vecteur3D v)
{
    os << v.get_x() << " " << v.get_y() << " " << v.get_z();
    return os;
}

//creation methode rotation
Vecteur3D Vecteur3D::rotation(Vecteur3D a, double t){
    a = ~a;
    Vecteur3D x = *this;
    return  cos(t) * x + ( 1-cos(t) ) * (x*a) * a + sin(t) * (a ^ x);
}





