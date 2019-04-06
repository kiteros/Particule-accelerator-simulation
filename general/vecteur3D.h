#ifndef VECTEUR3D_H
#define VECTEUR3D_H

#include <iostream>

using namespace std;

class Vecteur3D{
    private:
        double x,y,z;
    public:
        double get_x();
        double get_y();
        double get_z();
        Vecteur3D();
        Vecteur3D(double, double, double);
        void set(double, double, double);
        void affiche();
        bool compare(Vecteur3D);
        Vecteur3D addition(Vecteur3D) const;
        Vecteur3D operator+(Vecteur3D const&);
        Vecteur3D operator-(Vecteur3D const&);
        Vecteur3D operator-();
        Vecteur3D operator*(double);
        double operator*(Vecteur3D const&);
        Vecteur3D operator^(Vecteur3D const&);
        Vecteur3D operator~(void);
        Vecteur3D soustraction(Vecteur3D) const;
        Vecteur3D oppose() const;
        Vecteur3D mult(double) const;
        double prod_scal(Vecteur3D) const;
        Vecteur3D prod_vect(Vecteur3D) const;
        double norme();
        double norme2();
        Vecteur3D unitaire();
        bool operator==(Vecteur3D const &);
        Vecteur3D rotation(Vecteur3D,double);
};

Vecteur3D  operator* (double scal, Vecteur3D v);
ostream& operator<<(ostream& os, Vecteur3D v);
double prod_mixte(Vecteur3D, Vecteur3D, Vecteur3D);

#endif // VECTEUR3D_H
