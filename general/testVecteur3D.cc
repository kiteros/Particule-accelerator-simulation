#include <iostream>
#include "vecteur3D.h"

using namespace std;

int main()
{

    // un vecteur en 3D :
    Vecteur3D vect1(1.0, 2.0, -0.1);
    
    // un autre vecteur en 3D
    Vecteur3D vect2(2.6, 3.5,  4.1);
    Vecteur3D vect4(4.3,-1,3.2);
    double b = 4.5;
    
    Vecteur3D vect3(vect1);  // copie de V1
    cout << "the real number b is : "<< b <<endl;
    cout << "Vecteur 1 : " << vect1 << endl;
    cout << "Vecteur 2 : " << vect2 << endl;
    cout << "Vecteur 3 : " << vect3 << endl;
    
    cout << "Le vecteur 1 est ";
    if (vect1 == vect2) {
        cout << "égal au";
    } else {
        cout << "différent du";
    }
    cout << " vecteur 2," << endl << "et est ";
    if (vect1 != vect3) {
        cout << "différent du";
    } else {
        cout << "égal au";
    }
    cout << " vecteur 3." << endl;

    
    
    cout << "Vecteur 1 cross vecteur 2 est : " << (vect1 ^ vect2) <<endl;
    cout << "vecteur 1 + vecteur 2 est : "<< (vect1 + vect2)<<endl;
    cout << "vecteur 1 - vecteur 2 est : "<< (vect1 - vect2)<<endl;
    cout << " - vecteur 2 est : " << (- vect2)<<endl;
    cout << "b * vecteur2 est : " << (b * vect2)<<endl;
    cout << "vecteur2 * b est : " << (b * vect2)<<endl;
    cout << "le vecteur unitaire de vecteur 1 est : " << ~(vect1) << endl;
    cout << "le produit scalaire de vecteur 1 et vecteur 2 est : "<< (vect1 * vect2)<<endl;
    cout << "le produit mixte de vecteur 1 ,vecteur 2 et vecteur 4 est : "<< prod_mixte(vect1, vect2,vect4)<<endl;

    return 0;

}
