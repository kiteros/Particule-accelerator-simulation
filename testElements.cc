#include "particle.h"
#include "elements.h"
#include <iostream>
using namespace std;

int main(){
    cout << "test d'éléments" << endl;
    Element_droit ligne = Element_droit(
                Vecteur3D(0,0,0),
                Vecteur3D(10,10,10),
                10.2);

    Element_courbe elem = Element_courbe(
                Vecteur3D(0,0,0),
                Vecteur3D(10,10,10),
                10.2, 2);

    cout << "premier element : " << ligne << endl;
    cout << "deuxieme element test: " << elem << endl;


    return 0;
}
