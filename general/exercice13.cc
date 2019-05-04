#include <iostream>
#include <math.h>
#include "faisceau.h"
#include "vecteur3D.h"
#include "constantes.h"

using namespace std;

void Faisceau::calcul_force_neighboor_P13(Particle* p, vector<Particle*> list){
    //Calcul des forces avec la première methode

    for(auto q:list){
        //Calcul force between p and q
        Vecteur3D distance = p->getPosition() - q->getPosition();
        Vecteur3D force_inter_particle =
                pow(p->getElectricCharge(), 2) /
                (4 * M_PI * constantes::void_permitivity *
                pow(distance.norme(),3) * pow(p->gamma_factor(), 2)) * distance;
        p->ajouteForceMagnetique(force_inter_particle);
        q->ajouteForceMagnetique(-force_inter_particle);
    }
}
