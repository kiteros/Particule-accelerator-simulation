#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "vecteur3D.h"
#include <iostream>
#include <fstream>

/*
 * cette classe definit les constantes que on a utiliser dans le projet
*/

class constantes
{
    private:
        constantes();
    public:
        static const double light_speed;
        static Vecteur3D e3; // vecteur (0,0,1)
        static Vecteur3D e1; // vecteur (1,0,0)
        static Vecteur3D e2; // vecteur (0,1,0)
        static double time_step; // le temps entre deux bouge()
        static double void_permitivity;
        static int turn_before_update; //le nombre de frame a calculer en amont avant d'afficher l'accelerateur
        static double time_division; //le facteur de reduction du temps
        static double rayon;

        static void load(); //afficher les constantes

};

#endif // CONSTANTES_H
