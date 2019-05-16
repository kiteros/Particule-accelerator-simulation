#include "particle.h"
#include "vecteur3D.h"
#include <iostream>
using namespace std;

int main(){


    Particle p1(0.938272,1.60217653e-19, Vecteur3D(-210200, -2.64754e+08, 0), Vecteur3D(3.00984, -0.391837, 0));
    cout << "particule 1 : \n" << p1 << endl;
    Particle p2(0.938272,1.60217653e-19, Vecteur3D(210200, -2.64754e+08, 0), Vecteur3D(2.99016, -0.391837, 0));
    cout << "particule 2 : \n" << p2 << endl;

    cout << "Ajout d'une force magnétique B=0 0 7 (dt=1e-11) a p1:" << endl << endl;

    p1.ajouteForceMagnetique(Vecteur3D(0,0,7), 1e-11);

    cout << "Ajout d'une force magnétique B=0 0 7 (dt=1e-11) a p2:" << endl << endl;

    p2.ajouteForceMagnetique(Vecteur3D(0,0,7), 1e-11);

    cout << "particules après avoir bougé : " << endl;

    cout << "particule 1 : \n" << p1 << endl;
    cout << "particule 2 : \n" << p2 << endl;


    return 0;
}
