#include "constantes.h"
#include "vecteur3D.h"
#include <iostream>
#include <fstream>

using namespace std;

constantes::constantes(){}

const double constantes::light_speed = 299792458.0;
Vecteur3D constantes::e1 = Vecteur3D(1.0,0.0,0.0);
Vecteur3D constantes::e2 = Vecteur3D(0.0,1.0,0.0);
Vecteur3D constantes::e3 = Vecteur3D(0.0,0.0,1.0);
double constantes::time_step = 1e-11;
double constantes::void_permitivity = 8.85e-12;
int constantes::turn_before_update = 1;
double constantes::time_division = 1e12;
double constantes::rayon = 0.1;

void constantes::load(){
    cout << "void_permitivity : " << void_permitivity << endl;
    cout << "turn_before_update : " << turn_before_update << endl;
    cout << "time_division : " << time_division << endl;
    cout << "light_speed : " << light_speed << endl;
    cout << "rayon : " << rayon << endl;
}
