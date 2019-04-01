#ifndef CONSTANTES_H
#define CONSTANTES_H
#include "vecteur3D.h"

class constantes
{
    private:
        constantes();
    public:
        static const double light_speed;
        static const Vecteur3D e3;
        static const Vecteur3D e1;
        static const Vecteur3D e2;
        static int current_index_element;
        static int current_index_particle;
        static double time_step = 0.5;

};

#endif // CONSTANTES_H
