#include "particle.h"
#include "elements.h"
#include "vecteur3D.h"
#include "accelerateur.h"
#include "textViewer.h"
#include "particle.h"
#include "constantes.h"
#include <iostream>
using namespace std;

int main(){

    //Test des fonctions dessinables
    //Ajouter tout a l'accélérateur

    cout << "welcome to l'accelerateur de Jules et Weishung" << endl;

    //But créer le support a dessin befor
    TextViewer textView = TextViewer(cout);

    Accelerateur LHC = Accelerateur(&textView, "LHC");

    Particle electron = Particle(0.2, 0.4, Vecteur3D(1,1,1), Vecteur3D(2,2,2));
    Particle proton = Particle(1, 0.7, Vecteur3D(0.3,1,1), Vecteur3D(2,2.3,2));

    Element_droit ligne = Element_droit(Vecteur3D(0,0,0), Vecteur3D(2,2,2), 10.0, &textView);
    Element_courbe courbe = Element_courbe(Vecteur3D(0,0,0), Vecteur3D(3,3,3), 10.0, 13.0, &textView);
    Dipole aimant = Dipole(Vecteur3D(0,0,0), Vecteur3D(3,3,3), 10.0, 13.0, 2.0, &textView);
    Quadrupoles quadr = Quadrupoles(Vecteur3D(0,0,0), Vecteur3D(3,3,3), 10.0, 13.0, &textView);

    LHC.add_element(&ligne);
    LHC.add_element(&courbe);
    LHC.add_element(&aimant);
    LHC.add_element(&quadr);

    LHC.add_particles(&electron);
    LHC.add_particles(&proton);

    LHC.start(cout);
    textView.dessine(LHC);

    return 0;
}
