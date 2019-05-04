#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "vecteur3D.h"

class constantes
{
    private:
        constantes();
    public:
        static const double light_speed;
        static Vecteur3D e3;
        static Vecteur3D e1;
        static Vecteur3D e2;
        static int current_index_element;
        static int current_index_particle;
        static double time_step;
        static double void_permitivity;

};

#endif // CONSTANTES_H
