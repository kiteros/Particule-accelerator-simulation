#include "particle.h"
#include "elements.h"
#include "vecteur3D.h"
#include "accelerateur.h"
#include "textViewer.h"
#include "particle.h"
#include "constantes.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){

    //Test des fonctions dessinables
    //Ajouter tout a l'accélérateur

    cout << "welcome to l'accelerateur de Jules et Weishung" << endl;

    //But créer le support a dessin befor
    TextViewer textView = TextViewer(cout);

    Accelerateur LHC = Accelerateur(&textView, "LHC");

    Particle electron = Particle(0.938272, 1.60217653e-19, Vecteur3D(0,-2.64754e+08,0), Vecteur3D(3.01,0,0));
    Particle proton = Particle(0.938272, 1.60217653e-19, Vecteur3D(0,-2.64754e+08,0), Vecteur3D(2.99,0,0));
    Quadrupoles Q1(Vecteur3D(3,2,0),Vecteur3D(3,1,0),0.1,1.2,&textView);
    Quadrupoles Q2(Vecteur3D(3,0,0),Vecteur3D(3,-1,0),0.1,-1.2,&textView);
    Quadrupoles Q3(Vecteur3D(2,-3,0),Vecteur3D(1,-3,0),0.1,1.2,&textView);
    Quadrupoles Q4(Vecteur3D(0,-3,0),Vecteur3D(-1,-3,0),0.1,-1.2,&textView);
    Quadrupoles Q5(Vecteur3D(-3,-2,0),Vecteur3D(-3,-1,0),0.1,1.2,&textView);
    Quadrupoles Q6(Vecteur3D(-3,0,0),Vecteur3D(-3,1,0),0.1,-1.2,&textView);
    Quadrupoles Q7(Vecteur3D(-2,3,0),Vecteur3D(-1,3,0),0.1,1.2,&textView);
    Quadrupoles Q8(Vecteur3D(0,3,0),Vecteur3D(1,3,0),0.1,-1.2,&textView);


    Element_droit E1(Vecteur3D(3,1,0),Vecteur3D(3,0,0),0.1,&textView);
    Element_droit E2(Vecteur3D(3,-1,0),Vecteur3D(3,-2,0),0.1,&textView);
    Element_droit E3(Vecteur3D(1,-3,0),Vecteur3D(0,-3,0),0.1,&textView);
    Element_droit E4(Vecteur3D(-1,-3,0),Vecteur3D(-2,-3,0),0.1,&textView);
    Element_droit E5(Vecteur3D(-3,-1,0),Vecteur3D(-3,0,0),0.1,&textView);
    Element_droit E6(Vecteur3D(-3,1,0),Vecteur3D(-3,2,0),0.1,&textView);
    Element_droit E7(Vecteur3D(-1,3,0),Vecteur3D(0,3,0),0.1,&textView);
    Element_droit E8(Vecteur3D(1,3,0),Vecteur3D(2,3,0),0.1,&textView);

    Dipole D1(Vecteur3D(3,-2,0),Vecteur3D(2,-3,0),0.1,1,5.89158,&textView);
    Dipole D2(Vecteur3D(-2,-3,0),Vecteur3D(3,-2,0),0.1,1,5.89158,&textView);
    Dipole D3(Vecteur3D(-3,2,0),Vecteur3D(-2,3,0),0.1,1,5.89158,&textView);
    Dipole D4(Vecteur3D(2,3,0),Vecteur3D(3,2,0),0.1,1,5.89158,&textView);

    Q1.set_element_suivant(&E1);
    E1.set_element_suivant(&Q2);
    Q2.set_element_suivant(&E2);
    E2.set_element_suivant(&D1);
    D1.set_element_suivant(&Q3);
    Q3.set_element_suivant(&E3);
    E3.set_element_suivant(&Q4);
    Q4.set_element_suivant(&E4);
    E4.set_element_suivant(&D2);
    D2.set_element_suivant(&Q5);
    Q5.set_element_suivant(&E5);
    E5.set_element_suivant(&Q6);
    Q6.set_element_suivant(&E6);
    E6.set_element_suivant(&D3);
    D3.set_element_suivant(&Q7);
    Q7.set_element_suivant(&E7);
    E7.set_element_suivant(&Q8);
    Q8.set_element_suivant(&E8);
    E8.set_element_suivant(&D4);
    D4.set_element_suivant(&Q1);

    vector<Element*> v{ &Q1,&Q2,&Q3,&Q4,&Q5,&Q6,&Q7,&Q8,&D1,&D2,&D3,&D4,&E1,&E2,&E3,&E4,&E5,&E6,&E7,&E8} ;
    LHC.add_elements(v);

    LHC.add_particles(&electron);
    LHC.add_particles(&proton);

    LHC.start(cout);
    LHC.dessine();
    LHC.evolue();
    LHC.dessine();


    return 0;
}
