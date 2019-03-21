#include <iostream>
#include "vecteur3D.h"
#include "particle.h"
using namespace std;

int main()
{

    cout << "welcome to l'accélérateur de particules de Jules et Weishung" << endl;

    Particle particle = Particle(0.23, 2.20);

    cout << particle << endl;
    return 0;

}
