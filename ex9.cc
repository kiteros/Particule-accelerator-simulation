#include "particle.h"
#include "elements.h"
#include "vecteur3D.h"
#include "dessinable.h"
#include <iostream>
using namespace std;

int main(){

    //Test des fonctions dessinables
    //Ajouter tout a l'accélérateur

    Accelerateur LHC = Accelerateur();

    Particle electron = Particle(0.2, 0.4, Vecteur3D(1,1,1), Vecteur3D(2,2,2));
    Particle proton = Particle(1, 0.7, Vecteur3D(0.3,1,1), Vecteur3D(2,2.3,2));

    Element_droit ligne = Element_droit(Vecteur3D(0,0,0), Vecteur3D(2,2,2), 10.0);
    Element_courbe courbe = Element_courbe(Vecteur3D(0,0,0), Vecteur3D(3,3,3), 10.0, 13.0);
    Dipole aimant = Dipole(Vecteur3D(0,0,0), Vecteur3D(3,3,3), 10.0, 13.0, 2.0);
    Quadrupoles quadr = Quadrupoles(Vecteur3D(0,0,0), Vecteur3D(3,3,3), 10.0, 13.0);

    LHC.add_element(ligne);
    LHC.add_element(courbe);
    LHC.add_element(aimant);
    LHC.add_element(quadr);

    LHC.add_particles(electron);
    LHC.add_particles(proton);

    return 0;
}
