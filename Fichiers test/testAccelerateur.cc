#include "particle.h"
#include "elements.h"
#include "accelerateur.h"
#include "vecteur3D.h"
#include "textViewer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    cout << "test d'accelerateur" << endl;

    Dipole di = Dipole(Vecteur3D(1,2,3),
                       Vecteur3D(10,10,10),
                       10.2,
                       2,
                       7,nullptr);
    Element_droit ligne = Element_droit(
                Vecteur3D(3,4,5),
                Vecteur3D(10,10,10),
                10.2,nullptr);
    
    Particle p(1.2,3.4, Vecteur3D(1.0,1.0,1.0), Vecteur3D(3.0,2.0,1.0));
    Particle p2(1.0,6.4, Vecteur3D(1.0,5.0,1.0), Vecteur3D(3.0,3.0,1.0));
    Accelerateur acc = Accelerateur(nullptr);
    acc.add_element(&di);
    acc.add_element(&ligne);
    acc.add_particles(&p);
    acc.add_particles(&p2);

    cout << acc ;

    return 0;
}
