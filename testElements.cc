#include "particle.h"
#include "elements.h"
#include "vecteur3D.h"
#include "textViewer.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream result_file;
    result_file.open("./Results/text_results.txt");

    result_file << "test d'éléments" << endl;
    TextViewer textV(result_file);
    result_file.close();
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
