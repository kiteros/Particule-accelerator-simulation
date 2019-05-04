#include "constantes.h"
#include "vecteur3D.h"

constantes::constantes(){}

const double constantes::light_speed = 299792458.0;
Vecteur3D constantes::e1 = Vecteur3D(1.0,0.0,0.0);
Vecteur3D constantes::e2 = Vecteur3D(0.0,1.0,0.0);
Vecteur3D constantes::e3 = Vecteur3D(0.0,0.0,1.0);
double constantes::time_step = 0.5;
double constantes::void_permitivity = 8.85e-12;
