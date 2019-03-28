#include "particle.h"
#include "elements.h"
#include "vecteur3D.h"
#include "textViewer.h"
#include <iostream>
using namespace std;

int main(){
    cout << "test d'éléments" << endl;
    TextViewer textV(cout);
    Element_droit ligne = Element_droit(
                Vecteur3D(0,0,0),
                Vecteur3D(10,10,10),
                10.2,&textV);

    Element_courbe elem = Element_courbe(
                Vecteur3D(0,0,0),
                Vecteur3D(10,10,10),
                10.2, 2,&textV);
    ligne.dessine();
    elem.dessine();
    //cout << "premier element : " << ligne << endl;
    //cout << "deuxieme element test: " << elem << endl;


    return 0;
}
