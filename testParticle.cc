#include "particle.h"
#include <iostream>
using namespace std;

int main(){
    Particle p(1.2,3.4, Vecteur3D(1.0,1.0,1.0), Vecteur3D(3.0,2.0,1.0));
    cout << p;
    return 0;
}
